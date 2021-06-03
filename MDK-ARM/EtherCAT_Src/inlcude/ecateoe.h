/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
 * \addtogroup EoE Ethernet over EtherCAT
 * @{
 */

/**
\file ecateoe.h
\author EthercatSSC@beckhoff.com
\brief Sample header brief info

\version 5.12

<br>Changes to version V5.10:<br>
V5.12 EOE1: move icmp sample to the sampleappl,add EoE application interface functions<br>
V5.12 EOE4: handle 16bit only acceess, move ethernet protocol defines and structures to application header files<br>
<br>Changes to version V5.01:<br>
V5.10 EOE2: Add new EoE service identifier (6-9)<br>
V5.10 EOE3: Change local send frame pending indication variable to a global variable (it need to be resetted if the mailbox is stopped and a frame is pending)<br>
<br>Changes to version - :<br>
V5.01 : Start file change log
 */


/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include "mailbox.h"


#ifndef _ECATEOE_H_
#define _ECATEOE_H_

/*-----------------------------------------------------------------------------------------
------
------    Defines and Types
------
-----------------------------------------------------------------------------------------*/

#define    ETHERNET_MAX_FRAME_LEN         1514 /**< \brief Max Ethernet frame length*/
#define    ETHERNET_MAX_FRAMEBUF_LEN      1536 /**< \brief Max Ethernet frame buffer size*/

#define    ETHERNET_FRAGMENT_GRANULAR           32 /**< \brief length of each fragment (except the last fragment) must be dividable by 32*/
#define    ETHERNET_FRAGMENT_MASK               0xFFFFFFE0 /**< \brief EoE Fragment mask*/
#define    ETHERNET_FRAGMENT_BUFFER(n)          (((n)+31)/32) /**< \brief Fragment buffer*/
#define    ETHERNET_MAX_FRAGMENTS               48 /**< \brief Max number of fragments*/
#define    ETHERNET_MAX_FRAGMENTBUFFER          ((ETHERNET_MAX_FRAGMENTS)*(ETHERNET_FRAGMENT_GRANULAR)) /**< \brief Max fragment buffer (1536)*/

#define    ETHERNET_FRAMENO_MASK                0x0000000F /**< \brief Fragment number mask*/

#define    EOE_TYPE_FRAME_FRAG                  0 /**< \brief ETHERCAT_EOE_HEADER followed by frame fragment (ETHERCAT_EOE_TIMESTAMP may included)*/
#define    EOE_TYPE_TIMESTAMP_RES               1 /**< \brief ETHERCAT_EOE_HEADER followed by ETHERCAT_EOE_TIMESTAMP*/
#define    EOE_TYPE_INIT_REQ                    2 /**< \brief ETHERCAT_EOE_HEADER followed by ETHERCAT_EOE_INIT (Set IP Parameter Request)*/
#define    EOE_TYPE_INIT_RES                    3 /**< \brief ETHERCAT_EOE_HEADER (Set IP Parameter Response)*/
#define    EOE_TYPE_MACFILTER_REQ               4 /**< \brief ETHERCAT_EOE_HEADER followed by ETHERCAT_EOE_MACFILTER (Set MAC Filter Request)*/
#define    EOE_TYPE_MACFILTER_RES               5 /**< \brief ETHERCAT_EOE_HEADER (Set MAC Filter Response)*/
#define    EOE_TYPE_GET_IP_PARAM_REQ            6 /**< \brief Get IP Request*/
#define    EOE_TYPE_GET_IP_PARAM_RES            7 /**< \brief Get IP Response*/
#define    EOE_TYPE_GET_MAC_FILTER_REQ          8 /**< \brief Get MAC Filter Request*/
#define    EOE_TYPE_GET_MAC_FILTER_RES          9 /**< \brief Get MAC Filter Response*/

#define    EOE_RESULT_NOERROR                   0x0000 /**< \brief No Error*/
#define    EOE_RESULT_UNSPECIFIED_ERROR         0x0001 /**< \brief Unspecified error*/
#define    EOE_RESULT_UNSUPPORTED_TYPE          0x0002 /**< \brief unsupported type*/
#define    EOE_RESULT_NO_IP_SUPPORT             0x0201 /**< \brief No IP supported*/
#define    EOE_RESULT_NO_DHCP_SUPPORT           0x0202 /**< \brief No DHCP supported*/
#define    EOE_RESULT_NO_MACFILTERMASK_SUPPORT  0x0401 /**< \brief No mac filter supported*/



/** \brief MAC address*/
typedef struct MBX_STRUCT_PACKED_START
{
/*ECATCHANGE_START(V5.12) EOE4*/
    UINT16 w[3];
/*ECATCHANGE_END(V5.12) EOE4*/
}MBX_STRUCT_PACKED_END
ETHERNET_ADDRESS;


#define    ETHERNET_ADDRESS_LEN    SIZEOF(ETHERNET_ADDRESS) /**< \brief MAC address length*/


/**
 * \brief EoE Parameter header
 */
typedef struct MBX_STRUCT_PACKED_START
{
    UINT16                  Flags1; /**< \brief First 16Bit Flags*/
        #define    EOEINIT_CONTAINSMACADDR           0x0001 /**< \brief Includes MAC address*/
        #define    EOEINIT_CONTAINSIPADDR            0x0002 /**< \brief Includes IP address*/
        #define    EOEINIT_CONTAINSSUBNETMASK        0x0004 /**< \brief Includes SubNetMask*/
        #define    EOEINIT_CONTAINSDEFAULTGATEWAY    0x0008 /**< \brief Includes default gateway*/
        #define    EOEINIT_CONTAINSDNSSERVER         0x0010 /**< \brief Includes DNS server*/
        #define    EOEINIT_CONTAINSDNSNAME           0x0020 /**< \brief Includes DNS name*/
    UINT16                  Flags2; /**< \brief Second 16Bit Flags*/
        #define    EOEINIT_APPENDTIMESTAMP           0x0001 /**< \brief Includes time stamp*/
    ETHERNET_ADDRESS        MacAddr; /**< \brief MAC address buffer*/
/*ECATCHANGE_START(V5.12) EOE4*/
    UINT16                  IpAddr[2]; /**< \brief IP address buffer*/
    UINT16                  SubnetMask[2]; /**< \brief SubNetMask buffer*/
    UINT16                  DefaultGateway[2]; /**< \brief default gateway buffer*/
    UINT16                  DnsServer[2]; /**< \brief DNS server buffer*/
/*ECATCHANGE_END(V5.12) EOE4*/
    CHAR                    DnsName[32]; /**< \brief DNS name buffer*/
}MBX_STRUCT_PACKED_END
ETHERCAT_EOE_INIT;


#define    ETHERCAT_EOE_INIT_LEN    SIZEOF(ETHERCAT_EOE_INIT) /**< \brief EoE Parameter size*/


/**
 * \brief EoE Address filter request
 */
typedef struct MBX_STRUCT_PACKED_START
{
    UINT16                    Flags; /**< \brief 16Bit Flags*/
        #define    EOEMACFILTER_MACFILTERCOUNT              0x000F /**< \brief Number of MAC address filters*/
        #define    EOEMACFILTER_MACFILTERMASKCOUNT          0x0030 /**< \brief Number of MAC address masks*/
        #define    EOEMACFILTERSHIFT_MACFILTERMASKCOUNT     4 /**< \brief Number of MAC address masks shift*/
        #define    EOEMACFILTER_NOBROADCASTS                0x0080 /**< \brief Filter Broadcasts*/
    ETHERNET_ADDRESS        MacFilter[16]; /**< \brief MAC address buffer*/
    ETHERNET_ADDRESS        MacFilterMask[4]; /**< \brief MAC address masks buffer*/
}MBX_STRUCT_PACKED_END
ETHERCAT_EOE_MACFILTER;


#define    ETHERCAT_EOE_MACFILTER_LEN    SIZEOF(ETHERCAT_EOE_MACFILTER) /**< \brief EoE Address filter size*/


/**
 * \brief EoE Timestamp
 */
typedef struct MBX_STRUCT_PACKED_START
{
    UINT32                        TimeStamp;  /**< \brief 32 bit time stamp*/
}MBX_STRUCT_PACKED_END
ETHERCAT_EOE_TIMESTAMP;

#define    ETHERCAT_EOE_TIMESTAMP_LEN    SIZEOF(ETHERCAT_EOE_TIMESTAMP) /**< \brief EoE timestamp size*/

/**
 * \brief EoE header
 */
typedef struct MBX_STRUCT_PACKED_START
{
    UINT16                    Flags1; /**< \brief First 16Bit Flags*/
        #define    EOEHEADER_TYPE                     0x000F /**< \brief specifies following data*/
        #define    EOEHEADER_PORTASSIGN               0x00F0 /**< \brief 0 = unspecified, 1 = port 1...*/
        #define    EOEHEADER_LASTFRAGMENT             0x0100 /**< \brief TRUE if last fragment (EOE_TYPE_FRAME_FRAG only)*/
        #define    EOEHEADER_TIMESTAMPAPPENDED        0x0200 /**< \brief 32 bit time stamp appended  (EOE_TYPE_FRAME_FRAG with LastFragment=1 only)*/
        #define    EOEHEADER_TIMESTAMPREQUESTED       0x0400 /**< \brief time stamp response requested (EOE_TYPE_FRAME_FRAG only)*/

    UINT16                    Flags2; /**< \brief Second 16Bit Flags*/
        // EOE_TYPE_FRAME_FRAG and EOE_TYPE_TIMESTAMP_RES only
        #define    EOEHEADER_FRAGMENT                 0x003F /**< \brief fragment number (EOE_TYPE_FRAME_FRAG only)*/
        #define    EOEHEADER_OFFSETBUFFER             0x0FC0  /**< \brief byte offset multiplied by 32 (if Fragment != 0)  (EOE_TYPE_FRAME_FRAG only)
                                                              buffer size multiplied by 32 (if Fragment == 0) (EOE_TYPE_FRAME_FRAG only)*/
        #define    EOEHEADERSHIFT_OFFSETBUFFER        6
        #define    EOEHEADER_FRAMENO                  0xF000 /**< \brief frame number (EOE_TYPE_FRAME_FRAG and EOE_TYPE_TIMESTAMP_RES only)*/
        #define    EOEHEADER_RESULT                   0xFFFF /**< \brief EOE_TYPE_INIT_RES and EOE_TYPE_MACFILTER_RES only*/
}MBX_STRUCT_PACKED_END
ETHERCAT_EOE_HEADER;

#define    ETHERCAT_EOE_HEADER_LEN    SIZEOF(ETHERCAT_EOE_HEADER) /**< \brief EoE header size*/


#endif //_ECATEOE_H_

#if _ECATEOE_
    #define PROTO
#else
    #define PROTO extern
#endif

/*-----------------------------------------------------------------------------------------
------
------    Global Variables
------
-----------------------------------------------------------------------------------------*/

PROTO BOOL                bEoESendFramePending;             /**< \brief is set while an Ethernet frame is sent
                                                            with several fragments, the next Ethernet frame
                                                            could not be sent before the actual frame
                                                            is sent completely (EOE_SendFrameReq returns 1 in that case) */
/*ECATCHANGE_START(V5.12) EOE1*/
PROTO TMBX MBXMEM *       pEoeSendStored;                   /**< \brief if the mailbox service could not be sent (or stored),
                                                            the EoE service will be stored in this variable
                                                            and will be sent automatically from the mailbox handler
                                                            (EOE_ContinueInd) when the send mailbox will be read
                                                            the next time from the master */

PROTO MEM_ADDR MBXMEM *   pEthernetSendFrame;               /**< \brief stores the buffer of the Ethernet frame to be sent */

PROTO UINT16              u16EthernetSendSize;              /**< \brief stores the size of the actual Ethernet frame to be sent */

PROTO UINT8               u8SendFragmentNo;                 /**< \brief stores the fragment number of the next fragment to be sent */

PROTO UINT16              u16EthernetSendOffset;            /**< \brief stores the actual offset of the Ethernet frame, which
                                                            points to the next fragment to be sent */

PROTO UINT16              u16SendFrameNo;                   /**< \brief stores the frame number of the actual Ethernet frame to be sent */
/*ECATCHANGE_END(V5.12) EOE1*/
/*-----------------------------------------------------------------------------------------
------
------    Global Functions
------
-----------------------------------------------------------------------------------------*/

PROTO    void   EOE_Init(BOOL bPowerUp);
PROTO    UINT8  EOE_ServiceInd(TMBX MBXMEM * pMbx);
PROTO    void   EOE_ContinueInd(TMBX MBXMEM * pMbx);
PROTO    void   SendFragment(void);
#undef PROTO
/** @}*/
