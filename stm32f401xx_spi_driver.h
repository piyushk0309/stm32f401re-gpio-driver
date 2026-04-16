/*
 * stm32f401xx_spi_driver.h
 *
 *  Created on: 15-Apr-2026
 *      Author: hp
 */

#ifndef INC_STM32F401XX_SPI_DRIVER_H_
#define INC_STM32F401XX_SPI_DRIVER_H_



#endif /* INC_STM32F401XX_SPI_DRIVER_H_ */




// CONFIGURATION STRUCTURE FOR SPIX PERIPHERAL
typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
} SPI_Config_t;


// HANDLE STRUCTURE FOR SPIx PERIPHERAL

typedef struct
{
	SPI_RegDef_t	*pSPIx;
	SPI_Config_t	*SPIConfig;

} SPI_Handle_t;




/* PERIPHERAL CLOCK SETUP*/

void SPI_PeriClockControl(SPI_Reg_Def_t *pSPIx,uint8_t EnorDi);

/*INIT AND DE-INIT*/

void GPIO_Init(SPI_Handle_t *pSPIHandle);
void GPIO_DeInit(SPI_Reg_Def_t *pSPIx);
