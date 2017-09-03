################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/utils/md5/md5.c 

OBJS += \
./hal/utils/md5/md5.o 

C_DEPS += \
./hal/utils/md5/md5.d 


# Each subdirectory must supply rules for building sources it contributes
hal/utils/md5/%.o: ../hal/utils/md5/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


