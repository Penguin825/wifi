################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/stm32f7xx_hal_msp.c \
../Src/stm32f7xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f7xx.c 

OBJS += \
./Src/main.o \
./Src/stm32f7xx_hal_msp.o \
./Src/stm32f7xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f7xx.o 

C_DEPS += \
./Src/main.d \
./Src/stm32f7xx_hal_msp.d \
./Src/stm32f7xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f7xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Inc" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/CMSIS/Include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/bsp/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/driver/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/bus_wrapper/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/common/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/config" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/socket/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/spi_flash" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/CMSIS/DSP_Lib/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


