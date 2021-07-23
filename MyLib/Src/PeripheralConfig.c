/*
 * PeripheralConfig.c
 *
 *  Created on: Jul 23, 2021
 *      Author: tuang
 */

#include "PeripheralConfig.h"

void GPIO_Config(void)
{
	// Set clock GPIO
	RCC -> AHB1ENR |= (1 << GPIOD_EN);
	// GPIO config
	GPIOD -> MODER |= (OUTPUT << LED3_Pin * 2) | (OUTPUT << LED4_Pin * 2) | (OUTPUT << LED5_Pin * 2) | (OUTPUT << LED6_Pin * 2);
	GPIOD -> OTYPER = (OUTPUT_PP << LED3_Pin) | (OUTPUT_PP << LED4_Pin) | (OUTPUT_PP << LED5_Pin) | (OUTPUT_PP << LED6_Pin);
	GPIOD -> OSPEEDR = (H_SPEED << LED3_Pin * 2) | (H_SPEED << LED4_Pin * 2) | (H_SPEED << LED5_Pin * 2) | (H_SPEED << LED6_Pin * 2);
	GPIOD -> PUPDR = (PUP_N_PP << LED3_Pin) | (PUP_N_PP << LED4_Pin) | (PUP_N_PP << LED5_Pin) | (PUP_N_PP << LED6_Pin);

	RCC -> AHB1ENR |= (1 << GPIOA_EN);
	GPIOA -> MODER |= (INPUT << BTN_Pin);
	GPIOA -> PUPDR |= (PUP_N_PP << BTN_Pin);
}
