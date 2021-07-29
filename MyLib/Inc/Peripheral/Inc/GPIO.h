///*
// * GPIO.h
// *
// *  Created on: Jul 1, 2021
// *      Author: tuang
// */
//
#ifndef GPIO_H_
#define GPIO_H_
#include "stm32.h"

#ifdef STM32F407
#ifndef STM32F407DEF_H_
	#include "stm32f407def.h"
#endif
#endif


uint8_t GPIO_Read(GPIO_TypeDef* GPIO_Port, uint16_t GPIO_Pin);
void GPIO_Write(GPIO_TypeDef* GPIO_Port, uint16_t GPIO_Pin, uint8_t GPIO_Pin_State);
void GPIO_Toggle(GPIO_TypeDef* GPIO_Port, uint16_t GPIO_Pin);

#endif /* GPIO_H_ */
