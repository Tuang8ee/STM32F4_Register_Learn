/*
 * main.h
 *
 *  Created on: Jul 1, 2021
 *      Author: tuang
 */

#ifndef MAIN_H_
#define MAIN_H_
#include "stm32f407def.h"
#include "string.h"
#include "GPIO.h"
#include "timer.h"
#include "UART.h"
#include "ADC.h"
#include "SPI.h"
//#include "DS3231.h"

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

Section void GPIO_Config(void);
Section void USART2_RX_Interrupt(void);
Section void SysClock_Config(void);
Section void Delay_Cycle (uint32_t time);

#endif

#endif /* MAIN_H_ */
