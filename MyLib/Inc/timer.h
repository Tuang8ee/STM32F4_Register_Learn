/*
 * timer.h
 *
 *  Created on: Jul 12, 2021
 *      Author: tuang
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "stm32.h"

#ifdef STM32F407
	#include "stm32f407def.h"
#endif

#ifdef STM32F407DEF_H_
	// TIM6 & TIM7 control register 1
	#define CEN			0
	#define UDIS		1
	#define OPM			3
	#define ARPE		7

	// TIM6 & TIM7 status register
	#define UIF			0

	// TIM6 & TIM7 DMA/Interrupt enable register
	#define UIE	0
	#define UDE	8
#endif

Section void TIM6_Config(void);
Section void TIM7_Config(void);
Section void TIM6_Delay_us(uint16_t time);
Section void TIM6_Delay_ms(uint32_t time);

#endif /* TIMER_H_ */
