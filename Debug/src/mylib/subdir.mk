################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/mylib/sum.c 

OBJS += \
./src/mylib/sum.o 

C_DEPS += \
./src/mylib/sum.d 


# Each subdirectory must supply rules for building sources it contributes
src/mylib/%.o: ../src/mylib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


