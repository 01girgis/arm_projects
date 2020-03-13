################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/display/Fonts/subdir.mk
-include Drivers/display/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
MechnaicalEncoder_With_Timer.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
MechnaicalEncoder_With_Timer.list \

OBJCOPY_BIN += \
MechnaicalEncoder_With_Timer.bin \


# All Target
all: MechnaicalEncoder_With_Timer.elf secondary-outputs

# Tool invocations
MechnaicalEncoder_With_Timer.elf: $(OBJS) $(USER_OBJS) C:\Users\MECHANIC\Desktop\ARM\MechnaicalEncoder_With_Timer\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "MechnaicalEncoder_With_Timer.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\MECHANIC\Desktop\ARM\MechnaicalEncoder_With_Timer\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="MechnaicalEncoder_With_Timer.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

MechnaicalEncoder_With_Timer.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "MechnaicalEncoder_With_Timer.list"
	@echo 'Finished building: $@'
	@echo ' '

MechnaicalEncoder_With_Timer.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "MechnaicalEncoder_With_Timer.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
