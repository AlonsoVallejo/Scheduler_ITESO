################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../os/FreeRTOS_821/Demo/Common/Full/BlockQ.c \
../os/FreeRTOS_821/Demo/Common/Full/PollQ.c \
../os/FreeRTOS_821/Demo/Common/Full/comtest.c \
../os/FreeRTOS_821/Demo/Common/Full/death.c \
../os/FreeRTOS_821/Demo/Common/Full/dynamic.c \
../os/FreeRTOS_821/Demo/Common/Full/events.c \
../os/FreeRTOS_821/Demo/Common/Full/flash.c \
../os/FreeRTOS_821/Demo/Common/Full/flop.c \
../os/FreeRTOS_821/Demo/Common/Full/integer.c \
../os/FreeRTOS_821/Demo/Common/Full/print.c \
../os/FreeRTOS_821/Demo/Common/Full/semtest.c 

OBJS += \
./os/FreeRTOS_821/Demo/Common/Full/BlockQ.o \
./os/FreeRTOS_821/Demo/Common/Full/PollQ.o \
./os/FreeRTOS_821/Demo/Common/Full/comtest.o \
./os/FreeRTOS_821/Demo/Common/Full/death.o \
./os/FreeRTOS_821/Demo/Common/Full/dynamic.o \
./os/FreeRTOS_821/Demo/Common/Full/events.o \
./os/FreeRTOS_821/Demo/Common/Full/flash.o \
./os/FreeRTOS_821/Demo/Common/Full/flop.o \
./os/FreeRTOS_821/Demo/Common/Full/integer.o \
./os/FreeRTOS_821/Demo/Common/Full/print.o \
./os/FreeRTOS_821/Demo/Common/Full/semtest.o 

C_DEPS += \
./os/FreeRTOS_821/Demo/Common/Full/BlockQ.d \
./os/FreeRTOS_821/Demo/Common/Full/PollQ.d \
./os/FreeRTOS_821/Demo/Common/Full/comtest.d \
./os/FreeRTOS_821/Demo/Common/Full/death.d \
./os/FreeRTOS_821/Demo/Common/Full/dynamic.d \
./os/FreeRTOS_821/Demo/Common/Full/events.d \
./os/FreeRTOS_821/Demo/Common/Full/flash.d \
./os/FreeRTOS_821/Demo/Common/Full/flop.d \
./os/FreeRTOS_821/Demo/Common/Full/integer.d \
./os/FreeRTOS_821/Demo/Common/Full/print.d \
./os/FreeRTOS_821/Demo/Common/Full/semtest.d 


# Each subdirectory must supply rules for building sources it contributes
os/FreeRTOS_821/Demo/Common/Full/%.o: ../os/FreeRTOS_821/Demo/Common/Full/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


