################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/getting_started/src/Services/Scheduler/app_scheduler.c \
../app/getting_started/src/Services/Scheduler/app_tasks.c 

OBJS += \
./app/getting_started/src/Services/Scheduler/app_scheduler.o \
./app/getting_started/src/Services/Scheduler/app_tasks.o 

C_DEPS += \
./app/getting_started/src/Services/Scheduler/app_scheduler.d \
./app/getting_started/src/Services/Scheduler/app_tasks.d 


# Each subdirectory must supply rules for building sources it contributes
app/getting_started/src/Services/Scheduler/%.o: ../app/getting_started/src/Services/Scheduler/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


