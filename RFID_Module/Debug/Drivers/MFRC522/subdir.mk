################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MFRC522/MFRC522.c 

OBJS += \
./Drivers/MFRC522/MFRC522.o 

C_DEPS += \
./Drivers/MFRC522/MFRC522.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MFRC522/MFRC522.o: ../Drivers/MFRC522/MFRC522.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Drivers/display -I../Drivers/MFRC522 -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/MFRC522/MFRC522.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

