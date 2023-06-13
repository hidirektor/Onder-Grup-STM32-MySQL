################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.c \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.c \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.c \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.c \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.c \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.c \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.c \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.c \
../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.c 

OBJS += \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.o \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.o \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.o \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.o \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.o \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.o \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.o \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.o \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.o \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.o \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.o \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.o \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.o \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.o 

C_DEPS += \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.d \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.d \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.d \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.d \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.d \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.d \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.d \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.d \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.d \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.d \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.d \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.d \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.d \
./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/%.o Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/%.su Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/%.cyclo: ../Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/%.c Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-Drivers-2f-STM32F1xx_HAL_Driver-2f-Src

clean-Middlewares-2f-Drivers-2f-STM32F1xx_HAL_Driver-2f-Src:
	-$(RM) ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.su ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.su ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.su ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.su ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.su ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.su ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.su ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.su ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.su ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.su ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.su ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.su ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.su ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.cyclo ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.d ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.o ./Middlewares/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.su

.PHONY: clean-Middlewares-2f-Drivers-2f-STM32F1xx_HAL_Driver-2f-Src

