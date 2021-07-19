/*
 * stm32f407def.h
 *
 *  Created on: Jul 9, 2021
 *      Author: tuang
 */
#include "stm32f407xx.h"
#include "stdint.h"

#ifndef STM32F407DEF_H_
#define STM32F407DEF_H_

#define Section	__attribute__((section(".sec.")))

#define PLL_M 	8
#define PLL_N 	200
#define PLL_P	0		//00 PLLP = 2
#define PLL_Q 	4



// RCC APB1 peripheral clock enable register (RCC_APB1ENR)
#define TIM2_EN		0
#define TIM3_EN		1
#define TIM4_EN		2
#define TIM5_EN		3
#define TIM6_EN		4
#define TIM7_EN		5
#define TIM12_EN	6
#define TIM13_EN	7
#define TIM14_EN	8
#define WWDG_EN		11
#define SPI2_EN		14
#define SPI3_EN		15
#define UART2_EN	17
#define UART3_EN	18
#define UART4_EN	19
#define UART5_EN	20
#define I2C1_EN		21
#define I2C2_EN		22
#define I2C3_EN		23
#define CAN1_EN		25
#define CAN2_EN		26
#define PWR_EN		28
#define DAC_EN		29
#define UART7_EN	30
#define UART8_EN	31

// RCC APB2 peripheral clock enable register (RCC_APB2ENR)
#define TIM1_EN		0
#define TIM8_EN		1
#define UART1_EN	4
#define UART6_EN	5
#define ADC1_EN		8
#define ADC2_EN		9
#define ADC3_EN		10
#define SDIO_EN		11
#define SPI1_EN		12
#define SPI4_EN		13
#define SYSCFG_EN	14
#define TIM9_EN		16
#define TIM10_EN	17
#define TIM11_EN	18
#define SPI5_EN		20
#define SPI6_EN		21
#define SAI1_EN		22
#define LTDC_EN		26

// RCC_AHB1 peripheral clock register
#define GPIOA_EN	0
#define GPIOB_EN	1
#define GPIOC_EN	2
#define GPIOD_EN	3
#define GPIOE_EN	4
#define GPIOF_EN	5
#define GPIOG_EN	6
#define GPIOH_EN	7
#define GPIOI_EN	8
#define GPIOJ_EN	9
#define GPIOK_EN	10
#define CRC_EN		12
#define BKPSRAM_EN	19
#define CCMDATARAM_EN	20


#endif /* STM32F407DEF_H_ */
