################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: OlimexBoard11C24.axf

# Tool invocations
OlimexBoard11C24.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Leonid Lezner\Documents\LPC11C24\lpc_chip_11cxx_lib\Debug" -Xlinker -Map="OlimexBoard11C24.map" -Xlinker --gc-sections -mcpu=cortex-m0 -mthumb -T "OlimexBoard11C24_Debug.ld" -o "OlimexBoard11C24.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) OlimexBoard11C24.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "OlimexBoard11C24.axf"; # arm-none-eabi-objcopy -v -O binary "OlimexBoard11C24.axf" "OlimexBoard11C24.bin" ; # checksum -p LPC11C24_301 -d "OlimexBoard11C24.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
