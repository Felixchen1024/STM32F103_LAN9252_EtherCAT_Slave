/**
* \addtogroup pic32_mchp_gpio_sample_app pic32_mchp_gpio_sample_app
* @{
*/

/**
\file pic32_mchp_gpio_sample_appObjects
\author ET9300Utilities.ApplicationHandler (Version 1.3.6.0) | EthercatSSC@beckhoff.com

\brief pic32_mchp_gpio_sample_app specific objects<br>
\brief NOTE : This file will be overwritten if a new object dictionary is generated!<br>
*/

#if defined(_PIC32_MCHP_GPIO_SAMPLE_APP_) && (_PIC32_MCHP_GPIO_SAMPLE_APP_ == 1)
#define PROTO
#else
#define PROTO extern
#endif
/******************************************************************************
*                    Object 0x1601 : GPIO_OUTPUTS process data mapping
******************************************************************************/
/**
* \addtogroup 0x1601 0x1601 | GPIO_OUTPUTS process data mapping
* @{
* \brief Object 0x1601 (GPIO_OUTPUTS process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x7010.0<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1601[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x7010.0 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1601[] = "GPIO_OUTPUTS process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _PIC32_MCHP_GPIO_SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x7010.0 */
} OBJ_STRUCT_PACKED_END
TOBJ1601;
#endif //#ifndef _PIC32_MCHP_GPIO_SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1601 GPIO_OUTPUTSProcessDataMapping0x1601
#if defined(_PIC32_MCHP_GPIO_SAMPLE_APP_) && (_PIC32_MCHP_GPIO_SAMPLE_APP_ == 1)
={1,0x70100020}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A00 : GPIO_INPUTS process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A00 0x1A00 | GPIO_INPUTS process data mapping
* @{
* \brief Object 0x1A00 (GPIO_INPUTS process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6001.0<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A00[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x6001.0 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A00[] = "GPIO_INPUTS process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _PIC32_MCHP_GPIO_SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6001.0 */
} OBJ_STRUCT_PACKED_END
TOBJ1A00;
#endif //#ifndef _PIC32_MCHP_GPIO_SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A00 GPIO_INPUTSProcessDataMapping0x1A00
#if defined(_PIC32_MCHP_GPIO_SAMPLE_APP_) && (_PIC32_MCHP_GPIO_SAMPLE_APP_ == 1)
={1,0x60010020}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C12 : SyncManager 2 assignment
******************************************************************************/
/**
* \addtogroup 0x1C12 0x1C12 | SyncManager 2 assignment
* @{
* \brief Object 0x1C12 (SyncManager 2 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C12[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C12[] = "SyncManager 2 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _PIC32_MCHP_GPIO_SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C12;
#endif //#ifndef _PIC32_MCHP_GPIO_SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C12 sRxPDOassign
#if defined(_PIC32_MCHP_GPIO_SAMPLE_APP_) && (_PIC32_MCHP_GPIO_SAMPLE_APP_ == 1)
={1,{0x1601}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C13 : SyncManager 3 assignment
******************************************************************************/
/**
* \addtogroup 0x1C13 0x1C13 | SyncManager 3 assignment
* @{
* \brief Object 0x1C13 (SyncManager 3 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C13[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C13[] = "SyncManager 3 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _PIC32_MCHP_GPIO_SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C13;
#endif //#ifndef _PIC32_MCHP_GPIO_SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C13 sTxPDOassign
#if defined(_PIC32_MCHP_GPIO_SAMPLE_APP_) && (_PIC32_MCHP_GPIO_SAMPLE_APP_ == 1)
={1,{0x1A00}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6001 : GPIO_INPUTS
******************************************************************************/
/**
* \addtogroup 0x6001 0x6001 | GPIO_INPUTS
* @{
* \brief Object 0x6001 (GPIO_INPUTS) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x6001 = { DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_RXPDOMAPPING };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x6001[] = "GPIO_INPUTS\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT32 GPIO_INPUTS0x6001
#if defined(_PIC32_MCHP_GPIO_SAMPLE_APP_) && (_PIC32_MCHP_GPIO_SAMPLE_APP_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7010 : GPIO_OUTPUTS
******************************************************************************/
/**
* \addtogroup 0x7010 0x7010 | GPIO_OUTPUTS
* @{
* \brief Object 0x7010 (GPIO_OUTPUTS) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x7010 = { DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_TXPDOMAPPING };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x7010[] = "GPIO_OUTPUTS\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT32 GPIO_OUTPUTS0x7010
#if defined(_PIC32_MCHP_GPIO_SAMPLE_APP_) && (_PIC32_MCHP_GPIO_SAMPLE_APP_ == 1)
= 0x00
#endif
;
/** @}*/







#ifdef _OBJD_
TOBJECT    OBJMEM ApplicationObjDic[] = {
/* Object 0x1601 */
{NULL , NULL ,  0x1601 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1601 , aName0x1601 , &GPIO_OUTPUTSProcessDataMapping0x1601, NULL , NULL , 0x0000 },
/* Object 0x1A00 */
{NULL , NULL ,  0x1A00 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1A00 , aName0x1A00 , &GPIO_INPUTSProcessDataMapping0x1A00, NULL , NULL , 0x0000 },
/* Object 0x1C12 */
{NULL , NULL ,  0x1C12 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C12 , aName0x1C12 , &sRxPDOassign, NULL , NULL , 0x0000 },
/* Object 0x1C13 */
{NULL , NULL ,  0x1C13 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C13 , aName0x1C13 , &sTxPDOassign, NULL , NULL , 0x0000 },
/* Object 0x6001 */
{NULL , NULL ,  0x6001 , {DEFTYPE_UNSIGNED32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x6001 , aName0x6001 , &GPIO_INPUTS0x6001 , NULL , NULL , 0x0000 },
/* Object 0x7010 */
{NULL , NULL ,  0x7010 , {DEFTYPE_UNSIGNED32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x7010 , aName0x7010 , &GPIO_OUTPUTS0x7010 , NULL , NULL , 0x0000 },
{NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_
#undef PROTO

/** @}*/
#define _PIC32_MCHP_GPIO_SAMPLE_APP_OBJECTS_H_
