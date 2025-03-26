################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CustomDrivers/u8g2/cppsrc/U8g2lib.cpp \
../CustomDrivers/u8g2/cppsrc/U8x8lib.cpp 

OBJS += \
./CustomDrivers/u8g2/cppsrc/U8g2lib.o \
./CustomDrivers/u8g2/cppsrc/U8x8lib.o 

CPP_DEPS += \
./CustomDrivers/u8g2/cppsrc/U8g2lib.d \
./CustomDrivers/u8g2/cppsrc/U8x8lib.d 


# Each subdirectory must supply rules for building sources it contributes
CustomDrivers/u8g2/cppsrc/%.o CustomDrivers/u8g2/cppsrc/%.su CustomDrivers/u8g2/cppsrc/%.cyclo: ../CustomDrivers/u8g2/cppsrc/%.cpp CustomDrivers/u8g2/cppsrc/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2/csrc" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2/cppsrc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/Model" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CustomDrivers-2f-u8g2-2f-cppsrc

clean-CustomDrivers-2f-u8g2-2f-cppsrc:
	-$(RM) ./CustomDrivers/u8g2/cppsrc/U8g2lib.cyclo ./CustomDrivers/u8g2/cppsrc/U8g2lib.d ./CustomDrivers/u8g2/cppsrc/U8g2lib.o ./CustomDrivers/u8g2/cppsrc/U8g2lib.su ./CustomDrivers/u8g2/cppsrc/U8x8lib.cyclo ./CustomDrivers/u8g2/cppsrc/U8x8lib.d ./CustomDrivers/u8g2/cppsrc/U8x8lib.o ./CustomDrivers/u8g2/cppsrc/U8x8lib.su

.PHONY: clean-CustomDrivers-2f-u8g2-2f-cppsrc

