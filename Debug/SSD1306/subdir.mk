################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SSD1306/ssd1306.c \
../SSD1306/ssd1306_fonts.c \
../SSD1306/ssd1306_tests.c 

C_DEPS += \
./SSD1306/ssd1306.d \
./SSD1306/ssd1306_fonts.d \
./SSD1306/ssd1306_tests.d 

OBJS += \
./SSD1306/ssd1306.o \
./SSD1306/ssd1306_fonts.o \
./SSD1306/ssd1306_tests.o 


# Each subdirectory must supply rules for building sources it contributes
SSD1306/%.o SSD1306/%.su SSD1306/%.cyclo: ../SSD1306/%.c SSD1306/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/Controller" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2/csrc" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2/cppsrc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/Model" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SSD1306

clean-SSD1306:
	-$(RM) ./SSD1306/ssd1306.cyclo ./SSD1306/ssd1306.d ./SSD1306/ssd1306.o ./SSD1306/ssd1306.su ./SSD1306/ssd1306_fonts.cyclo ./SSD1306/ssd1306_fonts.d ./SSD1306/ssd1306_fonts.o ./SSD1306/ssd1306_fonts.su ./SSD1306/ssd1306_tests.cyclo ./SSD1306/ssd1306_tests.d ./SSD1306/ssd1306_tests.o ./SSD1306/ssd1306_tests.su

.PHONY: clean-SSD1306

