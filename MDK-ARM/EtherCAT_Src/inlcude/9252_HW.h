#ifndef _9252_HW_H_
#define _9252_HW_H_

///////////////////////////////////////////////////////////////////////////////
// Includes

#include  "esc.h"

#include "stm32f1xx_hal.h"
///////////////////////////////////////////////////////////////////////////////
// Defines, types

#define ESC_RD                    0x02 /**< \brief Indicates a read access to ESC or EEPROM*/
#define ESC_WR                    0x04 /**< \brief Indicates a write access to ESC or EEPROM.*/

///////////////////////////////////////////////////////////////////////////////
//9252 HW DEFINES
#define ECAT_REG_BASE_ADDR              0x0300

#define CSR_DATA_REG_OFFSET             0x00
#define CSR_CMD_REG_OFFSET              0x04
#define PRAM_READ_ADDR_LEN_OFFSET       0x08
#define PRAM_READ_CMD_OFFSET            0x0c
#define PRAM_WRITE_ADDR_LEN_OFFSET      0x10
#define PRAM_WRITE_CMD_OFFSET           0x14

#define PRAM_SPACE_AVBL_COUNT_MASK      0x1f
#define IS_PRAM_SPACE_AVBL_MASK         0x01


#define CSR_DATA_REG                    ECAT_REG_BASE_ADDR+CSR_DATA_REG_OFFSET
#define CSR_CMD_REG                     ECAT_REG_BASE_ADDR+CSR_CMD_REG_OFFSET
#define PRAM_READ_ADDR_LEN_REG          ECAT_REG_BASE_ADDR+PRAM_READ_ADDR_LEN_OFFSET
#define PRAM_READ_CMD_REG               ECAT_REG_BASE_ADDR+PRAM_READ_CMD_OFFSET
#define PRAM_WRITE_ADDR_LEN_REG         ECAT_REG_BASE_ADDR+PRAM_WRITE_ADDR_LEN_OFFSET
#define PRAM_WRITE_CMD_REG              ECAT_REG_BASE_ADDR+PRAM_WRITE_CMD_OFFSET

#define PRAM_READ_FIFO_REG              0x04
#define PRAM_WRITE_FIFO_REG             0x20

#define HBI_INDEXED_DATA0_REG           0x04
#define HBI_INDEXED_DATA1_REG           0x0c
#define HBI_INDEXED_DATA2_REG           0x14

#define HBI_INDEXED_INDEX0_REG          0x00
#define HBI_INDEXED_INDEX1_REG          0x08
#define HBI_INDEXED_INDEX2_REG          0x10

#define HBI_INDEXED_PRAM_READ_WRITE_FIFO    0x18

#define PRAM_RW_ABORT_MASK      (1U << 30)
#define PRAM_RW_BUSY_32B        (1U << 31)
#define PRAM_RW_BUSY_8B         (1U << 7)
#define PRAM_SET_READ           (1U << 6)
#define PRAM_SET_WRITE          0


//#define 

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Hardware timer settings

#define ECAT_TIMER_INC_P_MS              2999 /**< \brief 312 ticks per ms*/


///////////////////////////////////////////////////////////////////////////////
// Interrupt and Timer Defines
//ESC_int -> scyn0

#ifndef DISABLE_ESC_INT
    #define    DISABLE_ESC_INT()           {1;}//HAL_NVIC_DisableIRQ(EXTI0_IRQn);} /**< \brief Disable interrupt source INT1*/
#endif
#ifndef ENABLE_ESC_INT
    #define    ENABLE_ESC_INT()          {1;}//HAL_NVIC_EnableIRQ(EXTI0_IRQn);} /**< \brief Enable interrupt source INT1  HAL_NVIC_EnableIRQ*/
#endif



#endif // end of #ifdef PIC32_HW


///////////////////////////////////////////////////////////////////////////////
// Interrupt and Timer defines

#define HW_EscReadWord(WordValue, Address) HW_EscRead(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief 16Bit ESC read access*/
#define HW_EscReadDWord(DWordValue, Address) HW_EscRead(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief 32Bit ESC read access*/
#define HW_EscReadByte(ByteValue, Address) HW_EscRead(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1) /**< \brief 8Bit ESC read access*/
#define HW_EscReadMbxMem(pData,Address,Len) HW_EscRead(((MEM_ADDR *)(pData)),((UINT16)(Address)),(Len)) /**< \brief The mailbox data is stored in the local uC memory therefore the default read function is used.*/

#define HW_EscReadWordIsr(WordValue, Address) HW_EscReadIsr(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief Interrupt specific 16Bit ESC read access*/
#define HW_EscReadDWordIsr(DWordValue, Address) HW_EscReadIsr(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief Interrupt specific 32Bit ESC read access*/
#define HW_EscReadByteIsr(ByteValue, Address) HW_EscReadIsr(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1) /**< \brief Interrupt specific 8Bit ESC read access*/


#define HW_EscWriteWord(WordValue, Address) HW_EscWrite(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief 16Bit ESC write access*/
#define HW_EscWriteDWord(DWordValue, Address) HW_EscWrite(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief 32Bit ESC write access*/
#define HW_EscWriteByte(ByteValue, Address) HW_EscWrite(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1) /**< \brief 8Bit ESC write access*/
#define HW_EscWriteMbxMem(pData,Address,Len) HW_EscWrite(((MEM_ADDR *)(pData)),((UINT16)(Address)),(Len)) /**< \brief The mailbox data is stored in the local uC memory therefore the default write function is used.*/

#define HW_EscWriteWordIsr(WordValue, Address) HW_EscWriteIsr(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief Interrupt specific 16Bit ESC write access*/
#define HW_EscWriteDWordIsr(DWordValue, Address) HW_EscWriteIsr(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief Interrupt specific 32Bit ESC write access*/
#define HW_EscWriteByteIsr(ByteValue, Address) HW_EscWriteIsr(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1) /**< \brief Interrupt specific 8Bit ESC write access*/


#if _9252_HW_
    #define PROTO
#else
    #define PROTO extern
#endif

	///////////////////////////////////////////////////////////////////////////////
	// Global variables extern

	///////////////////////////////////////////////////////////////////////////////
	// Global functions prototype

	PROTO UINT8 HW_Init(void);
	PROTO void HW_Release(void);
	PROTO UINT16 HW_GetALEventRegister(void);

	PROTO UINT16 HW_GetALEventRegister_Isr(void);

	PROTO void HW_ResetALEventMask(UINT16 intMask);
	PROTO void HW_SetALEventMask(UINT16 intMask);

	PROTO void HW_EscRead( MEM_ADDR * pData, UINT16 Address, UINT16 Len );
	PROTO void HW_EscReadIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len );

	PROTO void HW_EscWrite( MEM_ADDR *pData, UINT16 Address, UINT16 Len );

	PROTO void HW_EscWriteIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len );

	PROTO void HW_DisableSyncManChannel(UINT8 channel);
	PROTO void HW_EnableSyncManChannel(UINT8 channel);
	PROTO TSYNCMAN ESCMEM *HW_GetSyncMan(UINT8 channel);
    PROTO void HW_SetLed(UINT8 RunLed,UINT8 ErrLed);

	///////////////////////////////////////////////////////////////////////////////
	// ESC Access macros

	#if _9252_PIC32HW_
		// Place-holder
	#endif //#if _9252_PIC32HW_

#undef    PROTO

