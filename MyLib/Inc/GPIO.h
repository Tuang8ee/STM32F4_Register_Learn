///*
// * GPIO.h
// *
// *  Created on: Jul 1, 2021
// *      Author: tuang
// */
//
#ifndef GPIO_H_
#define GPIO_H_
#include "SysClockConfig.h"


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

#endif /* GPIO_H_ */
