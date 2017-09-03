################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../os/FreeRTOS_821/Source/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./os/FreeRTOS_821/Source/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./os/FreeRTOS_821/Source/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
os/FreeRTOS_821/Source/portable/GCC/ARM_CM4F/%.o: ../os/FreeRTOS_821/Source/portable/GCC/ARM_CM4F/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


