/*
 * I2C.h
 *
 *  Created on: Jul 12, 2021
 *      Author: tuang
 */

#ifndef I2C_H_
#define I2C_H_

#include "GPIO.h"

#ifdef STM32F407DEF_H_
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
#endif

#define I2C_WRITE		0
#define I2C_READ		1

typedef enum
{
	I2C_OK,
	I2C_ERROR
}I2C_State;



void I2C1_Config(void);
I2C_State I2C1_Start(void);
I2C_State I2C1_AddressRequest(uint8_t devaddress, uint8_t memaddress);
void I2C1_Writes(uint8_t devaddress, uint8_t memaddress, uint8_t *data, uint8_t size);
void I2C1_Write(uint8_t devaddress, uint8_t memaddress, uint8_t data);
I2C_State I2C1_AddressRead(uint8_t devaddress, uint8_t memaddress, uint8_t* data);
void I2C1_Stop(void);

#endif /* I2C_H_ */
