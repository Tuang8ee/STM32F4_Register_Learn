/*
 * UART.c
 *
 *  Created on: Jul 29, 2021
 *      Author: tuang
 */
#include <UART.h>

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
