################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/ringbuffer/ringbuffer.c 

OBJS += \
./Drivers/ringbuffer/ringbuffer.o 

C_DEPS += \
./Drivers/ringbuffer/ringbuffer.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ringbuffer/ringbuffer.o: ../Drivers/ringbuffer/ringbuffer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../USB_DEVICE/Target -I../Drivers/ringbuffer -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../USB_DEVICE/App -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/ringbuffer/ringbuffer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

