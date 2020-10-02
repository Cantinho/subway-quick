################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/model/users/Cashier.cpp \
../src/model/users/Employee.cpp \
../src/model/users/Manager.cpp \
../src/model/users/User.cpp 

OBJS += \
./src/model/users/Cashier.o \
./src/model/users/Employee.o \
./src/model/users/Manager.o \
./src/model/users/User.o 

CPP_DEPS += \
./src/model/users/Cashier.d \
./src/model/users/Employee.d \
./src/model/users/Manager.d \
./src/model/users/User.d 


# Each subdirectory must supply rules for building sources it contributes
src/model/users/%.o: ../src/model/users/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


