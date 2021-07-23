/*
 * UART.h
 *
 *  Created on: Jul 12, 2021
 *      Author: tuang
 */

#ifndef UART_H_
#define UART_H_

#ifndef GPIO_H_
	#include "GPIO.h"
#endif

#ifdef STM32F407DEF_H_
	// USART Control register 1
	#define SBK 		0
	#define RWu			1
	#define RE			2
	#define TE			3
	#define IDLEIE		4
	#define RXNEIE		5
	#define TCIE		6
	#define TXEIE 		7
	#define PEIE		8
	#define PS			9
	#define PCE			10
	#define WAKE		11
	#define M			12
	#define UE			13
	#define OVER8		15

	// Value off M bit in USART Control register 1
	#define DATA_BIT_8	0
	#define DATA_BIT_9	1

	// USART Control register 2
	#define ADD			0
	#define LBDL		5
	#define LBDIE		6
	#define LBCL		8
	#define CPHA		9
	#define CPOL		10
	#define CLKEN		11
	#define UART_STOP	12
	#define LINEN		14

	// Value off STOP bit in USART Control register 2
	#define STOP_BIT_1		0
	#define STOP_BIT_0_5	1
	#define STOP_BIT_2		2
	#define STOP_BIT_1_5	3

	// USART Status register
	#define PE		0
	#define FE		1
	#define NF		2
	#define ORE		3
	#define IDLE	4
	#define RXNE	5
	#define TC		6
	#define TXE		7
	#define LBD		8
	#define CTS		9
#endif




#define FindString(src, dic)						strstr((const char*)src, (const char*)dic)

Section void UART2_Config(void);
Section void UART_SendChar(USART_TypeDef *USARTx, char chr);
Section void UART_Writes(USART_TypeDef *USARTx, char *string, uint16_t size);
Section char UART_ReadChar(USART_TypeDef *USARTx);

#endif /* UART_H_ */
