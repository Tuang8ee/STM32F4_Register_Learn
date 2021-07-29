################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MyLib/Inc/Peripheral/Src/ADC.c \
../MyLib/Inc/Peripheral/Src/GPIO.c \
../MyLib/Inc/Peripheral/Src/I2C.c \
../MyLib/Inc/Peripheral/Src/SPI.c \
../MyLib/Inc/Peripheral/Src/UART.c \
../MyLib/Inc/Peripheral/Src/timer.c 

OBJS += \
./MyLib/Inc/Peripheral/Src/ADC.o \
./MyLib/Inc/Peripheral/Src/GPIO.o \
./MyLib/Inc/Peripheral/Src/I2C.o \
./MyLib/Inc/Peripheral/Src/SPI.o \
./MyLib/Inc/Peripheral/Src/UART.o \
./MyLib/Inc/Peripheral/Src/timer.o 

C_DEPS += \
./MyLib/Inc/Peripheral/Src/ADC.d \
./MyLib/Inc/Peripheral/Src/GPIO.d \
./MyLib/Inc/Peripheral/Src/I2C.d \
./MyLib/Inc/Peripheral/Src/SPI.d \
./MyLib/Inc/Peripheral/Src/UART.d \
./MyLib/Inc/Peripheral/Src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
MyLib/Inc/Peripheral/Src/ADC.o: ../MyLib/Inc/Peripheral/Src/ADC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/MyPeripheralLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc/Peripheral/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MyLib/Inc/Peripheral/Src/ADC.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
MyLib/Inc/Peripheral/Src/GPIO.o: ../MyLib/Inc/Peripheral/Src/GPIO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/MyPeripheralLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc/Peripheral/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MyLib/Inc/Peripheral/Src/GPIO.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
MyLib/Inc/Peripheral/Src/I2C.o: ../MyLib/Inc/Peripheral/Src/I2C.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/MyPeripheralLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc/Peripheral/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MyLib/Inc/Peripheral/Src/I2C.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
MyLib/Inc/Peripheral/Src/SPI.o: ../MyLib/Inc/Peripheral/Src/SPI.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/MyPeripheralLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc/Peripheral/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MyLib/Inc/Peripheral/Src/SPI.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
MyLib/Inc/Peripheral/Src/UART.o: ../MyLib/Inc/Peripheral/Src/UART.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/MyPeripheralLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc/Peripheral/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MyLib/Inc/Peripheral/Src/UART.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
MyLib/Inc/Peripheral/Src/timer.o: ../MyLib/Inc/Peripheral/Src/timer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/Drivers/CMSIS/Include" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/MyPeripheralLib/Inc" -I"F:/Projects/Projects/Work/Work/Learn/STM32_VHEC_Training/STM32F4_Register_Learn/MyLib/Inc/Peripheral/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MyLib/Inc/Peripheral/Src/timer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

