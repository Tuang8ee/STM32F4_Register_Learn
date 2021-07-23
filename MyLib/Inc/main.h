/*
 * main.h
 *
 *  Created on: Jul 1, 2021
 *      Author: tuang
 */

#ifndef MAIN_H_
#define MAIN_H_

/*
 * C language library
 */
#include "stdio.h"
#include "string.h"
#include "PeripheralConfig.h"
/*
 * STM32 peripherals library
 */


/*
 * External peripheral
 */

//#include "DS3231.h"

Section void USART2_RX_Interrupt(void);
Section void Delay_Cycle (uint32_t time);


#endif /* MAIN_H_ */
