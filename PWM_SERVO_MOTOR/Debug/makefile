################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
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
PWM_SERVO_MOTOR.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
PWM_SERVO_MOTOR.list \

OBJCOPY_BIN += \
PWM_SERVO_MOTOR.bin \


# All Target
all: PWM_SERVO_MOTOR.elf secondary-outputs

# Tool invocations
PWM_SERVO_MOTOR.elf: $(OBJS) $(USER_OBJS) C:\Users\MECHANIC\Desktop\ARM\PWM_SERVO_MOTOR\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "PWM_SERVO_MOTOR.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\MECHANIC\Desktop\ARM\PWM_SERVO_MOTOR\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="PWM_SERVO_MOTOR.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

PWM_SERVO_MOTOR.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "PWM_SERVO_MOTOR.list"
	@echo 'Finished building: $@'
	@echo ' '

PWM_SERVO_MOTOR.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "PWM_SERVO_MOTOR.bin"
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
