/*
 * Interrupts.h
 *
 *  Created on: Jul 28, 2021
 *      Author: tuang
 */

#ifndef INC_INTERRUPTS_H_
#define INC_INTERRUPTS_H_

#include "string.h"
#include "Peripheral.h"

void SysTick_Handler(void);
void EXTI0_IRQHandler(void);
void TIM7_IRQHandler(void);
void USART2_IRQHandler(void);
void USART2_RX_Interrupt(void);
#endif /* INC_INTERRUPTS_H_ */
