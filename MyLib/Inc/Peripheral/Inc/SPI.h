/*
 * SPI.h
 *
 *  Created on: Jul 13, 2021
 *      Author: tuang
 */

#ifndef SPI_H_
#define SPI_H_

#ifndef GPIO_H_
	#include "GPIO.h"
#endif


void SPI_Enable(SPI_TypeDef * SPIx);
void SPI_Disable(SPI_TypeDef * SPIx);
void SPI_CS_Enable(void);
void SPI_CS_Disable(void);

void SPI_Transmit(SPI_TypeDef * SPIx, uint8_t *data, uint8_t size);

void SPI_Receive(SPI_TypeDef * SPIx, uint8_t *data, uint8_t size);

void SPI_TransmitReceive(SPI_TypeDef * SPIx, uint8_t *tx_data, uint8_t *rx_data, uint8_t size);
/*
 * Hàm này dùng chỉ để mục đích test
 * SPI1 làm Master, SP3 làm Slaver
 * SPI1 sẽ truyền n kí tự (size) cho SPI3, SPI3 nhận n kí tự.
 */
void SPI_TransmitReceives(SPI_TypeDef * SPIx, SPI_TypeDef * SPIy ,uint8_t *tx_data, uint8_t *rx_data, uint8_t size);


#endif /* SPI_H_ */
