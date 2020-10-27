################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/octaveCaller.cpp 

OBJS += \
./src/octaveCaller.o 

CPP_DEPS += \
./src/octaveCaller.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/include/octave-5.2.0/octave/ -I/usr/share/octave/5.2.0/etc/tests -I/usr/lib/x86_64-redhat-linux6E -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


