################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../os/FreeRTOS_821/Source/portable/MemMang/heap_1.c \
../os/FreeRTOS_821/Source/portable/MemMang/heap_2.c \
../os/FreeRTOS_821/Source/portable/MemMang/heap_3.c \
../os/FreeRTOS_821/Source/portable/MemMang/heap_4.c \
../os/FreeRTOS_821/Source/portable/MemMang/heap_5.c 

OBJS += \
./os/FreeRTOS_821/Source/portable/MemMang/heap_1.o \
./os/FreeRTOS_821/Source/portable/MemMang/heap_2.o \
./os/FreeRTOS_821/Source/portable/MemMang/heap_3.o \
./os/FreeRTOS_821/Source/portable/MemMang/heap_4.o \
./os/FreeRTOS_821/Source/portable/MemMang/heap_5.o 

C_DEPS += \
./os/FreeRTOS_821/Source/portable/MemMang/heap_1.d \
./os/FreeRTOS_821/Source/portable/MemMang/heap_2.d \
./os/FreeRTOS_821/Source/portable/MemMang/heap_3.d \
./os/FreeRTOS_821/Source/portable/MemMang/heap_4.d \
./os/FreeRTOS_821/Source/portable/MemMang/heap_5.d 


# Each subdirectory must supply rules for building sources it contributes
os/FreeRTOS_821/Source/portable/MemMang/%.o: ../os/FreeRTOS_821/Source/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


