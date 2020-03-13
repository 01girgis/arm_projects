################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/ringbuffer_dma/subdir.mk
-include Drivers/display/Fonts/subdir.mk
-include Drivers/display/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Drivers/BMP280/subdir.mk
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
STM_ESP8266_http_server.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM_ESP8266_http_server.list \

OBJCOPY_BIN += \
STM_ESP8266_http_server.bin \


# All Target
all: STM_ESP8266_http_server.elf secondary-outputs

# Tool invocations
STM_ESP8266_http_server.elf: $(OBJS) $(USER_OBJS) C:\Users\MECHANIC\Desktop\ARM\STM_ESP8266_http_server\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "STM_ESP8266_http_server.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\MECHANIC\Desktop\ARM\STM_ESP8266_http_server\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM_ESP8266_http_server.map" -Wl,--gc-sections -static -u _printf_float --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM_ESP8266_http_server.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM_ESP8266_http_server.list"
	@echo 'Finished building: $@'
	@echo ' '

STM_ESP8266_http_server.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM_ESP8266_http_server.bin"
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
