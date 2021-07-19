/*
 * SPI.c
 *
 *  Created on: Jul 13, 2021
 *      Author: tuang
 */
#include "SPI.h"

#ifdef STM32F407DEF_H_


void SPI1_Config(void)
{
	/*
	 * The maximum SPI clock speed is 5MHz with 100pF maximum loading
	 * and the timing scheme follows clock polarity (CPOL = 1) and
	 * clock phase (CPHA = 1)
	 *
	 * APB2 Clock = 50Mhz => BR = F.PCLK/16 < 5MHz
	 * SPI config:
	 * MODE: Master full duplex
	 * Frame: 8bit | First bit: MSB bit
	 * SCK Mode: SPOL = 1 | SPHA = 1
	 */

	RCC -> APB2ENR |= (1 << SPI1_EN);
	SPI1 -> CR1 |= (DATA_FRAME_8_BIT << DFF) | (FULL_DUPLEX << RXONLY) | (1 << SSM) | (1 << SSI) | (MSB_FIRST << LSBFIRST);
	SPI1 -> CR1 |= (PCLK_DIV_16 << BR) | (MASTER_CONFIG << MSTR) | (1 << SPICPOL) | (1 << SPICPHA);
	SPI1 -> CR1 |= (1 << SPE);

	RCC -> AHB1ENR |= (1 << SPI1_PORT_EN);
	// SCK, MOSI, MISO pins config
	SPI1_PORT -> MODER |= (AFM << SPI1_MOSI_MODER) | (AFM << SPI1_MISO_MODER) | (AFM << SPI1_SCK_MODER);
	SPI1_PORT -> OSPEEDR |= (VH_SPEED << SPI1_MOSI_SP) | (VH_SPEED << SPI1_MISO_OP) | (VH_SPEED << SPI1_SCK_OP);
	SPI1_PORT -> IDR |= (1 << SPI1_MOSI) | (1 << SPI1_MISO) | (1 << SPI1_SCK);
	SPI1_PORT -> AFRL |= (SPIM_AF << SPI1_MOSI_AF) | (SPIM_AF << SPI1_MISO_AF) | (SPIM_AF << SPI1_SCK_AF);
	// SS pin config
	SPI_CS_PORT -> MODER |= (OUTPUT << SPI_CS_PIN * 2);
	SPI_CS_PORT -> OSPEEDR |= (VH_SPEED << SPI_CS_PIN * 2);
}


void SPI3_Config(void)
{
	/*
	 * The maximum SPI clock speed is 5MHz with 100pF maximum loading
	 * and the timing scheme follows clock polarity (CPOL = 1) and
	 * clock phase (CPHA = 1)
	 *
	 * APB2 Clock = 50Mhz => BR = F.PCLK/16 < 5MHz
	 * SPI config:
	 * MODE: Slaver full duplex
	 * Frame: 8bit | First bit: MSB bit
	 * SCK Mode: SPOL = 1 | SPHA = 1
	 * Hardware input slaver: PA15
	 */

	RCC -> APB1ENR |= (1 << SPI3_EN);
	SPI3 -> CR1 |= (DATA_FRAME_8_BIT << DFF) | (FULL_DUPLEX << RXONLY) | (0 << SSM) | (0 << SSI) | (MSB_FIRST << LSBFIRST);
	SPI3 -> CR1 |= (1 << SPICPOL) | (1 << SPICPHA);
	SPI3 -> CR1 |= (1 << SPE);

	RCC -> AHB1ENR |= (1 << SPI3_PORT_EN);
	// SCK, MOSI, MISO pins config
	SPI3_PORT -> MODER |= (AFM << SPI3_MOSI_MODER) | (AFM << SPI3_MISO_MODER) | (AFM << SPI3_SCK_MODER);
	SPI3_PORT -> OSPEEDR |= (VH_SPEED << SPI3_MOSI_SP) | (VH_SPEED << SPI3_MISO_OP) | (VH_SPEED << SPI3_SCK_OP);
	SPI3_PORT -> IDR |= (1 << SPI3_MOSI) | (1 << SPI3_MISO) | (1 << SPI3_SCK);
	SPI3_PORT -> AFRH |= (SPIS_AF << SPI3_MOSI_AF) | (SPIS_AF << SPI3_MISO_AF) | (SPIS_AF << SPI3_SCK_AF);
	//NSS pin config (Slaver Mode)
	RCC -> AHB1ENR |= (1 << GPIOA_EN);
	GPIOA -> MODER |= (AFM << MODER15);
	GPIOA -> OSPEEDR |= (VH_SPEED << OSPEEDR15);
	GPIOA -> OTYPER |= (OUTPUT_PP << OT15);
	GPIOA -> PUPDR |= (PUP_N_PP << PUPDR15);
	GPIOA -> IDR |= (0 << 15);
	GPIOA -> AFRH |= (SPIS_AF << AFRH15);
}
void SPI_Enable(SPI_TypeDef * SPIx)
{
	SPIx -> CR1 |= (1 << SPE);
}
void SPI_Disable(SPI_TypeDef * SPIx)
{
	SPIx -> CR1 &= ~(1 << SPE);
}
void SPI_CS_Enable(void)
{
	GPIO_Write(SPI_CS_PORT, SPI_CS_PIN, LOW);
}
void SPI_CS_Disable(void)
{
	GPIO_Write(SPI_CS_PORT, SPI_CS_PIN, HIGH);
}

