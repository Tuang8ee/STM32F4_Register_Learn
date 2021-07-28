/*
 * stm32f407def.h
 *
 *  Created on: Jul 9, 2021
 *      Author: tuang
 */
#include "stm32f407xx.h"
#include "stdint.h"

#ifndef STM32F407DEF_H_
#define STM32F407DEF_H_

#define FindString(src, dic)		strstr((const char*)src, (const char*)dic)
#define Section	__attribute__((section(".sec.")))

#define HIGH	1
#define LOW		0

#define LED3_Port	GPIOD
#define LED3_Pin	13
#define LED4_Port	GPIOD
#define LED4_Pin	12
#define LED5_Port	GPIOD
#define LED5_Pin	14
#define LED6_Port	GPIOD
#define LED6_Pin	15
#define BTN_Port	GPIOA
#define BTN_Pin		0

// SysTick clock source selection
#define AHB_DIV_8	0
#define AHB_DIV_1	1

// SysTick control and status register (STK_CTRL)
#define ENABLE		0
#define TICKINT		1
#define CLKSOURCE	2
#define COUNTFLAG	16

// SysTick calibration value register (STK_CALIB)
#define TENMS		0
#define SKEW		30
#define NOREF		31

// RCC APB1 peripheral clock enable register (RCC_APB1ENR)
#define TIM2_EN		0
#define TIM3_EN		1
#define TIM4_EN		2
#define TIM5_EN		3
#define TIM6_EN		4
#define TIM7_EN		5
#define TIM12_EN	6
#define TIM13_EN	7
#define TIM14_EN	8
#define WWDG_EN		11
#define SPI2_EN		14
#define SPI3_EN		15
#define UART2_EN	17
#define UART3_EN	18
#define UART4_EN	19
#define UART5_EN	20
#define I2C1_EN		21
#define I2C2_EN		22
#define I2C3_EN		23
#define CAN1_EN		25
#define CAN2_EN		26
#define PWR_EN		28
#define DAC_EN		29
#define UART7_EN	30
#define UART8_EN	31

// RCC APB2 peripheral clock enable register (RCC_APB2ENR)
#define TIM1_EN		0
#define TIM8_EN		1
#define UART1_EN	4
#define UART6_EN	5
#define ADC1_EN		8
#define ADC2_EN		9
#define ADC3_EN		10
#define SDIO_EN		11
#define SPI1_EN		12
#define SPI4_EN		13
#define SYSCFG_EN	14
#define TIM9_EN		16
#define TIM10_EN	17
#define TIM11_EN	18
#define SPI5_EN		20
#define SPI6_EN		21
#define SAI1_EN		22
#define LTDC_EN		26

// RCC_AHB1 peripheral clock register
#define GPIOA_EN	0
#define GPIOB_EN	1
#define GPIOC_EN	2
#define GPIOD_EN	3
#define GPIOE_EN	4
#define GPIOF_EN	5
#define GPIOG_EN	6
#define GPIOH_EN	7
#define GPIOI_EN	8
#define GPIOJ_EN	9
#define GPIOK_EN	10
#define CRC_EN		12
#define BKPSRAM_EN	19
#define CCMDATARAM_EN	20

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

	// GPIO port output type register
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

	// TIM6 & TIM7 control register 1
	#define CEN			0
	#define UDIS		1
	#define OPM			3
	#define ARPE		7

	// TIM6 & TIM7 status register
	#define UIF			0

	// TIM6 & TIM7 DMA/Interrupt enable register
	#define UIE	0
	#define UDE	8

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
	#define ADC_DMA		8
	#define ADC_DDS		9
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

	// USART Control register 1
	#define SBK 		0
	#define RWu			1
	#define RE			2
	#define TE			3
	#define IDLEIE		4
	#define RXNEIE		5
	#define TCIE		6
	#define TXEIE 		7
	#define PEIE		8
	#define PS			9
	#define PCE			10
	#define WAKE		11
	#define M			12
	#define UE			13
	#define OVER8		15

	// Value off M bit in USART Control register 1
	#define DATA_BIT_8	0
	#define DATA_BIT_9	1

	// USART Control register 2
	#define ADD			0
	#define LBDL		5
	#define LBDIE		6
	#define LBCL		8
	#define CPHA		9
	#define CPOL		10
	#define CLKEN		11
	#define UART_STOP	12
	#define LINEN		14

	// Value off STOP bit in USART Control register 2
	#define STOP_BIT_1		0
	#define STOP_BIT_0_5	1
	#define STOP_BIT_2		2
	#define STOP_BIT_1_5	3

	// USART Status register
	#define PE		0
	#define FE		1
	#define NF		2
	#define ORE		3
	#define IDLE	4
	#define RXNE	5
	#define TC		6
	#define TXE		7
	#define LBD		8
	#define CTS		9


	// I2C PINs define
	#define I2C_AF			AF4

	#define I2C1_PORT		GPIOB
	#define I2C1_PORT_EN	GPIOB_EN
	#define I2C1_SDA		7
	#define I2C1_SCL		6
	#define I2C1_SCL_H_SP	OSPEEDR6
	#define I2C1_SDA_H_SP	OSPEEDR7
	#define I2C1_SCL_MODER	MODER6
	#define I2C1_SDA_MODER	MODER7

	#define I2C1_SCL_AF		AFRL6
	#define I2C1_SDA_AF		AFRL7
	#define I2C1_SCL_PUPDR	PUPDR6
	#define I2C1_SDA_PUPDR	PUPDR7

	// I2C Control register 1 (I2C_CR1)
	#define PE			0
	#define SMBUS		1
	#define SMBTYPE		3
	#define ENARP		4
	#define ENPEC		5
	#define ENGC		6
	#define NOSTRETCH	7
	#define START		8
	#define STOP		9
	#define ACK			10
	#define POS			11
	#define PEC			12
	#define ALERT		13
	#define SWRST		15

	// I2C Control register 2 (I2C_CR2)
	#define FREQ	0
	#define ITERREN	8
	#define ITEVTEN	9
	#define ITBUFEN 10
	#define DMAEN	11
	#define LAST	12

	// F_S value
	#define Fm		1
	#define Sm		0
	// I2C Clock control register (I2C_CCR)
	#define I2C_CCR	0
	#define DUTY	14
	#define F_S		15

	// I2C Status register 1
	#define SB			0
	#define ADDR		1
	#define BTF			2
	#define ADD10		3
	#define STOPF		4
	#define RxNE		6
	#define TxE			7
	#define BERR		8
	#define ARLO    	9
	#define AF			10
	#define OVR			11
	#define PECERR		12
	#define TIMEOUT		14
	#define SMBALERT	15


	#define SPIM_AF			AF5
	#define SPIS_AF			AF6
	// SPI1 PINs define
	#define SPI_CS_PORT		GPIOA
	#define SPI_CS_PIN		4

	#define SPI1_PORT		GPIOA
	#define SPI1_PORT_EN	GPIOA_EN
	#define SPI1_SCK		5
	#define SPI1_MISO		6
	#define SPI1_MOSI		7

	#define SPI1_SCK_OP		OSPEEDR5
	#define SPI1_MISO_OP	OSPEEDR6
	#define SPI1_MOSI_SP	OSPEEDR7
	#define SPI1_SCK_MODER	MODER5
	#define SPI1_MISO_MODER	MODER6
	#define SPI1_MOSI_MODER	MODER7
	#define SPI1_SCK_AF		AFRL5
	#define SPI1_MISO_AF	AFRL6
	#define SPI1_MOSI_AF	AFRL7
	#define SPI1_SCK_PUPDR	PUPDR5
	#define SPI1_MISO_PUPDR	PUPDR6
	#define SPI1_MOSI_PUPDR	PUPDR7

	// SPI2 PINs define
