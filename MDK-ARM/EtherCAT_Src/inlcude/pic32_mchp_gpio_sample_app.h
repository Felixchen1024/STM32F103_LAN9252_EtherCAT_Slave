/**
 * \addtogroup pic32_mchp_gpio_sample_app pic32_mchp_gpio_sample_app
 * @{
 */

/**
\file pic32_mchp_gpio_sample_app.h
\brief pic32_mchp_gpio_sample_app function prototypes and defines

\version 1.0.0.11
 */

 
 #ifndef _PIC32_MCHP_GPIO_SAMPLE_APP_H_
#define _PIC32_MCHP_GPIO_SAMPLE_APP_H_


/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include "ecat_def.h"

#include "ecatappl.h"

/*-----------------------------------------------------------------------------------------
------
------    Defines and Types
------
-----------------------------------------------------------------------------------------*/

#endif //_PIC32_MCHP_GPIO_SAMPLE_APP_H_

//include custom application object dictionary 
#include "pic32_mchp_gpio_sample_appObjects.h"


#if defined(_PIC32_MCHP_GPIO_SAMPLE_APP_) && (_PIC32_MCHP_GPIO_SAMPLE_APP_ == 1)
    #define PROTO
#else
    #define PROTO extern
#endif


PROTO void APPL_Application(void);
#if EXPLICIT_DEVICE_ID
PROTO UINT16 APPL_GetDeviceID(void);
#endif

PROTO void   APPL_AckErrorInd(UINT16 stateTrans);
PROTO UINT16 APPL_StartMailboxHandler(void);
PROTO UINT16 APPL_StopMailboxHandler(void);
PROTO UINT16 APPL_StartInputHandler(UINT16 *pIntMask);
PROTO UINT16 APPL_StopInputHandler(void);
PROTO UINT16 APPL_StartOutputHandler(void);
PROTO UINT16 APPL_StopOutputHandler(void);

PROTO UINT16 APPL_GenerateMapping(UINT16 *pInputSize,UINT16 *pOutputSize);
PROTO void APPL_InputMapping(UINT16* pData);
PROTO void APPL_OutputMapping(UINT16* pData);

#undef PROTO
/** @}*/

