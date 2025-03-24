################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CustomDrivers/u8g2/u8g2_stm32.c 

C_DEPS += \
./CustomDrivers/u8g2/u8g2_stm32.d 

OBJS += \
./CustomDrivers/u8g2/u8g2_stm32.o 


# Each subdirectory must supply rules for building sources it contributes
CustomDrivers/u8g2/%.o CustomDrivers/u8g2/%.su CustomDrivers/u8g2/%.cyclo: ../CustomDrivers/u8g2/%.c CustomDrivers/u8g2/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2/csrc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CustomDrivers-2f-u8g2

clean-CustomDrivers-2f-u8g2:
	-$(RM) ./CustomDrivers/u8g2/u8g2_stm32.cyclo ./CustomDrivers/u8g2/u8g2_stm32.d ./CustomDrivers/u8g2/u8g2_stm32.o ./CustomDrivers/u8g2/u8g2_stm32.su

.PHONY: clean-CustomDrivers-2f-u8g2

