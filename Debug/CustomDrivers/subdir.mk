################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CustomDrivers/UserActionPanel.cpp \
../CustomDrivers/UserButton.cpp 

OBJS += \
./CustomDrivers/UserActionPanel.o \
./CustomDrivers/UserButton.o 

CPP_DEPS += \
./CustomDrivers/UserActionPanel.d \
./CustomDrivers/UserButton.d 


# Each subdirectory must supply rules for building sources it contributes
CustomDrivers/%.o CustomDrivers/%.su CustomDrivers/%.cyclo: ../CustomDrivers/%.cpp CustomDrivers/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2/csrc" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2/cppsrc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/Model" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CustomDrivers

clean-CustomDrivers:
	-$(RM) ./CustomDrivers/UserActionPanel.cyclo ./CustomDrivers/UserActionPanel.d ./CustomDrivers/UserActionPanel.o ./CustomDrivers/UserActionPanel.su ./CustomDrivers/UserButton.cyclo ./CustomDrivers/UserButton.d ./CustomDrivers/UserButton.o ./CustomDrivers/UserButton.su

.PHONY: clean-CustomDrivers

