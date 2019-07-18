################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP_Lib/Source/CommonTables/arm_common_tables.c \
../Drivers/CMSIS/DSP_Lib/Source/CommonTables/arm_const_structs.c 

OBJS += \
./Drivers/CMSIS/DSP_Lib/Source/CommonTables/arm_common_tables.o \
./Drivers/CMSIS/DSP_Lib/Source/CommonTables/arm_const_structs.o 

C_DEPS += \
./Drivers/CMSIS/DSP_Lib/Source/CommonTables/arm_common_tables.d \
./Drivers/CMSIS/DSP_Lib/Source/CommonTables/arm_const_structs.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP_Lib/Source/CommonTables/%.o: ../Drivers/CMSIS/DSP_Lib/Source/CommonTables/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Inc" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/CMSIS/Include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/bsp/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/driver/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/bus_wrapper/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/common/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/config" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/socket/include" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/spi_flash" -I"C:/Users/Aric/Documents/STM32F7xWINC1500/Drivers/CMSIS/DSP_Lib/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