void SPI_Transmit(SPI_TypeDef * SPIx, uint8_t *data, uint8_t size)
{
	uint32_t timeout = 100000;
	uint8_t index = 0;
	for(index = 0; index < size;)
	{
		// Wait for TXE bit is set
		while(timeout)
		{
			timeout--;
			if((SPIx -> SR) & (1 << SPITXE))
			{
				timeout = 0;
				break;
			}
		}
		timeout = 100000;
		// Load the data into the Data Register
		SPIx -> DR = data[index];
		index++;
	}
	// Wait for TXE bit is set
	timeout = 100000;
	while(timeout--)
	{
		if((SPIx -> SR) & (1 << SPITXE))
		{
			timeout = 0;
			break;
		}
	}
	// Wait for BSY bit is reset
	timeout = 100000;
	while(timeout--)
	{
		if(!((SPIx -> SR) & (1 << BSY)))
		{
			break;
		}
	}
}

void SPI_Receive(SPI_TypeDef * SPIx, uint8_t *data, uint8_t size)
{
	uint32_t timeout = 100000;
	uint8_t index = 0;
	for(index = 0; index < size;)
	{
		// Wait for BSY bit is reset
		timeout = 100000;
		while(timeout)
		{
			timeout--;
			if(!((SPIx -> SR) & (1 << BSY)))
			{
				timeout = 0;
				break;
			}
		}
		// Wait for RXNE bit is set
		timeout = 10000;
		while(((SPIx -> SR) & (1 << SPIRXNE)) != (1 << SPIRXNE))
		{
			timeout--;
			if(timeout == 0)break;
		}
		// Load the data into the Data Register
		data[index] = SPIx -> DR;
		index++;
	}
}

void SPI_TransmitReceive(SPI_TypeDef * SPIx, uint8_t *tx_data, uint8_t *rx_data, uint8_t size)
{
	uint32_t timeout = 100000;
	uint8_t index = 0;
	for(index = 0; index < size;)
	{
		// Wait for TXE bit is set
		timeout = 100000;
		while(timeout)
		{
			timeout--;
			if((SPIx -> SR) & (1 << SPITXE))
			{
				timeout = 0;
				break;
			}
		}
		// Load the data into the Data Register
		SPIx -> DR = tx_data[index];

		//Read data:
		// Wait for BSY bit is reset
		timeout = 100000;
		while(timeout)
		{
			timeout--;
			if(!((SPIx -> SR) & (1 << BSY)))
			{
				timeout = 0;
				break;
			}
		}
		// Wait for RXNE bit is set
		timeout = 10000;
		while(((SPIx -> SR) & (1 << SPIRXNE)) != (1 << SPIRXNE))
		{
			timeout--;
			if(timeout == 0)break;
		}
		// Read the data from the Data Register
		rx_data[index] = SPIx -> DR;
		index++;
	}
	// Wait for TXE bit is set
	timeout = 100000;
	while(timeout--)
	{
		if((SPIx -> SR) & (1 << SPITXE))
		{
			timeout = 0;
			break;
		}
	}
	// Wait for BSY bit is reset
	timeout = 100000;
	while(timeout--)
	{
		if(!((SPIx -> SR) & (1 << BSY)))
		{
			break;
		}
	}
}
/*
 * Hàm này dùng chỉ để mục đích test
 * SPI1 làm Master, SP3 làm Slaver
 * SPI1 sẽ truyền n kí tự (size) cho SPI3, SPI3 nhận n kí tự.
 */
void SPI_TransmitReceives(SPI_TypeDef * SPIx, SPI_TypeDef * SPIy ,uint8_t *tx_data, uint8_t *rx_data, uint8_t size)
{
	uint32_t timeout = 100000;
	uint8_t index = 0;
	for(index = 0; index < size;)
	{
		// Wait for TXE bit is set
		timeout = 100000;
		while(timeout)
		{
			timeout--;
			if((SPIx -> SR) & (1 << SPITXE))
			{
				timeout = 0;
				break;
			}
		}
		// Load the data into the Data Register
		SPIx -> DR = tx_data[index];

		//Read data:
		// Wait for BSY bit is reset
		timeout = 100000;
		while(timeout)
		{
			timeout--;
			if(!((SPIx -> SR) & (1 << BSY)))
			{
				timeout = 0;
				break;
			}
		}
		// Wait for RXNE bit is set
		timeout = 10000;
		while(((SPIy -> SR) & (1 << SPIRXNE)) != (1 << SPIRXNE))
		{
			timeout--;
			if(timeout == 0)break;
		}
		// Read the data from the Data Register
		rx_data[index] = SPIy -> DR;
		index++;
	}
	// Wait for TXE bit is set
	timeout = 100000;
	while(timeout--)
	{
		if((SPIx -> SR) & (1 << SPITXE))
		{
			timeout = 0;
			break;
		}
	}
	// Wait for BSY bit is reset
	timeout = 100000;
	while(timeout--)
	{
		if(!((SPIx -> SR) & (1 << BSY)))
		{
			break;
		}
	}
}

#endif
