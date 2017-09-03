################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/getting_started/src/main.c 

OBJS += \
./app/getting_started/src/main.o 

C_DEPS += \
./app/getting_started/src/main.d 


# Each subdirectory must supply rules for building sources it contributes
app/getting_started/src/%.o: ../app/getting_started/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


