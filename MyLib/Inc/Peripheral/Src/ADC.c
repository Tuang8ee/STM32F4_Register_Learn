/*
 * ADC.c
 *
 *  Created on: Jul 29, 2021
 *      Author: tuang
 */

#include "ADC.h"

#ifdef STM32F407DEF_H_

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

#endif /* STM32F407DEF_H_ */
