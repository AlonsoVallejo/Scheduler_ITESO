################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/getting_started/src/Services/SysTick/systick.c 

OBJS += \
./app/getting_started/src/Services/SysTick/systick.o 

C_DEPS += \
./app/getting_started/src/Services/SysTick/systick.d 


# Each subdirectory must supply rules for building sources it contributes
app/getting_started/src/Services/SysTick/%.o: ../app/getting_started/src/Services/SysTick/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


