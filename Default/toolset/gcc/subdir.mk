################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../toolset/gcc/startup_sam.c 

OBJS += \
./toolset/gcc/startup_sam.o 

C_DEPS += \
./toolset/gcc/startup_sam.d 


# Each subdirectory must supply rules for building sources it contributes
toolset/gcc/%.o: ../toolset/gcc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


