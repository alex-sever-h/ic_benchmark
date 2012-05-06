################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/CM3/CoreSupport/core_cm3.c 

OBJS += \
./CMSIS/CM3/CoreSupport/core_cm3.o 

C_DEPS += \
./CMSIS/CM3/CoreSupport/core_cm3.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/CM3/CoreSupport/%.o: ../CMSIS/CM3/CoreSupport/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Linux GCC C Compiler'
	arm-none-eabi-gcc -I../STM32F10x_StdPeriph_Driver/inc -I../CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../CMSIS/CM3/CoreSupport -I../inc -O3 -fshort-enums -ffunction-sections -fdata-sections -Wall -Wextra -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


