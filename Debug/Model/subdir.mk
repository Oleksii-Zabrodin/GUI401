################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Model/Event.cpp \
../Model/EventReciever.cpp \
../Model/EventSender.cpp \
../Model/Stack.cpp \
../Model/UserEvent.cpp \
../Model/VideoChannel.cpp 

OBJS += \
./Model/Event.o \
./Model/EventReciever.o \
./Model/EventSender.o \
./Model/Stack.o \
./Model/UserEvent.o \
./Model/VideoChannel.o 

CPP_DEPS += \
./Model/Event.d \
./Model/EventReciever.d \
./Model/EventSender.d \
./Model/Stack.d \
./Model/UserEvent.d \
./Model/VideoChannel.d 


# Each subdirectory must supply rules for building sources it contributes
Model/%.o Model/%.su Model/%.cyclo: ../Model/%.cpp Model/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/Controller" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2/csrc" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers/u8g2/cppsrc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/Model" -I"/Users/lex/STM32CubeIDE/workspace_1.17.0/GUI401/CustomDrivers" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Model

clean-Model:
	-$(RM) ./Model/Event.cyclo ./Model/Event.d ./Model/Event.o ./Model/Event.su ./Model/EventReciever.cyclo ./Model/EventReciever.d ./Model/EventReciever.o ./Model/EventReciever.su ./Model/EventSender.cyclo ./Model/EventSender.d ./Model/EventSender.o ./Model/EventSender.su ./Model/Stack.cyclo ./Model/Stack.d ./Model/Stack.o ./Model/Stack.su ./Model/UserEvent.cyclo ./Model/UserEvent.d ./Model/UserEvent.o ./Model/UserEvent.su ./Model/VideoChannel.cyclo ./Model/VideoChannel.d ./Model/VideoChannel.o ./Model/VideoChannel.su

.PHONY: clean-Model

