################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include STM32F10x_StdPeriph_Driver/src/subdir.mk
-include CMSIS/CM3/DeviceSupport/ST/STM32F10x/subdir.mk
-include CMSIS/CM3/CoreSupport/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
chinaboard_model.hex \

SECONDARY_LIST += \
chinaboard_model.lst \

SECONDARY_SIZE += \
chinaboard_model.siz \


# All Target
all: chinaboard_model.elf secondary-outputs

# Tool invocations
chinaboard_model.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Sourcery Linux GCC C Linker'
	arm-none-eabi-gcc -T"../device/linker/stm32f103xb_flash.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,chinaboard_model.map -mcpu=cortex-m3 -mthumb -o "chinaboard_model.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

chinaboard_model.hex: chinaboard_model.elf
	@echo 'Invoking: ARM Sourcery Linux GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex chinaboard_model.elf  "chinaboard_model.hex"
	@echo 'Finished building: $@'
	@echo ' '

chinaboard_model.lst: chinaboard_model.elf
	@echo 'Invoking: ARM Sourcery Linux GNU Create Listing'
	arm-none-eabi-objdump -h -S chinaboard_model.elf > "chinaboard_model.lst"
	@echo 'Finished building: $@'
	@echo ' '

chinaboard_model.siz: chinaboard_model.elf
	@echo 'Invoking: ARM Sourcery Linux GNU Print Size'
	arm-none-eabi-size  --format=berkeley chinaboard_model.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(EXECUTABLES)$(SECONDARY_LIST)$(S_UPPER_DEPS) chinaboard_model.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
