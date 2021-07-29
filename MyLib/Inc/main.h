/*
 * main.h
 *
 *  Created on: Jul 1, 2021
 *      Author: tuang
 */

#ifndef MAIN_H_
#define MAIN_H_

/*
 * C language library
 */
#include "stdio.h"
#include "string.h"
#include "STM32F407Config.h"

//#include "SysClockConfig.h"
/*
 * STM32 peripherals library
 */

/*
 * External peripheral
 */

//#include "DS3231.h"

void Hardware_Config(void)
{
	SysClock_Config();
	SysTick_Config(100000);
	GPIO_Config();
	Interrupt_Config();
	TIM7_Config();
	UART2_Config();
	SPI1_Config();
	SPI3_Config();
	ADC1_Config();
//	I2C1_Config();
}
void Delay_Cycle (uint32_t time)
{
	while (time --);
}


#endif /* MAIN_H_ */
