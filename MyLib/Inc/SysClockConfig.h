/*
 * SysClockConfig.h
 *
 *  Created on: Jul 23, 2021
 *      Author: tuang
 */
#include "stm32.h"

#ifdef STM32F407
	#include "stm32f407def.h"
#endif

void SysClock_Config(void);
