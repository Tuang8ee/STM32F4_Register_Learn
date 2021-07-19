################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include MyPeripheralLib/Src/subdir.mk
-include MyLib/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32F4_Register_Learn.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32F4_Register_Learn.list \

OBJCOPY_BIN += \
STM32F4_Register_Learn.bin \


# All Target
all: STM32F4_Register_Learn.elf secondary-outputs

# Tool invocations
STM32F4_Register_Learn.elf: $(OBJS) $(USER_OBJS) F:\Projects\Projects\Work\Work\Learn\STM32_VHEC_Training\STM32F4_Register_Learn\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "STM32F4_Register_Learn.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"F:\Projects\Projects\Work\Work\Learn\STM32_VHEC_Training\STM32F4_Register_Learn\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32F4_Register_Learn.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32F4_Register_Learn.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32F4_Register_Learn.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32F4_Register_Learn.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32F4_Register_Learn.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
