/*
 * SPI.c
 *
 *  Created on: Jul 29, 2021
 *      Author: tuang
 */

#include "SPI.h"

#ifdef STM32F407DEF_H_
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

#endif /* STM32F407_H_ */
