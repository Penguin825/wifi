################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/source/m2m_hif.c \
../driver/source/m2m_ota.c \
../driver/source/m2m_periph.c \
../driver/source/m2m_wifi.c \
../driver/source/nmasic.c \
../driver/source/nmbus.c \
../driver/source/nmdrv.c \
../driver/source/nmi2c.c \
../driver/source/nmspi.c \
../driver/source/nmuart.c 

OBJS += \
./driver/source/m2m_hif.o \
./driver/source/m2m_ota.o \
./driver/source/m2m_periph.o \
./driver/source/m2m_wifi.o \
./driver/source/nmasic.o \
./driver/source/nmbus.o \
./driver/source/nmdrv.o \
./driver/source/nmi2c.o \
./driver/source/nmspi.o \
./driver/source/nmuart.o 

C_DEPS += \
./driver/source/m2m_hif.d \
./driver/source/m2m_ota.d \
./driver/source/m2m_periph.d \
./driver/source/m2m_wifi.d \
./driver/source/nmasic.d \
./driver/source/nmbus.d \
./driver/source/nmdrv.d \
./driver/source/nmi2c.d \
./driver/source/nmspi.d \
./driver/source/nmuart.d 


# Each subdirectory must supply rules for building sources it contributes
driver/source/%.o: ../driver/source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Inc" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/CMSIS/Include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/bsp/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/driver/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/bus_wrapper/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/common/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/config" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/socket/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/spi_flash" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/CMSIS/DSP_Lib/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


