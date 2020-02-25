################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/exo_lumiere.c \
../src/main.c \
../src/parping.c 

OBJS += \
./src/exo_lumiere.o \
./src/main.o \
./src/parping.o 

C_DEPS += \
./src/exo_lumiere.d \
./src/main.d \
./src/parping.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

