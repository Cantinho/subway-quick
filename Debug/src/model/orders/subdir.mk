################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/model/orders/Order.cpp \
../src/model/orders/OrderItem.cpp 

OBJS += \
./src/model/orders/Order.o \
./src/model/orders/OrderItem.o 

CPP_DEPS += \
./src/model/orders/Order.d \
./src/model/orders/OrderItem.d 


# Each subdirectory must supply rules for building sources it contributes
src/model/orders/%.o: ../src/model/orders/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


