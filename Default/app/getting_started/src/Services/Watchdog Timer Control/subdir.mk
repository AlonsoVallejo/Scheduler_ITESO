################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/getting_started/src/Services/Watchdog\ Timer\ Control/wdt_ctrl.c 

OBJS += \
./app/getting_started/src/Services/Watchdog\ Timer\ Control/wdt_ctrl.o 

C_DEPS += \
./app/getting_started/src/Services/Watchdog\ Timer\ Control/wdt_ctrl.d 


# Each subdirectory must supply rules for building sources it contributes
app/getting_started/src/Services/Watchdog\ Timer\ Control/wdt_ctrl.o: ../app/getting_started/src/Services/Watchdog\ Timer\ Control/wdt_ctrl.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"app/getting_started/src/Services/Watchdog Timer Control/wdt_ctrl.d" -MT"app/getting_started/src/Services/Watchdog\ Timer\ Control/wdt_ctrl.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


