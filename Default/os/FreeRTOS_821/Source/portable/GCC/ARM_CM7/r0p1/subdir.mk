################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../os/FreeRTOS_821/Source/portable/GCC/ARM_CM7/r0p1/port.c 

OBJS += \
./os/FreeRTOS_821/Source/portable/GCC/ARM_CM7/r0p1/port.o 

C_DEPS += \
./os/FreeRTOS_821/Source/portable/GCC/ARM_CM7/r0p1/port.d 


# Each subdirectory must supply rules for building sources it contributes
os/FreeRTOS_821/Source/portable/GCC/ARM_CM7/r0p1/%.o: ../os/FreeRTOS_821/Source/portable/GCC/ARM_CM7/r0p1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


