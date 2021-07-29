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



void ADC_DMA_Start(ADC_TypeDef *ADCx);
void ADC1_Start(uint8_t channel);

uint16_t ADC1_GetValue(uint8_t channel);
#endif /* ADC_H_ */
