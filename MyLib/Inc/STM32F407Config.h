/*
 * STM32F407Config.h
 *
 *  Created on: Jul 28, 2021
 *      Author: tuang
 */

#ifndef INC_STM32F407CONFIG_H_
#define INC_STM32F407CONFIG_H_

#include "SysClockConfig.h"
#include "GPIO.h"
#include "timer.h"
#include "ADC.h"
#include "UART.h"
#include "SPI.h"
//#include "I2C.h"


#ifdef STM32F407DEF_H_

#ifdef GPIO_H_
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

void Interrupt_Config(void)
{
	RCC -> APB2ENR |= (1 << SYSCFG_EN); 	// Enable SYSCNFG Clock
	SYSCFG -> EXTICR[0] &= 0x0;				// PORT A: Interrupt
	EXTI -> IMR	 |= (1 << MR0);
	EXTI -> RTSR |= (1 << TRIG0);
	EXTI -> FTSR |= (1 << TRIG0);
	NVIC_SetPriority(EXTI0_IRQn, 1);
	NVIC_EnableIRQ(EXTI0_IRQn);
}
#endif /* GPIO_H_ */

#ifdef TIMER_H_
void TIM7_Config(void)
{
	uint32_t TIME_Clock = HSE_Clock.APB1 * 2 * 1000000;
	/*
	 * APB1 Timer clocks: 50Mhz
	 * Enable Timer 7
	 * Timer Prescale: 50Mhz/50000 ~ 1ms
	 * Counter = 1000 (64535 - 65535) = 1s : Interrupt
	 * Counter Enable
	 */
	RCC -> APB1ENR |= (1 << TIM7_EN);

	TIM7 -> DIER |= (1 << UIE);
	TIM7 -> PSC = TIME_Clock/1000 - 1;
	TIM7 -> CNT = 65535 - 1000;

	TIM7 -> CR1 |= (1 << CEN);
	/*
	 * NVIC set enable Interrupt
	 */
	NVIC_SetPriority(TIM7_IRQn, 2);
	NVIC_EnableIRQ(TIM7_IRQn);
}
#endif /* TIMER_H_ */

#ifdef ADC_H_
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
#endif /* ADC_H_ */

#ifdef UART_H_
void UART2_Config(void)
{
	RCC -> APB1ENR |= (1 << UART2_EN);
	/*
	 * Set UART:
	 * Pin clock
	 * Alternate function mode
	 * High Speed
	 * PA3 (ARFL3) => UART mode (AF7)
	 * PA2 (ARFL2) => UART mode (AF7)
	 */
	RCC -> AHB1ENR |= (1 << GPIOA_EN);
	GPIOA -> MODER |= (AFM << MODER2) | (AFM << MODER3);
	GPIOA -> OSPEEDR |= (H_SPEED << OSPEEDR2) | (H_SPEED << OSPEEDR3);
	GPIOA -> AFRL |= (AF7 << AFRL2) | (AF7 << AFRL3);

	/*
	 * USART2 Enable
	 * 1 Start bit, 8 Data bit, 1 Stop bit
	 */
	USART2 -> CR1 |= 0x00;
	USART2 -> CR1 |= (1 << UE);
	USART2 -> CR1 |= (DATA_BIT_8 << M);
	USART2 -> CR2 |= (STOP_BIT_1 << UART_STOP);

	/*
	 * Set baud:
	 * How to derive USARTDIV from USART_BRR register values when OVER8=1:
	 * USARTDIV = Fck / (8 * 115200) = 27.13 => 27 & 0.13
	 * DIV_Mantissa = 27
	 * 0.13 * 8, the nearest real number is 1 => DIV_Fraction = 1.
	 */
	USART2 -> CR1 |= (1 << OVER8);
	USART2 -> BRR = 0x0000;
	USART2 -> BRR |= (1 << 0) | (27 << 4);

	/*
	 * UART2:
	 * Transmitter and receiver Enable.
	 * Receiver interrupt Enable
	 */
	USART2 -> CR1 |= (1 << RE) | (1 << TE);
	USART2 -> CR1 |= (1 << RXNEIE); // RXNE interrup enable
	/*
	 * NVIC set enable Interrupt
	 */
	NVIC_SetPriority(USART2_IRQn, 2);
	NVIC_EnableIRQ(USART2_IRQn);
}
#endif /* UART_H_ */

#ifdef SPI_H_
void SPI1_Config(void)
{
	/*
	 * The maximum SPI clock speed is 5MHz with 100pF maximum loading
	 * and the timing scheme follows clock polarity (CPOL = 1) and
	 * clock phase (CPHA = 1)
	 *
	 * APB2 Clock = 50Mhz => BR = F.PCLK/16 < 5MHz
	 * SPI config:
	 * MODE: Master full duplex
	 * Frame: 8bit | First bit: MSB bit
	 * SCK Mode: SPOL = 1 | SPHA = 1
	 */

	RCC -> APB2ENR |= (1 << SPI1_EN);
	SPI1 -> CR1 |= (DATA_FRAME_8_BIT << DFF) | (FULL_DUPLEX << RXONLY) | (1 << SSM) | (1 << SSI) | (MSB_FIRST << LSBFIRST);
	SPI1 -> CR1 |= (PCLK_DIV_16 << BR) | (MASTER_CONFIG << MSTR) | (1 << SPICPOL) | (1 << SPICPHA);
	SPI1 -> CR1 |= (1 << SPE);

	RCC -> AHB1ENR |= (1 << SPI1_PORT_EN);
	// SCK, MOSI, MISO pins config
	SPI1_PORT -> MODER |= (AFM << SPI1_MOSI_MODER) | (AFM << SPI1_MISO_MODER) | (AFM << SPI1_SCK_MODER);
	SPI1_PORT -> OSPEEDR |= (VH_SPEED << SPI1_MOSI_SP) | (VH_SPEED << SPI1_MISO_OP) | (VH_SPEED << SPI1_SCK_OP);
	SPI1_PORT -> IDR |= (1 << SPI1_MOSI) | (1 << SPI1_MISO) | (1 << SPI1_SCK);
	SPI1_PORT -> AFRL |= (SPIM_AF << SPI1_MOSI_AF) | (SPIM_AF << SPI1_MISO_AF) | (SPIM_AF << SPI1_SCK_AF);
	// SS pin config
	SPI_CS_PORT -> MODER |= (OUTPUT << SPI_CS_PIN * 2);
	SPI_CS_PORT -> OSPEEDR |= (VH_SPEED << SPI_CS_PIN * 2);
}


