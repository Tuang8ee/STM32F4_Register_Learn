/*
 * I2C.h
 *
 *  Created on: Jul 12, 2021
 *      Author: tuang
 */

#ifndef I2C_H_
#define I2C_H_

#ifndef GPIO_H_
	#include "GPIO.h"
#endif

#define I2C_WRITE		0
#define I2C_READ		1


typedef enum
{
	I2C_OK,
	I2C_ERROR
}I2C_State;


I2C_State I2C_Start(I2C_TypeDef *I2Cx);

void I2C_Stop(I2C_TypeDef *I2Cx);

uint8_t I2C_Read(I2C_TypeDef *I2Cx);

I2C_State I2C_AddressRequest(I2C_TypeDef *I2Cx, uint8_t devaddress, uint8_t memaddress);

I2C_State I2C_AddressRead(I2C_TypeDef *I2Cx, uint8_t devaddress, uint8_t memaddress, uint8_t* data);

void I2C_Write(I2C_TypeDef *I2Cx, uint8_t devaddress, uint8_t memaddress, uint8_t data);

void I2C_Writes(I2C_TypeDef *I2Cx, uint8_t devaddress, uint8_t memaddress, uint8_t *data, uint8_t size);

#endif /* I2C_H_ */
