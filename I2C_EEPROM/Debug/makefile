################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/display/Fonts/subdir.mk
-include Drivers/display/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
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
I2C_EEPROM.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
I2C_EEPROM.list \

OBJCOPY_BIN += \
I2C_EEPROM.bin \


# All Target
all: I2C_EEPROM.elf secondary-outputs

# Tool invocations
I2C_EEPROM.elf: $(OBJS) $(USER_OBJS) C:\Users\MECHANIC\Desktop\ARM\I2C_EEPROM\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "I2C_EEPROM.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\MECHANIC\Desktop\ARM\I2C_EEPROM\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="I2C_EEPROM.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

I2C_EEPROM.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "I2C_EEPROM.list"
	@echo 'Finished building: $@'
	@echo ' '

I2C_EEPROM.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "I2C_EEPROM.bin"
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
