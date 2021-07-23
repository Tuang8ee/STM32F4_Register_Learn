/*
 * ADC.c
 *
 *  Created on: Jul 13, 2021
 *      Author: tuang
 */
#include "ADC.h"
#include "timer.h"

#ifdef STM32F407DEF_H_

void ADC1_Config(void)
{
	RCC -> APB2ENR |= (1 << ADC1_EN);
	RCC -> AHB1ENR |= (1 << GPIOB_EN);

	GPIOB -> MODER |= (ANL << MODER1) |(ANL << MODER0);

	ADC -> CCR |= (PCKL2_DIV_2 << ADCPRE);

	ADC1 -> CR1 |= (1 << SCAN) | (ADC_12_BIT << RES); // Scan mode + 12 bit ADC restion
	ADC1 -> CR2 = (1 << CONT);
	ADC1 -> CR2 |= (1 << EOCS); //
	ADC1 -> CR2 &= ~(1 << ALIGN);

	ADC1 -> SMPR2 |= (SAMPLE_15CYC << SMP8) | (SAMPLE_15CYC << SMP9);
	ADC1 -> SQR1 |= (1 << L);

	ADC1 -> CR2 |= (1 << ADON);
	TIM6_Delay_us(10);
}

void ADC_DMA_Start(ADC_TypeDef *ADCx)
{
	ADCx -> CR2 |= (1 << ADC_DMA);
	ADCx -> CR2 |= (1 << ADC_DDS);

	ADCx -> SQR3 |= (8 << SQ1) | (9 << SQ2);
	ADC1 -> SR = 0;
	ADC1 -> CR2 |= (1 << SWSTART);
}

void ADC1_Start(uint8_t channel)
{
	ADC1 -> SQR3 = 0;
	ADC1 -> SQR3 |= (channel << SQ1);
	ADC1 -> SR = 0;
	ADC1 -> CR2 |= (1 << SWSTART);
}

uint16_t ADC1_GetValue(uint8_t channel)
{
	ADC1_Start(channel);
	while (!(ADC1 -> SR & (1 << 1)));
	ADC1 -> SR = 0;
	return (ADC1 -> DR);
}
#endif
