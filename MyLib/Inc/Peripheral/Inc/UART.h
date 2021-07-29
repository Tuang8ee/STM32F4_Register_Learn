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

void UART_SendChar(USART_TypeDef *USARTx, char chr);
void UART_Writes(USART_TypeDef *USARTx, char *string, uint16_t size);
char UART_ReadChar(USART_TypeDef *USARTx);

#endif /* UART_H_ */
