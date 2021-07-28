################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MyLib/Src/Interrupts.c 

OBJS += \
./MyLib/Src/Interrupts.o 

C_DEPS += \
./MyLib/Src/Interrupts.d 


# Each subdirectory must supply rules for building sources it contributes
MyLib/Src/Interrupts.o: ../MyLib/Src/Interrupts.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/MyPeripheralLib/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MyLib/Src/Interrupts.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

