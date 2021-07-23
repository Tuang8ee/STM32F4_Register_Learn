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

#ifdef STM32F407DEF_H_

	#define SPIM_AF			AF5
	#define SPIS_AF			AF6
	// SPI1 PINs define
	#define SPI_CS_PORT		GPIOA
	#define SPI_CS_PIN		4

	#define SPI1_PORT		GPIOA
	#define SPI1_PORT_EN	GPIOA_EN
	#define SPI1_SCK		5
	#define SPI1_MISO		6
	#define SPI1_MOSI		7

	#define SPI1_SCK_OP		OSPEEDR5
	#define SPI1_MISO_OP	OSPEEDR6
	#define SPI1_MOSI_SP	OSPEEDR7
	#define SPI1_SCK_MODER	MODER5
	#define SPI1_MISO_MODER	MODER6
	#define SPI1_MOSI_MODER	MODER7
	#define SPI1_SCK_AF		AFRL5
	#define SPI1_MISO_AF	AFRL6
	#define SPI1_MOSI_AF	AFRL7
	#define SPI1_SCK_PUPDR	PUPDR5
	#define SPI1_MISO_PUPDR	PUPDR6
	#define SPI1_MOSI_PUPDR	PUPDR7

	// SPI2 PINs define
//	#define SPI3_CS_PORT	GPIOA
//	#define SPI3_CS_PIN		4

	#define SPI3_PORT		GPIOC
	#define SPI3_PORT_EN	GPIOC_EN
	#define SPI3_SCK		10
	#define SPI3_MISO		11
	#define SPI3_MOSI		12

	#define SPI3_SCK_OP		OSPEEDR10
	#define SPI3_MISO_OP	OSPEEDR11
	#define SPI3_MOSI_SP	OSPEEDR12
	#define SPI3_SCK_MODER	MODER10
	#define SPI3_MISO_MODER	MODER11
	#define SPI3_MOSI_MODER	MODER12

	#define SPI3_SCK_AF		AFRH10
	#define SPI3_MISO_AF	AFRH11
	#define SPI3_MOSI_AF	AFRH12
	#define SPI3_SCK_PUPDR	PUPDR10
	#define SPI3_MISO_PUPDR	PUPDR11
	#define SPI3_MOSI_PUPDR	PUPDR12

	// Data frame format
	#define DATA_FRAME_8_BIT	0
	#define DATA_FRAME_16_BIT	1
	// Master selection
	#define SLAVER_CONFIG	0
	#define MASTER_CONFIG	1
	// Baud rate control
	#define PCLK_DIV_2		0
	#define PCLK_DIV_4		1
	#define PCLK_DIV_8		2
	#define PCLK_DIV_16		3
	#define PCLK_DIV_32		4
	#define PCLK_DIV_64		5
	#define PCLK_DIV_128	6
	#define PCLK_DIV_256	7
	// Frame format
	#define MSB_FIRST	0
	#define LSB_FIRST	1
	// Receive only
	#define FULL_DUPLEX		0
	#define RECEIVE_ONLY	1

	/* SPI control register 1 (SPI_CR1) */
	#define SPICPHA		0
	#define SPICPOL		1
	#define MSTR		2
	#define BR			3
	#define SPE			6
	#define LSBFIRST 	7
	#define SSI			8
	#define SSM			9
	#define RXONLY		10
	#define DFF			11
	#define CRCNEXT		12
	#define CRCEN		13
	#define BIDIOE		14
	#define BIDIMODE	15

	/* SPI control register 2 */
	#define RXDMAEN		0
	#define TXDMAEN		1
	#define SSOE		2
	#define FRF			4
	#define ERRIE		5
	#define SPIRXNEIE		6
	#define SPITXEIE		7

	/* SPI status register (SPI_SR)*/
	#define SPIRXNE		0
	#define SPITXE		1
	#define CHSIDE 		2
	#define UDR			3
	#define CRCERR		4
	#define MODF		5
	#define OVR_SPI		6
	#define BSY			7
	#define FRE			8
#endif



void SPI1_Config();
void SPI3_Config();
void SPI_Enable(SPI_TypeDef * SPIx);
void SPI_Disable(SPI_TypeDef * SPIx);
void SPI_CS_Enable(void);
void SPI_CS_Disable(void);
void SPI_Transmit(SPI_TypeDef * SPIx, uint8_t *data, uint8_t size);
void SPI_Receive(SPI_TypeDef * SPIx, uint8_t *data, uint8_t size);
void SPI_TransmitReceive(SPI_TypeDef * SPIx, uint8_t *tx_data, uint8_t *rx_data, uint8_t size);
void SPI_TransmitReceives(SPI_TypeDef * SPIx, SPI_TypeDef * SPIy ,uint8_t *tx_data, uint8_t *rx_data, uint8_t size);

#endif /* SPI_H_ */
