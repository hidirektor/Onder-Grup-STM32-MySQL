################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Drivers/Third_Party/FreeRTOS/Source/croutine.c \
../Middlewares/Drivers/Third_Party/FreeRTOS/Source/event_groups.c \
../Middlewares/Drivers/Third_Party/FreeRTOS/Source/list.c \
../Middlewares/Drivers/Third_Party/FreeRTOS/Source/queue.c \
../Middlewares/Drivers/Third_Party/FreeRTOS/Source/stream_buffer.c \
../Middlewares/Drivers/Third_Party/FreeRTOS/Source/tasks.c \
../Middlewares/Drivers/Third_Party/FreeRTOS/Source/timers.c 

OBJS += \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/croutine.o \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/event_groups.o \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/list.o \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/queue.o \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/stream_buffer.o \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/tasks.o \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/timers.o 

C_DEPS += \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/croutine.d \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/event_groups.d \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/list.d \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/queue.d \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/stream_buffer.d \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/tasks.d \
./Middlewares/Drivers/Third_Party/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Drivers/Third_Party/FreeRTOS/Source/%.o Middlewares/Drivers/Third_Party/FreeRTOS/Source/%.su Middlewares/Drivers/Third_Party/FreeRTOS/Source/%.cyclo: ../Middlewares/Drivers/Third_Party/FreeRTOS/Source/%.c Middlewares/Drivers/Third_Party/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-Drivers-2f-Third_Party-2f-FreeRTOS-2f-Source

clean-Middlewares-2f-Drivers-2f-Third_Party-2f-FreeRTOS-2f-Source:
	-$(RM) ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/croutine.cyclo ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/croutine.d ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/croutine.o ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/croutine.su ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/event_groups.cyclo ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/event_groups.d ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/event_groups.o ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/event_groups.su ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/list.cyclo ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/list.d ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/list.o ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/list.su ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/queue.cyclo ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/queue.d ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/queue.o ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/queue.su ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/stream_buffer.cyclo ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/stream_buffer.d ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/stream_buffer.o ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/stream_buffer.su ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/tasks.cyclo ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/tasks.d ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/tasks.o ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/tasks.su ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/timers.cyclo ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/timers.d ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/timers.o ./Middlewares/Drivers/Third_Party/FreeRTOS/Source/timers.su

.PHONY: clean-Middlewares-2f-Drivers-2f-Third_Party-2f-FreeRTOS-2f-Source

