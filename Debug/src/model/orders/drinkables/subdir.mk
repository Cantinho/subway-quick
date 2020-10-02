################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/model/orders/drinkables/Drink.cpp 

OBJS += \
./src/model/orders/drinkables/Drink.o 

CPP_DEPS += \
./src/model/orders/drinkables/Drink.d 


# Each subdirectory must supply rules for building sources it contributes
src/model/orders/drinkables/%.o: ../src/model/orders/drinkables/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


