################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/ringbuffer_dma/subdir.mk
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
BLUETOOTH_CONTROL_LEDS.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
BLUETOOTH_CONTROL_LEDS.list \

OBJCOPY_BIN += \
BLUETOOTH_CONTROL_LEDS.bin \


# All Target
all: BLUETOOTH_CONTROL_LEDS.elf secondary-outputs

# Tool invocations
BLUETOOTH_CONTROL_LEDS.elf: $(OBJS) $(USER_OBJS) C:\Users\MECHANIC\Desktop\ARM\BLUETOOTH_CONTROL_LEDS\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "BLUETOOTH_CONTROL_LEDS.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\MECHANIC\Desktop\ARM\BLUETOOTH_CONTROL_LEDS\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="BLUETOOTH_CONTROL_LEDS.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

BLUETOOTH_CONTROL_LEDS.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "BLUETOOTH_CONTROL_LEDS.list"
	@echo 'Finished building: $@'
	@echo ' '

BLUETOOTH_CONTROL_LEDS.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "BLUETOOTH_CONTROL_LEDS.bin"
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
