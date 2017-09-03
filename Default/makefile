################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := del

# All of the sources participating in the build are defined here
-include sources.mk
-include toolset/gcc/subdir.mk
-include os/FreeRTOS_821/Source/portable/MemMang/subdir.mk
-include os/FreeRTOS_821/Source/portable/GCC/ARM_CM7/r0p1/subdir.mk
-include os/FreeRTOS_821/Source/portable/GCC/ARM_CM4F/subdir.mk
-include os/FreeRTOS_821/Source/subdir.mk
-include os/FreeRTOS_821/Demo/Common/Minimal/subdir.mk
-include os/FreeRTOS_821/Demo/Common/Full/subdir.mk
-include hal/utils/md5/subdir.mk
-include hal/libchip_samv7/source/subdir.mk
-include bsp/libboard_samv7-ek/source/subdir.mk
-include bsp/libboard_samv7-ek/resources/gcc/subdir.mk
-include bsp/libboard_samv7-ek/resources/subdir.mk
-include app/getting_started/src/Services/Watchdog\ Timer\ Control/subdir.mk
-include app/getting_started/src/Services/SysTick/subdir.mk
-include app/getting_started/src/Services/Scheduler/subdir.mk
-include app/getting_started/src/Services/Memory/subdir.mk
-include app/getting_started/src/ECU\ Abstraction/Serial\ control/subdir.mk
-include app/getting_started/src/ECU\ Abstraction/LED\ control/subdir.mk
-include app/getting_started/src/ECU\ Abstraction/subdir.mk
-include app/getting_started/src/subdir.mk
-include app/getting_started/SAMV71_Xplained_Ultra/Debug/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: 

# Tool invocations
: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++  -o  $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(C_DEPS)$(CPP_DEPS) 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
