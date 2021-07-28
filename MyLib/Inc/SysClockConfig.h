/*
 * SysClockConfig.h
 *
 *  Created on: Jul 28, 2021
 *      Author: tuang
 */

#ifndef INC_SYSCLOCKCONFIG_H_
#define INC_SYSCLOCKCONFIG_H_

#include "stm32.h"
#ifdef STM32F407
#include "stm32f407def.h"


typedef struct
{
	uint8_t HSE;
	uint8_t PLL;
	uint8_t PLL_M;
	uint16_t PLL_N;
	uint8_t PLL_P;
	uint8_t PLL_Q;
	uint8_t SYSCLK;
	uint8_t AHB;
	uint8_t APB1;
	uint8_t APB2;
}Clock_Typedef;

Clock_Typedef HSE_Clock =
{
		.HSE = 8,
		.PLL = 1,
		.PLL_M = 8,
		.PLL_N = 200,
		.PLL_P = 2,
		.PLL_Q = 0,
};

/*
	 * Instruction Cache: Enable
	 * Prefetch Buffer	: Enable
	 * Data Cache		: Enable
	 * Flash Latency	: 3 wait state
	 * Power Regulator Voltage Scale: Scale 1
	 * HSE clock: 	8Mhz
	 * Main PLL : Enable
	 * 	+ PLL_M	: 8
	 * 	+ PLL_N	: 200
	 * 	+ PLL_P	: 2
	 * 	=> System Clock = HSE : 8 * 200 : 2 = 100Mhz
	 * AHB Prescale		: DIV1	: System Clock : 1 = 100Mhz
	 * APB1 Prescale	: DIV4	: APB1 Prescale clock: AHB : 4 = 25Mhz
	 * APB2 Prescale	: DIV2	: APB2 Prescale clock: AHB : 2 = 50Mhz
 */
void SysClock_Config(void)
{
	FLASH -> ACR |= FLASH_ACR_DCEN | FLASH_ACR_ICEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_3WS;

	PWR -> CR |= (1 << 14);

	if(HSE_Clock.HSE != 0)
	{
		RCC -> CR |= RCC_CR_HSEON;
		while (!(RCC -> CR & RCC_CR_HSERDY));
		HSE_Clock.SYSCLK = HSE_Clock.HSE;
	}
	if(HSE_Clock. PLL != 0)
	{
		RCC -> CR |= RCC_CR_PLLON;
		while(!(RCC -> CR & RCC_CR_PLLRDY));
		RCC -> PLLCFGR = (HSE_Clock.PLL_M << 0) | (HSE_Clock.PLL_N << 6) | ((HSE_Clock.PLL_P/2 - 1) << 16);
		if(HSE_Clock.HSE != 0)
		{
			RCC -> PLLCFGR |= (RCC_PLLCFGR_PLLSRC_HSE);
		}
		RCC -> CFGR |= (RCC_CFGR_SW_PLL);
		HSE_Clock.SYSCLK = HSE_Clock.HSE / HSE_Clock.PLL_M * HSE_Clock.PLL_N / HSE_Clock.PLL_P;
	}
	RCC -> CFGR |= RCC_CFGR_HPRE_DIV1 | RCC_CFGR_PPRE1_DIV4 | RCC_CFGR_PPRE2_DIV2;
	HSE_Clock.AHB = HSE_Clock.SYSCLK;
	HSE_Clock.APB1 = HSE_Clock.SYSCLK / 4;
	HSE_Clock.APB2 = HSE_Clock.SYSCLK / 2;
	while(!(RCC -> CFGR & RCC_CFGR_SWS));

}

#endif /* STM32F407_H_ */
#endif /* INC_SYSCLOCKCONFIG_H_ */
