/*
 * Interrupts.c
 *
 *  Created on: Jul 28, 2021
 *      Author: tuang
 */

#include "Interrupts.h"

uint16_t times = 0;

void SysTick_Handler(void)
{
	if(times >= 1000)
	{
		GPIO_Toggle(LED6_Port, LED6_Pin);
		times = 0;
	}
	else
	{
		times++;
	}
}
void EXTI0_IRQHandler(void)
{
	if(EXTI -> PR & (1 << PR0))
	{
		EXTI -> PR &= ~(0 << PR0);
		if(GPIO_Read(BTN_Port, BTN_Pin))
		{
			GPIO_Write(LED4_Port, LED4_Pin, HIGH);
			UART_Writes(USART2, "LED 3: BAT\n", 11);
		}
		else
		{
			GPIO_Write(LED4_Port, LED4_Pin, LOW);
			UART_Writes(USART2, "LED 3: TAT\n", 11);
		}
	}
}

void TIM7_IRQHandler(void)
{
	TIM7 -> SR &= (0 << UIF);
	TIM7 -> CNT = 65535 - 1000;
	GPIO_Toggle(LED5_Port, LED5_Pin);
}

void USART2_IRQHandler(void)
{
	if(USART2 -> SR & (1 << RXNE))
	{
		USART2_RX_Interrupt();
	}
}

char rx_array[100];
uint8_t rx_index = 0;
void USART2_RX_Interrupt(void)
{
	char chr = UART_ReadChar(USART2);
	if(chr == '{')
	{
		memset(rx_array, 0, 100);
		rx_index = 0;
		rx_array[rx_index] = chr;
		rx_index++;
	}
	else if(chr == '}')
	{
		rx_array[rx_index] = chr;
		rx_index = 0;
	}
	else
	{
		rx_array[rx_index] = chr;
		rx_index++;
	}
	if(FindString(rx_array, "BAT") != 0)
	{
		GPIO_Write(LED6_Port, LED6_Pin, HIGH);
	}
	else if(FindString(rx_array, "TAT") != 0)
	{
		GPIO_Write(LED6_Port, LED6_Pin, LOW);
	}
}
