/*
 * GPIO.h
 *
 *  Created on: Jul 1, 2021
 *      Author: tuang
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f407def.h"

#define HIGH	1
#define LOW		0
#ifdef STM32F407DEF_H_
// EXTI Registers
	#define MR0			0
	#define MR1			1
	#define MR2			2
	#define MR3			3
	#define MR4			4
	#define MR5			5
	#define MR6			6
	#define MR7			7
	#define MR8			8
	#define MR9			9
	#define MR10		10
	#define MR11		11
	#define MR12		12
	#define MR13		13
	#define MR14		14
	#define MR15		15
	#define MR16		16
	#define MR17		17
	#define MR18		18
	#define MR19		19
	#define MR20		20
	#define MR21		21
	#define MR22		22

	#define PR0			0
	#define PR1			1
	#define PR2			2
	#define PR3			3
	#define PR4			4
	#define PR5			5
	#define PR6			6
	#define PR7			7
	#define PR8			8
	#define PR9			9
	#define PR10		10
	#define PR11		11
	#define PR12		12
	#define PR13		13
	#define PR14		14
	#define PR15		15
	#define PR16		16
	#define PR17		17
	#define PR18		18
	#define PR19		19
	#define PR20		20
	#define PR21		21
	#define PR22		22

	#define TRIG0		0
	#define TRIG1		1
	#define TRIG2		2
	#define TRIG3		3
	#define TRIG4		4
	#define TRIG5		5
	#define TRIG6		6
	#define TRIG7		7
	#define TRIG8		8
	#define TRIG9		9
	#define TRIG10		10
	#define TRIG11		11
	#define TRIG12		12
	#define TRIG13		13
	#define TRIG14		14
	#define TRIG15		15
	#define TRIG16		16
	#define TRIG17		17
	#define TRIG18		18
	#define TRIG19		19
	#define TRIG20		20
	#define TRIG21		21
	#define TRIG22		22


	#define OUTPUT_PP	0
	#define OUTPUT_OD	1

	#define PUP_N_PP	0
	#define PUP_PU		1
	#define PUP_PD		2
	#define PUP_R		3

	#define INPUT	0
	#define OUTPUT	1
	#define AFM		2
	#define ANL		3
	// GPIO port mode register
	#define MODER0		0
	#define MODER1		2
	#define MODER2		4
	#define MODER3		6
	#define MODER4		8
	#define MODER5		10
	#define MODER6		12
	#define MODER7		14
	#define MODER8		16
	#define MODER9		18
	#define MODER10		20
	#define MODER11		22
	#define MODER12		24
	#define MODER13		26
	#define MODER14		28
	#define MODER15		30

	// GGIO port output type register
	#define OT0				0
	#define OT1				1
	#define OT2				2
	#define OT3				3
	#define OT4				4
	#define OT5				5
	#define OT6				6
	#define OT7				7
	#define OT8				8
	#define OT9				9
	#define OT10			10
	#define OT011			11
	#define OT12			12
	#define OT13			13
	#define OT14			14
	#define OT15			15


	// GPIO port speed register
	#define OSPEEDR0		0
	#define OSPEEDR1		2
	#define OSPEEDR2		4
	#define OSPEEDR3		6
	#define OSPEEDR4		8
	#define OSPEEDR5		10
	#define OSPEEDR6		12
	#define OSPEEDR7		14
	#define OSPEEDR8		16
	#define OSPEEDR9		18
	#define OSPEEDR10		20
	#define OSPEEDR11		22
	#define OSPEEDR12		24
	#define OSPEEDR13		26
	#define OSPEEDR14		28
	#define OSPEEDR15		30

	#define L_SPEED		0
	#define M_SPEED		1
	#define H_SPEED		2
	#define VH_SPEED	3

	// GPIO port mode register
	#define PUPDR0		0
	#define PUPDR1		2
	#define PUPDR2		4
	#define PUPDR3		6
	#define PUPDR4		8
	#define PUPDR5		10
	#define PUPDR6		12
	#define PUPDR7		14
	#define PUPDR8		16
	#define PUPDR9		18
	#define PUPDR10		20
	#define PUPDR011	22
	#define PUPDR12		24
	#define PUPDR13		26
	#define PUPDR14		28
	#define PUPDR15		30
	// GPIO alternate funcion register
	// GPIO alternate function low register
	#define AFRL		AFR[0]
	#define AFRL0		0
	#define AFRL1		4
	#define AFRL2		8
	#define AFRL3		12
	#define AFRL4		16
	#define AFRL5		20
	#define AFRL6		24
	#define AFRL7		28

	#define AFRH		AFR[1]
	#define AFRH8		0
	#define AFRH9		4
	#define AFRH10		8
	#define AFRH11		12
	#define AFRH12		16
	#define AFRH13		20
	#define AFRH14		24
	#define AFRH15		28

	// AFR selection
	#define AF0		0
	#define AF1		1
	#define AF2		2
	#define AF3		3
	#define AF4		4
	#define AF5		5
	#define AF6		6
	#define AF7		7
	#define AF8		8
	#define AF9		9
	#define AF10	10
	#define AF11	11
	#define AF12	12
	#define AF13	13
	#define AF14	14
	#define AF15	15
#endif

Section void Interrupt_Config(void);
Section uint8_t GPIO_Read(GPIO_TypeDef* GPIO_Port, uint16_t GPIO_Pin);
Section void GPIO_Write(GPIO_TypeDef* GPIO_Port, uint16_t GPIO_Pin, uint8_t GPIO_Pin_State);
Section void GPIO_Toggle(GPIO_TypeDef* GPIO_Port, uint16_t GPIO_Pin);

#endif /* GPIO_H_ */
