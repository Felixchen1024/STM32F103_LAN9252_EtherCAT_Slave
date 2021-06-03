/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
\addtogroup EoE Ethernet over EtherCAT
@{
*/

/**
\file eoeappl.c
\author EthercatSSC@beckhoff.com
\brief Implementation
This file contains an example how to use the EoE services

\version 5.12

<br>Changes to version V5.11:<br>
V5.12 ECAT2: big endian changes<br>
V5.12 EOE1: move icmp sample to the sampleappl,add EoE application interface functions<br>
V5.12 EOE4: handle 16bit only acceess, move ethernet protocol defines and structures to application header files<br>
V5.12 MBX2: do not set the pending indication in case of a EoE request, application triggered eoe datagram update<br>
<br>Changes to version V5.10:<br>
V5.11 ECAT10: change PROTO handling to prevent compiler errors<br>
V5.11 EOE1: update mailbox length calculation on EoE response<br>
<br>Changes to version V5.01:<br>
V5.10 EOE1: Prevent memeory leaks on incomplete EoE sequences<br>
V5.10 EOE5: Support "Get IP Parameter" (4Byte EoE requests also valid<br>
            Change setting of EoE response flag)<br>
<br>Changes to version V5.0:<br>
V5.01 EOE1: Return an error in case that DHCP handling is required.<br>
V5.01 EOE2: Add Ethernet frame buffer in case that static Ethernet buffer is used.<br>
<br>Changes to version V4.08:<br>
V5.0 EOE1: Support static Ethernet buffer.<br>
<br>Changes to version V4.06:<br>
V4.07 EOEAPPL 1: The memory define (for far or huge memory) was missing<br>
V4.07 EOEAPPL 2: The pointer pARP was not needed<br>
*/

/*---------------------------------------------------------------------------------------
------
------    Includes
------
---------------------------------------------------------------------------------------*/

#include "ecat_def.h"


#include "ecatslv.h"


#define    _EOEAPPL_    1
#include "eoeappl.h"
#undef      _EOEAPPL_

/*ECATCHANGE_START(V5.12) EOE1*/
#include "applInterface.h"
/*ECATCHANGE_END(V5.12) EOE1*/

/*remove definition of _EOEAPPL_ (#ifdef is used in eoeappl.h)*/
/*---------------------------------------------------------------------------------------
------
------    internal Types and Defines
------
---------------------------------------------------------------------------------------*/

#define    ECATEOE        0x4300
#define    ECATEOEMAX    0x02

/*---------------------------------------------------------------------------------------
------
------    static variables
------
---------------------------------------------------------------------------------------*/




/*---------------------------------------------------------------------------------------
------
------    static functions
------
---------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------------
------
------    functions
------
---------------------------------------------------------------------------------------*/


/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param     pFrame      Pointer to the received Ethernet frame (must be returned with
                            FREEMEM)
 \param     frameSize   Size of the received Ethernet frame

 \brief    This function is called when an Ethernet frame is received over EoE
*////////////////////////////////////////////////////////////////////////////////////////

void EOEAPPL_ReceiveFrameInd(UINT8 MBXMEM * pFrame, UINT16 frameSize)
{
/*ECATCHANGE_START(V5.12) EOE1*/
    if (pAPPL_EoeReceive != NULL)
    {
        /* call the application specific ethernet stack*/
        pAPPL_EoeReceive((UINT16 *)pFrame, frameSize);
    }
    /* the EOE sample is moved to the application files (enable SAMPLE_APPLICATION to get the ) */
/*ECATCHANGE_END(V5.12) EOE1*/
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param     pEoeInit   Pointer to store the IP settings
 \param     pMbxLength Pointer to length field in the mailbox header

 \return    0          Setting information were written

 \brief    This function is called when the IP get settings were received over EoE
*////////////////////////////////////////////////////////////////////////////////////////
UINT16 EOEAPPL_GetSettingsInd(ETHERCAT_EOE_INIT MBXMEM *pEoeInit,UINT16 *pMbxLength)
{
    /* Clear include Flags */
    pEoeInit->Flags1 = 0;
    pEoeInit->Flags2 = 0;

    /* set initial get IP parameter response length */
    *pMbxLength = 10;

     /* set MAC Address */
    MBXMEMCPY(&pEoeInit->MacAddr,aMacAdd, 6);
    pEoeInit->Flags1 |= EOEINIT_CONTAINSMACADDR;
    *pMbxLength += 6;

    // set IP Address
/*ECATCHANGE_START(V5.12) EOE4*/
    pEoeInit->IpAddr[0] = ((aIpAdd[1] & 0xFF) << 8) | ((aIpAdd[1] & 0xFF00) >> 8);
    pEoeInit->IpAddr[1] = ((aIpAdd[0] & 0xFF) << 8) | ((aIpAdd[0] & 0xFF00) >> 8);
/*ECATCHANGE_END(V5.12) EOE4*/

    pEoeInit->Flags1 |= EOEINIT_CONTAINSIPADDR;
    *pMbxLength += 4;

    pEoeInit->Flags1 = SWAPWORD(pEoeInit->Flags1);
    
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param     pEoeInit   Pointer to the received ip settings

 \return               0 (IP settings were correct), != 0 (IP settings were not correct)

 \brief    This function is called when the IP settings were received over EoE
*////////////////////////////////////////////////////////////////////////////////////////
UINT16 EOEAPPL_SettingsInd(ETHERCAT_EOE_INIT MBXMEM *pEoeInit)
{
    UINT16 result = 0;
/*ECATCHANGE_START(V5.12) ECAT2*/
    UINT16 u16eoeFlag = SWAPWORD(pEoeInit->Flags1);

    if (u16eoeFlag & EOEINIT_CONTAINSMACADDR )
    {
        // set MAC Address
        MBXMEMCPY(aMacAdd, &pEoeInit->MacAddr, 6);
    }
    else
    {
        HMEMSET(aMacAdd, 0x00, SIZEOF(aMacAdd));
    }

    if(u16eoeFlag & EOEINIT_CONTAINSIPADDR)
    {
        // set IP Address
/*ECATCHANGE_START(V5.12) EOE4*/
        aIpAdd[0] = ((pEoeInit->IpAddr[1] & 0xFF) << 8) | ((pEoeInit->IpAddr[1] & 0xFF00) >> 8);
        aIpAdd[1] = ((pEoeInit->IpAddr[0] & 0xFF) << 8) | ((pEoeInit->IpAddr[0] & 0xFF00) >> 8);
/*ECATCHANGE_END(V5.12) EOE4*/
    }
    else
    {
        HMEMSET(aIpAdd, 0x00, SIZEOF(aIpAdd));
    }

    if (u16eoeFlag & EOEINIT_CONTAINSSUBNETMASK)
    {
        // set Subnet mask
/*ECATCHANGE_START(V5.12) EOE4*/
        aSubNetMask[0] = ((pEoeInit->SubnetMask[1] & 0xFF) << 8) | ((pEoeInit->SubnetMask[1] & 0xFF00) >> 8);
        aSubNetMask[1] = ((pEoeInit->SubnetMask[0] & 0xFF) << 8) | ((pEoeInit->SubnetMask[0] & 0xFF00) >> 8);
/*ECATCHANGE_END(V5.12) EOE4*/
    }
    else
    {
        HMEMSET(aSubNetMask, 0x00, SIZEOF(aSubNetMask));
    }

    if (u16eoeFlag & EOEINIT_CONTAINSDEFAULTGATEWAY)
    {
        // set default gateway
        // set IP Address
/*ECATCHANGE_START(V5.12) EOE4*/
        aDefaultGateway[0] = ((pEoeInit->DefaultGateway[1] & 0xFF) << 8) | ((pEoeInit->DefaultGateway[1] & 0xFF00) >> 8);
        aDefaultGateway[1] = ((pEoeInit->DefaultGateway[0] & 0xFF) << 8) | ((pEoeInit->DefaultGateway[0] & 0xFF00) >> 8);
/*ECATCHANGE_END(V5.12) EOE4*/
    }
    else
    {
        HMEMSET(aDefaultGateway, 0x00, SIZEOF(aDefaultGateway));
    }

    if (u16eoeFlag & EOEINIT_CONTAINSDNSSERVER)
    {
            // set DNS ip
            // set IP Address
/*ECATCHANGE_START(V5.12) EOE4*/
        aDnsIp[0] = ((pEoeInit->DnsServer[1] & 0xFF) << 8) | ((pEoeInit->DnsServer[1] & 0xFF00) >> 8);
        aDnsIp[1] = ((pEoeInit->DnsServer[0] & 0xFF) << 8) | ((pEoeInit->DnsServer[0] & 0xFF00) >> 8);
/*ECATCHANGE_END(V5.12) EOE4*/
    }
    else
    {
        HMEMSET(aDnsIp, 0x00, SIZEOF(aDnsIp));
    }

    /*ECATCHANGE_START(V5.12) EOE1*/
    if (pAPPL_EoeSettingInd != NULL)
    {
        /* call the application specific ethernet stack*/
        pAPPL_EoeSettingInd((UINT16 *)aMacAdd, (UINT16 *)aIpAdd, (UINT16 *)aSubNetMask, (UINT16 *)aDefaultGateway, (UINT16 *)aDnsIp);
    }
    /* the EOE sample is moved to the application files (enable SAMPLE_APPLICATION to get the ) */
    /*ECATCHANGE_END(V5.12) EOE1*/

/*ECATCHANGE_END(V5.12) ECAT2*/
    return result;
}

/*ECATCHANGE_START(V5.12) EOE1*/
/////////////////////////////////////////////////////////////////////////////////////////
/**
\return   0 = sending of frame started, 1 = frame could not be sent, try it later

\param    pData    pointer to the Ethernet frame to be send (in case that STATIC_ETHERNET_BUFFER is 0 the memory will be freed after the last fragment was send)
\param    length   length of the Ethernet frame

\brief    Application interface function.
\brief    This function sends an Ethernet frame via EoE to the master
*////////////////////////////////////////////////////////////////////////////////////////
UINT16 EOE_SendFrameRequest(UINT16 *pData, UINT16 length)
{
    
    if (((!bEoESendFramePending && (nAlStatus != STATE_INIT))
        && (pEoeSendStored == NULL || pData == (UINT16 MBXMEM *)pEoeSendStored))
        )
    {
            /* no Ethernet is sent yet, no datagram is currently stored and the slave is at least in PRE-OP,
            so we could sent the requested frame */

        /* Ethernet frame is to be sent */
        bEoESendFramePending = TRUE;
        /* store the size of the Ethernet frame to be sent */
        u16EthernetSendSize = length;
        /* store the buffer of the Ethernet frame to be sent */
        pEthernetSendFrame = (MEM_ADDR MBXMEM *)pData;
        /* we start with the first fragment */
        u16EthernetSendOffset = 0;
        u8SendFragmentNo = 0;

        SendFragment();
    }
    else
    {
        /* frame could not be sent, try it later */
        return 1;
    }

    return 0;
}
/*ECATCHANGE_END(V5.12) EOE1*/

/** @} */




