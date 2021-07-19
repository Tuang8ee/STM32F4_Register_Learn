/*
 * GPIO.c
 *
 *  Created on: Jul 1, 2021
 *      Author: tuang
 */


#include "GPIO.h"

#define HIGH	1
#define LOW		0

#ifdef STM32F407DEF_H_

void Interrupt_Config(void)
{
	RCC -> APB2ENR |= (1 << SYSCFG_EN); 	// Enable SYSCNFG Clock
	SYSCFG -> EXTICR[0] &= 0x0;				// PORT A: Interrupt
	EXTI -> IMR	 |= (1 << MR0);
	EXTI -> RTSR |= (1 << TRIG0);
	EXTI -> FTSR |= (1 << TRIG0);
	NVIC_SetPriority(EXTI0_IRQn, 1);
	NVIC_EnableIRQ(EXTI0_IRQn);
}

uint8_t GPIO_Read(GPIO_TypeDef* GPIO_Port, uint16_t GPIO_Pin)
{
	uint8_t GPIO_Pin_State;
	if(GPIO_Port -> IDR & (1 << GPIO_Pin))
	{
		GPIO_Pin_State = HIGH;
	}
	else
	{
		GPIO_Pin_State = LOW;
	}
	return GPIO_Pin_State;
}

void GPIO_Write(GPIO_TypeDef* GPIO_Port, uint16_t GPIO_Pin, uint8_t GPIO_Pin_State)
{
	switch(GPIO_Pin_State)
	{
	case LOW:
		GPIO_Port -> BSRR |= ((1 << GPIO_Pin) << 16);
		break;
	case HIGH:
		GPIO_Port -> BSRR |= (1 << GPIO_Pin);
		break;
	default:
		GPIO_Port -> BSRR |= ((1 << GPIO_Pin) << 16);
		break;
	}
}
void GPIO_Toggle(GPIO_TypeDef* GPIO_Port, uint16_t GPIO_Pin)
{
	if(GPIO_Read(GPIO_Port, GPIO_Pin))
	{
		GPIO_Write(GPIO_Port, GPIO_Pin, LOW);
	}
	else
	{
		GPIO_Write(GPIO_Port, GPIO_Pin, HIGH);
	}
}
#endif
