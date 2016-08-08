################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/dma.c \
/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/gpio.c \
/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/i2c.c \
../Application/User/leds_handler.c \
/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/main.c \
/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/stm32f4xx_hal_msp.c \
/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/stm32f4xx_it.c \
/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/tim.c \
/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/usart.c 

OBJS += \
./Application/User/dma.o \
./Application/User/gpio.o \
./Application/User/i2c.o \
./Application/User/leds_handler.o \
./Application/User/main.o \
./Application/User/stm32f4xx_hal_msp.o \
./Application/User/stm32f4xx_it.o \
./Application/User/tim.o \
./Application/User/usart.o 

C_DEPS += \
./Application/User/dma.d \
./Application/User/gpio.d \
./Application/User/i2c.d \
./Application/User/leds_handler.d \
./Application/User/main.d \
./Application/User/stm32f4xx_hal_msp.d \
./Application/User/stm32f4xx_it.d \
./Application/User/tim.d \
./Application/User/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/dma.o: /home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/dma.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Include" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/gpio.o: /home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Include" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/i2c.o: /home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Include" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/%.o: ../Application/User/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Include" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/main.o: /home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Include" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_hal_msp.o: /home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Include" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_it.o: /home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/stm32f4xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Include" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/tim.o: /home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/tim.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Include" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/usart.o: /home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Src/usart.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Include" -I"/home/myzhar/devel/RoboSec/Firmware/rs_sensor_board/FW-rs_sensor_board/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


