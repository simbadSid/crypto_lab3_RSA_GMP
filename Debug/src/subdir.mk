################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/RSA_init.cc \
../src/largePrime.cc \
../src/largePrime_naive.cc \
../src/list.cc 

OBJS += \
./src/RSA_init.o \
./src/largePrime.o \
./src/largePrime_naive.o \
./src/list.o 

CC_DEPS += \
./src/RSA_init.d \
./src/largePrime.d \
./src/largePrime_naive.d \
./src/list.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


