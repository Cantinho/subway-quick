################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/model/orders/eatables/Filling.cpp \
../src/model/orders/eatables/Sandwich.cpp 

OBJS += \
./src/model/orders/eatables/Filling.o \
./src/model/orders/eatables/Sandwich.o 

CPP_DEPS += \
./src/model/orders/eatables/Filling.d \
./src/model/orders/eatables/Sandwich.d 


# Each subdirectory must supply rules for building sources it contributes
src/model/orders/eatables/%.o: ../src/model/orders/eatables/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


