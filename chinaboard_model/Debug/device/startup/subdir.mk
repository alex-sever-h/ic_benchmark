################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/startup/crt.c \
../device/startup/vectors_stm32f10x_md.c 

OBJS += \
./device/startup/crt.o \
./device/startup/vectors_stm32f10x_md.o 

C_DEPS += \
./device/startup/crt.d \
./device/startup/vectors_stm32f10x_md.d 


# Each subdirectory must supply rules for building sources it contributes
device/startup/%.o: ../device/startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Linux GCC C Compiler'
	arm-none-eabi-gcc -I../STM32F10x_StdPeriph_Driver/inc -I../CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../CMSIS/CM3/CoreSupport -I../inc -O3 -fshort-enums -ffunction-sections -fdata-sections -Wall -Wextra -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


