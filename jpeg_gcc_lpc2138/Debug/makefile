################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
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
dhrystone_gcc.hex \

SECONDARY_LIST += \
dhrystone_gcc.lst \

SECONDARY_SIZE += \
dhrystone_gcc.siz \


# All Target
all: dhrystone_gcc.elf secondary-outputs

# Tool invocations
dhrystone_gcc.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Sourcery Linux GCC C Linker'
	arm-none-eabi-gcc -T"../LPC2138-ROM.ld" -nostartfiles -Wl,-Map,dhrystone_gcc.map -mcpu=arm7tdmi-s -g3 -gdwarf-2 -o "dhrystone_gcc.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

dhrystone_gcc.hex: dhrystone_gcc.elf
	@echo 'Invoking: ARM Sourcery Linux GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex dhrystone_gcc.elf  "dhrystone_gcc.hex"
	@echo 'Finished building: $@'
	@echo ' '

dhrystone_gcc.lst: dhrystone_gcc.elf
	@echo 'Invoking: ARM Sourcery Linux GNU Create Listing'
	arm-none-eabi-objdump -h -S dhrystone_gcc.elf > "dhrystone_gcc.lst"
	@echo 'Finished building: $@'
	@echo ' '

dhrystone_gcc.siz: dhrystone_gcc.elf
	@echo 'Invoking: ARM Sourcery Linux GNU Print Size'
	arm-none-eabi-size  --format=berkeley dhrystone_gcc.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(EXECUTABLES)$(SECONDARY_LIST)$(S_UPPER_DEPS) dhrystone_gcc.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
