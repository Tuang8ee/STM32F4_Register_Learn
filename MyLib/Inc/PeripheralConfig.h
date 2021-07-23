/*
 * PeripheralConfig.h
 *
 *  Created on: Jul 23, 2021
 *      Author: tuang
 */
#include "SysClockConfig.h"
#include "timer.h"
#include "UART.h"
#include "ADC.h"
#include "SPI.h"
#include "DMA.h"
#ifndef GPIO_H_
	#include "GPIO.h"
#endif

/*
 * STM32 Discovery Kit
 */
#ifdef STM32F407DEF_H_

#define LED3_Port	GPIOD
#define LED3_Pin	13
#define LED4_Port	GPIOD
#define LED4_Pin	12
#define LED5_Port	GPIOD
#define LED5_Pin	14
#define LED6_Port	GPIOD
#define LED6_Pin	15
#define BTN_Port	GPIOA
#define BTN_Pin		0

#endif

void GPIO_Config(void);
