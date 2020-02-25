################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/60_count_char.c \
../src/61_count_char_file.c 

OBJS += \
./src/60_count_char.o \
./src/61_count_char_file.o 

C_DEPS += \
./src/60_count_char.d \
./src/61_count_char_file.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

