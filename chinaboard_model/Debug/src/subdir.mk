################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/benchmark.c \
../src/rbuffer.c \
../src/stm32f10x_it.c \
../src/timer.c \
../src/usart.c 

S_UPPER_SRCS += \
../src/startup_stm32f10x_md.S 

OBJS += \
./src/benchmark.o \
./src/rbuffer.o \
./src/startup_stm32f10x_md.o \
./src/stm32f10x_it.o \
./src/timer.o \
./src/usart.o 

C_DEPS += \
./src/benchmark.d \
./src/rbuffer.d \
./src/stm32f10x_it.d \
./src/timer.d \
./src/usart.d 

S_UPPER_DEPS += \
./src/startup_stm32f10x_md.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Linux GCC C Compiler'
	arm-none-eabi-gcc -I../STM32F10x_StdPeriph_Driver/inc -I../CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../CMSIS/CM3/CoreSupport -I../inc -O3 -fshort-enums -ffunction-sections -fdata-sections -Wall -Wextra -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Linux GCC Assembler'
	arm-none-eabi-gcc -x assembler-with-cpp -I../STM32F10x_StdPeriph_Driver/inc -I../CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../inc -Wall -Wextra -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