//	#define SPI3_CS_PORT	GPIOA
//	#define SPI3_CS_PIN		4

	#define SPI3_PORT		GPIOC
	#define SPI3_PORT_EN	GPIOC_EN
	#define SPI3_SCK		10
	#define SPI3_MISO		11
	#define SPI3_MOSI		12

	#define SPI3_SCK_OP		OSPEEDR10
	#define SPI3_MISO_OP	OSPEEDR11
	#define SPI3_MOSI_SP	OSPEEDR12
	#define SPI3_SCK_MODER	MODER10
	#define SPI3_MISO_MODER	MODER11
	#define SPI3_MOSI_MODER	MODER12

	#define SPI3_SCK_AF		AFRH10
	#define SPI3_MISO_AF	AFRH11
	#define SPI3_MOSI_AF	AFRH12
	#define SPI3_SCK_PUPDR	PUPDR10
	#define SPI3_MISO_PUPDR	PUPDR11
	#define SPI3_MOSI_PUPDR	PUPDR12

	// Data frame format
	#define DATA_FRAME_8_BIT	0
	#define DATA_FRAME_16_BIT	1
	// Master selection
	#define SLAVER_CONFIG	0
	#define MASTER_CONFIG	1
	// Baud rate control
	#define PCLK_DIV_2		0
	#define PCLK_DIV_4		1
	#define PCLK_DIV_8		2
	#define PCLK_DIV_16		3
	#define PCLK_DIV_32		4
	#define PCLK_DIV_64		5
	#define PCLK_DIV_128	6
	#define PCLK_DIV_256	7
	// Frame format
	#define MSB_FIRST	0
	#define LSB_FIRST	1
	// Receive only
	#define FULL_DUPLEX		0
	#define RECEIVE_ONLY	1

	/* SPI control register 1 (SPI_CR1) */
	#define SPICPHA		0
	#define SPICPOL		1
	#define MSTR		2
	#define BR			3
	#define SPE			6
	#define LSBFIRST 	7
	#define SSI			8
	#define SSM			9
	#define RXONLY		10
	#define DFF			11
	#define CRCNEXT		12
	#define CRCEN		13
	#define BIDIOE		14
	#define BIDIMODE	15

	/* SPI control register 2 */
	#define RXDMAEN		0
	#define TXDMAEN		1
	#define SSOE		2
	#define FRF			4
	#define ERRIE		5
	#define SPIRXNEIE		6
	#define SPITXEIE		7

	/* SPI status register (SPI_SR)*/
	#define SPIRXNE		0
	#define SPITXE		1
	#define CHSIDE 		2
	#define UDR			3
	#define CRCERR		4
	#define MODF		5
	#define OVR_SPI		6
	#define BSY			7
	#define FRE			8
#endif /* STM32F407DEF_H_ */
