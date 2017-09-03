################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/getting_started/src/Services/Memory/cnf_mem_alloc.c \
../app/getting_started/src/Services/Memory/memory_allocation.c 

OBJS += \
./app/getting_started/src/Services/Memory/cnf_mem_alloc.o \
./app/getting_started/src/Services/Memory/memory_allocation.o 

C_DEPS += \
./app/getting_started/src/Services/Memory/cnf_mem_alloc.d \
./app/getting_started/src/Services/Memory/memory_allocation.d 


# Each subdirectory must supply rules for building sources it contributes
app/getting_started/src/Services/Memory/%.o: ../app/getting_started/src/Services/Memory/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


