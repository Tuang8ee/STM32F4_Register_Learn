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
#ifndef STM32F407DEF_H_
	#include "stm32f407def.h"
#endif
#endif

void TIM6_Config(void);
void TIM6_Delay_us(uint16_t time);
void TIM6_Delay_ms(uint32_t time);

#endif /* TIMER_H_ */
