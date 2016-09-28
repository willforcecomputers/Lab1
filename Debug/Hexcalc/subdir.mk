################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hexcalc/hexcalc.c 

OBJS += \
./Hexcalc/hexcalc.o 

C_DEPS += \
./Hexcalc/hexcalc.d 


# Each subdirectory must supply rules for building sources it contributes
Hexcalc/%.o: ../Hexcalc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


