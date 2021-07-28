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

void TIM6_Config(void)
{
	/*
	 * APB1 Timer clocks: 50Mhz
	 * Enable Timer 6
	 * Timer Prescale: 50Mhz/50 ~ 1us
	 * Counter Enable
	 */
	RCC -> APB1ENR |= (1 << TIM6_EN);

	TIM6 -> PSC = HSE_Clock.APB1 * 2 - 1;
	TIM6 -> CNT = 0 - 1;
	TIM6 -> CR1 |= (1 << CEN);
	while(!(TIM6 -> SR & (1 << UIF)));
}

void TIM6_Delay_us(uint16_t time)
{
	TIM6_Config();
	TIM6 -> CNT = 0;


	while(TIM6 -> CNT < time);
	TIM6 -> CR1 = 0x00;
}

void TIM6_Delay_ms(uint32_t time)
{
	while(time --)
	{
		TIM6_Delay_us(1000);
	}
}

#endif /* TIMER_H_ */
