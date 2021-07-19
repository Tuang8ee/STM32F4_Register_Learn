/*
 * timer.c
 *
 *  Created on: Jul 12, 2021
 *      Author: tuang
 */

#include "timer.h"

#ifdef STM32F407DEF_H_

void TIM6_Config(void)
{
	/*
	 * APB1 Timer clocks: 50Mhz
	 * Enable Timer 6
	 * Timer Prescale: 50Mhz/50 ~ 1us
	 * Counter Enable
	 */
	RCC -> APB1ENR |= (1 << TIM6_EN);

	TIM6 -> PSC = 50 - 1;

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

void TIM7_Config(void)
{
	/*
	 * APB1 Timer clocks: 50Mhz
	 * Enable Timer 7
	 * Timer Prescale: 50Mhz/50000 ~ 1ms
	 * Counter = 1000 (64535 - 65535) = 1s : Interrupt
	 * Counter Enable
	 */
	RCC -> APB1ENR |= (1 << TIM7_EN);

	TIM7 -> DIER |= (1 << UIE);
	TIM7 -> PSC = 50000 - 1;
	TIM7 -> CNT = 64535;

	TIM7 -> CR1 |= (1 << CEN);
	/*
	 * NVIC set enable Interrupt
	 */
	NVIC_SetPriority(TIM7_IRQn, 2);
	NVIC_EnableIRQ(TIM7_IRQn);
}
#endif
