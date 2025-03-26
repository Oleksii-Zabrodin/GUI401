################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../View/MainScreenView.cpp 

OBJS += \
./View/MainScreenView.o 

CPP_DEPS += \
./View/MainScreenView.d 


# Each subdirectory must supply rules for building sources it contributes
View/%.o View/%.su View/%.cyclo: ../View/%.cpp View/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/Controller" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2/csrc" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2/cppsrc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/Model" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/Auxiliary" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-View

clean-View:
	-$(RM) ./View/MainScreenView.cyclo ./View/MainScreenView.d ./View/MainScreenView.o ./View/MainScreenView.su

.PHONY: clean-View

