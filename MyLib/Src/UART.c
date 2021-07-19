/*
 * UART.c
 *
 *  Created on: Jul 12, 2021
 *      Author: tuang
 */

#include "UART.h"

void UART2_Config(void)
{
	RCC -> APB1ENR |= (1 << UART2_EN);
	/*
	 * Set UART:
	 * Pin clock
	 * Alternate function mode
	 * High Speed
	 * PA3 (ARFL3) => UART mode (AF7)
	 * PA2 (ARFL2) => UART mode (AF7)
	 */
	RCC -> AHB1ENR |= (1 << GPIOA_EN);
	GPIOA -> MODER |= (AFM << MODER2) | (AFM << MODER3);
	GPIOA -> OSPEEDR |= (H_SPEED << OSPEEDR2) | (H_SPEED << OSPEEDR3);
	GPIOA -> AFRL |= (AF7 << AFRL2) | (AF7 << AFRL3);

	/*
	 * USART2 Enable
	 * 1 Start bit, 8 Data bit, 1 Stop bit
	 */
	USART2 -> CR1 |= 0x00;
	USART2 -> CR1 |= (1 << UE);
	USART2 -> CR1 |= (DATA_BIT_8 << M);
	USART2 -> CR2 |= (STOP_BIT_1 << UART_STOP);

	/*
	 * Set baud:
	 * How to derive USARTDIV from USART_BRR register values when OVER8=1:
	 * USARTDIV = Fck / (8 * 115200) = 27.13 => 27 & 0.13
	 * DIV_Mantissa = 27
	 * 0.13 * 8, the nearest real number is 1 => DIV_Fraction = 1.
	 */
	USART2 -> CR1 |= (1 << OVER8);
	USART2 -> BRR = 0x0000;
	USART2 -> BRR |= (1 << 0) | (27 << 4);

	/*
	 * UART2:
	 * Transmitter and receiver Enable.
	 * Receiver interrupt Enable
	 */
	USART2 -> CR1 |= (1 << RE) | (1 << TE);
	USART2 -> CR1 |= (1 << RXNEIE); // RXNE interrup enable
	/*
	 * NVIC set enable Interrupt
	 */
	NVIC_SetPriority(USART2_IRQn, 2);
	NVIC_EnableIRQ(USART2_IRQn);
}

void UART2_SendChar(char chr)
{
	USART2 -> DR = chr;
	while (!(USART2 -> SR & (1 << TC)));
}
void UART2_Writes(char *string, uint16_t size)
{
	uint16_t index = 0;
	while(index < size)
	{
		UART2_SendChar(string[index]);
		index++;
	}
}
char UART2_ReadChar(void)
{
	char chr;
	chr = USART2 -> DR;
	return (chr);
}



