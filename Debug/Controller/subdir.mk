################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Controller/MainNavigationController.cpp \
../Controller/MainViewController.cpp \
../Controller/ViewController.cpp 

OBJS += \
./Controller/MainNavigationController.o \
./Controller/MainViewController.o \
./Controller/ViewController.o 

CPP_DEPS += \
./Controller/MainNavigationController.d \
./Controller/MainViewController.d \
./Controller/ViewController.d 


# Each subdirectory must supply rules for building sources it contributes
Controller/%.o Controller/%.su Controller/%.cyclo: ../Controller/%.cpp Controller/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/Controller" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2/csrc" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2/cppsrc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/Model" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Controller

clean-Controller:
	-$(RM) ./Controller/MainNavigationController.cyclo ./Controller/MainNavigationController.d ./Controller/MainNavigationController.o ./Controller/MainNavigationController.su ./Controller/MainViewController.cyclo ./Controller/MainViewController.d ./Controller/MainViewController.o ./Controller/MainViewController.su ./Controller/ViewController.cyclo ./Controller/ViewController.d ./Controller/ViewController.o ./Controller/ViewController.su

.PHONY: clean-Controller

