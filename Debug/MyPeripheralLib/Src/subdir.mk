################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MyPeripheralLib/Src/DS3231.c 

OBJS += \
./MyPeripheralLib/Src/DS3231.o 

C_DEPS += \
./MyPeripheralLib/Src/DS3231.d 


# Each subdirectory must supply rules for building sources it contributes
MyPeripheralLib/Src/DS3231.o: ../MyPeripheralLib/Src/DS3231.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyPeripheralLib/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MyPeripheralLib/Src/DS3231.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

