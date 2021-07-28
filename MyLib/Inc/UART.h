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

void UART_SendChar(USART_TypeDef *USARTx, char chr)
{
	USARTx -> DR = chr;
	while (!(USARTx -> SR & (1 << TC)));
}
void UART_Writes(USART_TypeDef *USARTx, char *string, uint16_t size)
{
	uint16_t index = 0;
	while(index < size)
	{
		UART_SendChar(USARTx, string[index]);
		index++;
	}
}
char UART_ReadChar(USART_TypeDef *USARTx)
{
	char chr;
	chr = USARTx -> DR;
	return (chr);
}

#endif /* UART_H_ */
