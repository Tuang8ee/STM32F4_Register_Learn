/*
 * timer.c
 *
 *  Created on: Jul 29, 2021
 *      Author: tuang
 */

#include "timer.h"

#ifdef STM32F407DEF_H_

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

#endif /* STM32F407DEF_H_ */
