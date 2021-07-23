/*
 * SysClockConfig.c
 *
 *  Created on: Jul 23, 2021
 *      Author: tuang
 */

#include "SysClockConfig.h"

void SysClock_Config(void)
{
	FLASH -> ACR |= FLASH_ACR_DCEN | FLASH_ACR_ICEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_3WS;

	PWR -> CR |= (1 << 14);

	RCC -> CR |= RCC_CR_HSEON | RCC_CR_PLLON;
	while (!(RCC -> CR & RCC_CR_HSERDY));
	while(!(RCC -> CR & RCC_CR_PLLRDY));

	RCC -> PLLCFGR = (PLL_M << 0) | (PLL_N << 6) | (PLL_P << 16) | (RCC_PLLCFGR_PLLSRC_HSE);

	RCC -> CFGR |= RCC_CFGR_HPRE_DIV1 | RCC_CFGR_PPRE1_DIV4 | RCC_CFGR_PPRE2_DIV2 | RCC_CFGR_SW_PLL;
	while(!(RCC -> CFGR & RCC_CFGR_SWS));

}
