/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
 * \addtogroup EoE Ethernet over EtherCAT
 * @{
 */

/**
\file eoeappl.h
\author EthercatSSC@beckhoff.com

\version 5.12

<br>Changes to version V5.11:<br>
V5.12 EOE1: move icmp sample to the sampleappl,add EoE application interface functions<br>
V5.12 EOE4: handle 16bit only acceess, move ethernet protocol defines and structures to application header files<br>
<br>Changes to version V5.10:<br>
V5.11 ECAT10: change PROTO handling to prevent compiler errors<br>
V5.11 EOE1: update mailbox length calculation on EoE response<br>
<br>Changes to version V5.01:<br>
V5.10 EOE5: Support "Get IP Parameter" (4Byte EoE requests also valid<br>
            Change setting of EoE response flag)<br>
<br>Changes to version - :<br>
V5.01 : Start file change log
 */

/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include "ecateoe.h"

#ifndef _EOEAPPL_H_
#define _EOEAPPL_H_

/*-----------------------------------------------------------------------------------------
------
------    Defines and Types
------
-----------------------------------------------------------------------------------------*/
/*ECATCHANGE_START(V5.12) EOE4*/
/*move protocol specific defines to application header files*/
/*ECATCHANGE_END(V5.12) EOE4*/


#endif //_EOEAPPL_H_

/*-----------------------------------------------------------------------------------------
------
------    Global Variables
------
-----------------------------------------------------------------------------------------*/

#if defined(_EOEAPPL_) && (_EOEAPPL_ == 1)
    #define PROTO
#else
    #define PROTO extern
#endif

/*ECATCHANGE_START(V5.12) EOE1*/
/*ECATCHANGE_START(V5.12) EOE4*/
PROTO UINT16 aIpAdd[2];
PROTO UINT16 aSubNetMask[2];
PROTO UINT16 aDefaultGateway[2];
PROTO UINT16 aDnsIp[2];
PROTO UINT16 aMacAdd[3];
/*ECATCHANGE_END(V5.12) EOE4*/
/*ECATCHANGE_END(V5.12) EOE1*/

/*-----------------------------------------------------------------------------------------
------
------    Global Functions
------
-----------------------------------------------------------------------------------------*/

PROTO    void EOEAPPL_ReceiveFrameInd(UINT8 MBXMEM * pFrame, UINT16 frameSize);
PROTO    UINT16 EOEAPPL_SettingsInd(ETHERCAT_EOE_INIT MBXMEM *pEoeInit);
UINT16 EOEAPPL_GetSettingsInd(ETHERCAT_EOE_INIT MBXMEM *pEoeInit,UINT16 *pMbxLength);

#undef PROTO
/** @}*/
