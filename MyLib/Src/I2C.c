/*
 * I2C.c
 *
 *  Created on: Jul 12, 2021
 *      Author: tuang
 */


#include "I2C.h"

#ifdef STM32F407DEF_H_
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

	I2C1 -> CR2 |= (25 << FREQ); // PLK1 FREQUENCY IN MHZ

	I2C1 -> OAR1 |= (1 << 14);
	I2C1 -> CCR |= (0 < F_S) | (0 << DUTY) | (0x7D << I2C_CCR);
	I2C1 -> TRISE = 0x1A;

	I2C1 -> CR1 |= (1 << ACK);
	I2C1 -> CR1 |= (1 << PE);
}


I2C_State I2C1_Start(void)
{
	uint32_t timeout = 100000;
	I2C1 -> CR1 |= (1 << ACK);
	I2C1 -> CR1 |= (1 << START);
	while(timeout)
	{
		if(!(I2C1 -> SR1 & (1 << SB)))timeout--;
		else
		{
			timeout = 0;
			return I2C_OK;
		}
	}
	return I2C_ERROR;
}
void I2C1_Stop(void)
{
	I2C1 -> CR1 &= ~(1 << ACK);
	I2C1 -> CR1 |= (1 << STOP);
}


uint8_t I2C1_Read(void)
{
	uint8_t data;
	while(!(I2C1 -> SR1 & (1 << RxNE)))
	{
		if((I2C1 -> SR1 & (1 << AF)))
		{
			I2C1_Stop();
			break;
		}
	}
	data = I2C1 -> DR;
	return (data);
}
I2C_State I2C1_AddressRequest(uint8_t devaddress, uint8_t memaddress)
{
	uint32_t timeout = 100000;

	if(I2C1_Start() != I2C_OK)
	{
		return I2C_ERROR;
	}

	I2C1 -> DR = (devaddress << 1) + 0;

	//Wait ADDR Flag is set
	while(timeout)
	{
		if(!(I2C1 -> SR1 & (1 << ADDR)))timeout--;
		else
		{
			timeout = I2C1 -> SR1;
			timeout = I2C1 -> SR2;
			break;
		}
	}
	while(!(I2C1 -> SR1 & (1 << TxE)));
	I2C1 -> DR = memaddress;
	while(!(I2C1 -> SR1 & (1 << TxE)));
	return I2C_OK;
}
I2C_State I2C1_AddressRead(uint8_t devaddress, uint8_t memaddress, uint8_t* data)
{
	uint32_t timeout = 100000;

	I2C1_AddressRequest(devaddress, memaddress);

	if(I2C1_Start() != I2C_OK)
	{
		return I2C_ERROR;
	}

	I2C1 -> DR = (devaddress << 1) + 1;

	//Wait ADDR Flag is set
	while(timeout)
	{
		if(!(I2C1 -> SR1 & (1 << ADDR)))timeout--;
		else
		{
			timeout = I2C1 -> SR1;
			timeout = I2C1 -> SR2;
			break;
		}
	}
	*data = I2C1_Read();
	I2C1_Stop();
	return I2C_OK;
}

void I2C1_Write(uint8_t devaddress, uint8_t memaddress, uint8_t data)
{
	uint32_t timeout = 100000;
	I2C1_AddressRequest(devaddress, memaddress);
	I2C1 -> DR = data;
	while(timeout--)
	{
		if(!(I2C1 -> SR1 & (1 << BTF))); // wait for BTF bit set
		else
		{
			break;
		}
	}
	I2C1_Stop();
}

void I2C1_Writes(uint8_t devaddress, uint8_t memaddress, uint8_t *data, uint8_t size)
{
	uint8_t index;
	uint32_t timeout = 100000;
	I2C1_AddressRequest(devaddress, memaddress);
	for(index = 0; index < size;)
	{
		I2C1 -> DR = data[index];
		index++;
	}
	while(timeout--)
	{
		if(!(I2C1 -> SR1 & (1 << BTF))); // wait for BTF bit set
		else
		{
			break;
		}
	}
	I2C1_Stop();
}
#endif
