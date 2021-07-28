/*
 * ADC.h
 *
 *  Created on: Jul 12, 2021
 *      Author: tuang
 */

#ifndef ADC_H_
#define ADC_H_

#ifndef GPIO_H_
	#include "GPIO.h"
#endif
#ifndef TIMER_H_
	#include "timer.h"
#endif


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


#endif /* ADC_H_ */
