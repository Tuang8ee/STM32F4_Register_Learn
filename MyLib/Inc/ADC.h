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

#ifdef STM32F407DEF_H_
	// ADC Resolution
	#define ADC_12_BIT	0
	#define ADC_10_BIT	1
	#define ADC_8_BIT	2
	#define ADC_6_BIT	3
	// ADC control register 1
	#define AWDCH 		0
	#define EOCIE		5
	#define AWIDE		6
	#define JEOCIE		7
	#define SCAN		8
	#define AWDSGL		9
	#define JAUTO		10
	#define DISCEN		11
	#define JDISCEN		12
	#define DISCNUM		13
	#define JAWDEN		22
	#define AWDEN		23
	#define RES			24
	#define OVRIE		26
	// ADC control register 2
	#define ADON		0
	#define CONT		1
	#define CR2_DMA		8
	#define CR2_DDS		9
	#define EOCS		10
	#define ALIGN		11
	#define JEXTSEL		16
	#define JEXTEN		20
	#define JSWSTART	22
	#define EXTSEL		24
	#define EXTEN		28
	#define SWSTART		30
	// ADC Channel X sampling time selection
	#define SAMPLE_3CYC		0
	#define SAMPLE_15CYC	1
	#define SAMPLE_28CYC	2
	#define SAMPLE_56CYC	3
	#define SAMPLE_84CYC	4
	#define SAMPLE_112CYC	5
	#define SAMPLE_144CYC	6
	#define SAMPLE_480CYC	7
	// ADAC sample time resgister 1 (ADC_SMPR1)
	#define SMP10	0
	#define SMP11	3
	#define SMP12	6
	#define SMP13	9
	#define SMP14	12
	#define SMP15	15
	#define SMP16	18
	#define SMP17	21
	#define SMP18	24
	// ADAC sample time resgister 2 (ADC_SMPR2)
	#define SMP0	0
	#define SMP1	3
	#define SMP2	6
	#define SMP3	9
	#define SMP4	12
	#define SMP5	15
	#define SMP6	18
	#define SMP7	21
	#define SMP8	24
	#define SMP9	27

	// ADC regular sequence register 1 (ADC_SQR1)
	#define SQ13		0
	#define SQ14		5
	#define SQ15		10
	#define SQ16		15
	#define L			20
	// ADC regular sequence register 2 (ADC_SQR2)
	#define SQ7		0
	#define SQ8		5
	#define SQ9		10
	#define SQ10	15
	#define SQ11	20
	#define SQ12	25
	// ADC regular sequence register 3 (ADC_SQR3)
	#define SQ1		0
	#define SQ2		5
	#define SQ3		10
	#define SQ4		15
	#define SQ5		20
	#define SQ6		25
	// ADC prescaler
	#define PCKL2_DIV_2	0
	#define PCKL2_DIV_4	1
	#define PCKL2_DIV_6	2
	#define PCKL2_DIV_8	3
	// ADC common control register (ADC_CCR)
	#define MULTI	0
	#define DELAY	8
	#define DDS		13
	#define CCR_DMA	14
	#define ADCPRE	16
	#define VBATE	22
	#define TSWREFE	23
#endif

Section void ADC1_Config(void);
void ADC1_Start(uint8_t channel);
uint16_t ADC1_GetValue(uint8_t channel);

#endif /* ADC_H_ */
