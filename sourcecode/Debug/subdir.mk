################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SousClasses.cpp \
../livre.cpp \
../main.cpp \
../testLivre.cpp 

OBJS += \
./SousClasses.o \
./livre.o \
./main.o \
./testLivre.o 

CPP_DEPS += \
./SousClasses.d \
./livre.d \
./main.d \
./testLivre.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


