################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../os/FreeRTOS_821/Source/croutine.c \
../os/FreeRTOS_821/Source/event_groups.c \
../os/FreeRTOS_821/Source/list.c \
../os/FreeRTOS_821/Source/queue.c \
../os/FreeRTOS_821/Source/tasks.c \
../os/FreeRTOS_821/Source/timers.c 

OBJS += \
./os/FreeRTOS_821/Source/croutine.o \
./os/FreeRTOS_821/Source/event_groups.o \
./os/FreeRTOS_821/Source/list.o \
./os/FreeRTOS_821/Source/queue.o \
./os/FreeRTOS_821/Source/tasks.o \
./os/FreeRTOS_821/Source/timers.o 

C_DEPS += \
./os/FreeRTOS_821/Source/croutine.d \
./os/FreeRTOS_821/Source/event_groups.d \
./os/FreeRTOS_821/Source/list.d \
./os/FreeRTOS_821/Source/queue.d \
./os/FreeRTOS_821/Source/tasks.d \
./os/FreeRTOS_821/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
os/FreeRTOS_821/Source/%.o: ../os/FreeRTOS_821/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