void SPI3_Config(void)
{
	/*
	 * The maximum SPI clock speed is 5MHz with 100pF maximum loading
	 * and the timing scheme follows clock polarity (CPOL = 1) and
	 * clock phase (CPHA = 1)
	 *
	 * APB2 Clock = 50Mhz => BR = F.PCLK/16 < 5MHz
	 * SPI config:
	 * MODE: Slaver full duplex
	 * Frame: 8bit | First bit: MSB bit
	 * SCK Mode: SPOL = 1 | SPHA = 1
	 * Hardware input slaver: PA15
	 */

	RCC -> APB1ENR |= (1 << SPI3_EN);
	SPI3 -> CR1 |= (DATA_FRAME_8_BIT << DFF) | (FULL_DUPLEX << RXONLY) | (0 << SSM) | (0 << SSI) | (MSB_FIRST << LSBFIRST);
	SPI3 -> CR1 |= (1 << SPICPOL) | (1 << SPICPHA);
	SPI3 -> CR1 |= (1 << SPE);

	RCC -> AHB1ENR |= (1 << SPI3_PORT_EN);
	// SCK, MOSI, MISO pins config
	SPI3_PORT -> MODER |= (AFM << SPI3_MOSI_MODER) | (AFM << SPI3_MISO_MODER) | (AFM << SPI3_SCK_MODER);
	SPI3_PORT -> OSPEEDR |= (VH_SPEED << SPI3_MOSI_SP) | (VH_SPEED << SPI3_MISO_OP) | (VH_SPEED << SPI3_SCK_OP);
	SPI3_PORT -> IDR |= (1 << SPI3_MOSI) | (1 << SPI3_MISO) | (1 << SPI3_SCK);
	SPI3_PORT -> AFRH |= (SPIS_AF << SPI3_MOSI_AF) | (SPIS_AF << SPI3_MISO_AF) | (SPIS_AF << SPI3_SCK_AF);
	//NSS pin config (Slaver Mode)
	RCC -> AHB1ENR |= (1 << GPIOA_EN);
	GPIOA -> MODER |= (AFM << MODER15);
	GPIOA -> OSPEEDR |= (VH_SPEED << OSPEEDR15);
	GPIOA -> OTYPER |= (OUTPUT_PP << OT15);
	GPIOA -> PUPDR |= (PUP_N_PP << PUPDR15);
	GPIOA -> IDR |= (0 << 15);
	GPIOA -> AFRH |= (SPIS_AF << AFRH15);
}
#endif /* SPI_H_ */

#ifdef I2C_H_
void I2C1_Config(void)
{
	/*
	 * Enable I2C clock
	 * Enable GPIO_I2C clock
	 * Configure the I2C PINs for Alternate Functions
	 * Reset I2C
	 * I2C Master mode:
		 * Program the peripheral input clock in I2C_CR2 register in order to generate correct timings
		 * Configure the clock control registers
		 * Configure the rise time register
		 * Program the I2C_CR1 register to enable the peripheral
		 * Set the START bit in the I2C_CR1 register to generate a Start condition
	 */
	RCC -> APB1ENR |= (1 << I2C1_EN);

	RCC -> AHB1ENR |= (1 << I2C1_PORT_EN);
	I2C1_PORT -> MODER |= (AFM << I2C1_SCL_MODER) | (AFM << I2C1_SDA_MODER);
	I2C1_PORT -> OTYPER |= (OUTPUT_OD << I2C1_SCL) | (OUTPUT_OD << I2C1_SDA);
	I2C1_PORT -> OSPEEDR |= (VH_SPEED << I2C1_SCL_H_SP) | (VH_SPEED << I2C1_SDA_H_SP);
	I2C1_PORT -> PUPDR |= (PUP_PU << I2C1_SCL_PUPDR) | (PUP_PU << I2C1_SDA_PUPDR);
	I2C1_PORT -> IDR |= (1 << I2C1_SCL) | (1 << I2C1_SDA);
	I2C1_PORT -> AFRL |= (I2C_AF << I2C1_SCL_AF) | (I2C_AF << I2C1_SDA_AF);

	I2C1 -> CR1 |= (1 << SWRST);
	I2C1 -> CR1 &= ~(1 << SWRST);

	I2C1 -> CR2 |= (HSE_Clock.APB1 << FREQ); // PLK1 FREQUENCY IN MHZ

	I2C1 -> OAR1 |= (1 << 14);
	I2C1 -> CCR |= (0 < F_S) | (0 << DUTY) | (0x7D << I2C_CCR);
	I2C1 -> TRISE = 0x1A;

	I2C1 -> CR1 |= (1 << ACK);
	I2C1 -> CR1 |= (1 << PE);
}
#endif /* I2C_H_*/


#endif /* STM32F407DEF_H_ */

#endif /* INC_STM32F407CONFIG_H_ */
