#ifndef SPIDRIVER_H
#define	SPIDRIVER_H
#include "ecat_def.h"
#include "stm32f1xx_hal.h"
#include "main.h"
#ifdef	__cplusplus
extern "C" {
#endif
	// *****************************************************************************
	// *****************************************************************************
	// Section: File Scope or Global Data Types
	// *****************************************************************************
	// *****************************************************************************
	#define CMD_SERIAL_READ 0x03
	#define CMD_FAST_READ 0x0B
	#define CMD_DUAL_OP_READ 0x3B
	#define CMD_DUAL_IO_READ 0xBB
	#define CMD_QUAD_OP_READ 0x6B
	#define CMD_QUAD_IO_READ 0xEB
	#define CMD_SERIAL_WRITE 0x02
	#define CMD_DUAL_DATA_WRITE 0x32
	#define CMD_DUAL_ADDR_DATA_WRITE 0xB2
	#define CMD_QUAD_DATA_WRITE 0x62
	#define CMD_QUAD_ADDR_DARA_WRITE 0xE2

	#define CMD_SERIAL_READ_DUMMY 0
	#define CMD_FAST_READ_DUMMY 1
	#define CMD_DUAL_OP_READ_DUMMY 1
	#define CMD_DUAL_IO_READ_DUMMY 2
	#define CMD_QUAD_OP_READ_DUMMY 1
	#define CMD_QUAD_IO_READ_DUMMY 4
	#define CMD_SERIAL_WRITE_DUMMY 0
	#define CMD_DUAL_DATA_WRITE_DUMMY 0
	#define CMD_DUAL_ADDR_DATA_WRITE_DUMMY 0
	#define CMD_QUAD_DATA_WRITE_DUMMY 0
	#define CMD_QUAD_ADDR_DARA_WRITE_DUMMY 0

	#define ESC_CSR_CMD_REG		0x304
	#define ESC_CSR_DATA_REG	0x300
	#define ESC_WRITE_BYTE 		0x80
	#define ESC_READ_BYTE 		0xC0
	#define ESC_CSR_BUSY		0x80

    #define SYS_FREQ_MHZ     80

	#define SPI_CLK_DIV(MHz) ((SYS_FREQ_MHZ/(2*MHz))-1)

	#define SPI_MODE0 0
	#define SPI_MODE1 1
	#define SPI_MODE2 2
	#define SPI_MODE3 3

	#define CSLOW()     HAL_GPIO_WritePin(SPI2_NESS_GPIO_Port,SPI2_NESS_Pin,GPIO_PIN_RESET)
	#define CSHIGH()    HAL_GPIO_WritePin(SPI2_NESS_GPIO_Port,SPI2_NESS_Pin,GPIO_PIN_SET) 


	#define SPIWriteByte(UINT8) SPIWrite(UINT8)
	#define SPIReadByte(void) SPIRead(void)


	// *****************************************************************************
	// *****************************************************************************
	// Section: File Scope Functions
	// *****************************************************************************
	// *****************************************************************************

	void SPIWritePDRamRegister(UINT8 *WriteBuffer, UINT16 Address, UINT16 Count);
	void SPIReadPDRamRegister(UINT8 *ReadBuffer, UINT16 Address, UINT16 Count);
	void SPIWriteRegister( UINT8 *WriteBuffer, UINT16 Address, UINT16 Count);
	void SPIReadDRegister(UINT8 *ReadBuffer, UINT16 Address, UINT16 Count);
    void SPIReadRegUsingCSR(UINT8 *ReadBuffer, UINT16 Address, UINT8 Count);
    void SPIWriteRegUsingCSR( UINT8 *WriteBuffer, UINT16 Address, UINT8 Count);
	void SPIWriteDWord (UINT16 Address, UINT32 Val);
	UINT32 SPIReadDWord (UINT16 Address);
	UINT8 SPIRead(void);
	void SPIWrite(UINT8 data);
	void SPIPut(UINT8 data);
    void SPIWriteBurstMode (UINT32 Val);
    UINT32 SPIReadBurstMode (void);
    void SPISendAddr (UINT16 Address);
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* PMPDRIVER_H */

