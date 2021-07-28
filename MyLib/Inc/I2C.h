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


I2C_State I2C_Start(I2C_TypeDef *I2Cx)
{
	uint32_t timeout = 100000;
	I2Cx -> CR1 |= (1 << ACK);
	I2Cx -> CR1 |= (1 << START);
	while(timeout)
	{
		if(!(I2Cx -> SR1 & (1 << SB)))timeout--;
		else
		{
			timeout = 0;
			return I2C_OK;
		}
	}
	return I2C_ERROR;
}
void I2C_Stop(I2C_TypeDef *I2Cx)
{
	I2Cx -> CR1 &= ~(1 << ACK);
	I2Cx -> CR1 |= (1 << STOP);
}


uint8_t I2C_Read(I2C_TypeDef *I2Cx)
{
	uint8_t data;
	while(!(I2Cx -> SR1 & (1 << RxNE)))
	{
		if((I2Cx -> SR1 & (1 << AF)))
		{
			I2C_Stop(I2Cx);
			break;
		}
	}
	data = I2Cx -> DR;
	return (data);
}
I2C_State I2C_AddressRequest(I2C_TypeDef *I2Cx, uint8_t devaddress, uint8_t memaddress)
{
	uint32_t timeout = 100000;

	if(I2C_Start(I2Cx) != I2C_OK)
	{
		return I2C_ERROR;
	}

	I2Cx -> DR = (devaddress << 1) + 0;

	//Wait ADDR Flag is set
	while(timeout)
	{
		if(!(I2Cx -> SR1 & (1 << ADDR)))timeout--;
		else
		{
			timeout = I2Cx -> SR1;
			timeout = I2Cx -> SR2;
			break;
		}
	}
	while(!(I2Cx -> SR1 & (1 << TxE)));
	I2Cx -> DR = memaddress;
	while(!(I2Cx -> SR1 & (1 << TxE)));
	return I2C_OK;
}
I2C_State I2C_AddressRead(I2C_TypeDef *I2Cx, uint8_t devaddress, uint8_t memaddress, uint8_t* data)
{
	uint32_t timeout = 100000;

	I2C_AddressRequest(I2Cx, devaddress, memaddress);

	if(I2C_Start(I2Cx) != I2C_OK)
	{
		return I2C_ERROR;
	}

	I2Cx -> DR = (devaddress << 1) + 1;

	//Wait ADDR Flag is set
	while(timeout)
	{
		if(!(I2Cx -> SR1 & (1 << ADDR)))timeout--;
		else
		{
			timeout = I2Cx -> SR1;
			timeout = I2Cx -> SR2;
			break;
		}
	}
	*data = I2C_Read(I2Cx);
	I2C_Stop(I2Cx);
	return I2C_OK;
}

void I2C_Write(I2C_TypeDef *I2Cx, uint8_t devaddress, uint8_t memaddress, uint8_t data)
{
	uint32_t timeout = 100000;
	I2C_AddressRequest(I2Cx, devaddress, memaddress);
	I2Cx -> DR = data;
	while(timeout--)
	{
		if(!(I2Cx -> SR1 & (1 << BTF))); // wait for BTF bit set
		else
		{
			break;
		}
	}
	I2C_Stop(I2Cx);
}

void I2C_Writes(I2C_TypeDef *I2Cx, uint8_t devaddress, uint8_t memaddress, uint8_t *data, uint8_t size)
{
	uint8_t index;
	uint32_t timeout = 100000;
	I2C_AddressRequest(I2Cx, devaddress, memaddress);
	for(index = 0; index < size;)
	{
		I2Cx -> DR = data[index];
		index++;
	}
	while(timeout--)
	{
		if(!(I2Cx -> SR1 & (1 << BTF))); // wait for BTF bit set
		else
		{
			break;
		}
	}
	I2C_Stop(I2Cx);
}

#endif /* I2C_H_ */
