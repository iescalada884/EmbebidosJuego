################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/FreertosMain.c \
../src/dibujo.c \
../src/pajaro.c \
../src/powerUps.c \
../src/tuberia.c 

OBJS += \
./src/FreertosMain.o \
./src/dibujo.o \
./src/pajaro.o \
./src/powerUps.o \
./src/tuberia.o 

C_DEPS += \
./src/FreertosMain.d \
./src/dibujo.d \
./src/pajaro.d \
./src/powerUps.d \
./src/tuberia.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MicroBlaze gcc compiler'
	mb-gcc -Wall -O0 -g3 -I../../juego_bsp/microblaze_0/include -I"D:\Documentos\Universidad\Vivado\Practicas\pract_8\pract_8.sdk\juego\src" -c -fmessage-length=0 -MT"$@" -I../../juego_bsp/microblaze_0/include -mlittle-endian -mcpu=v11.0 -mxl-soft-mul -Wl,--no-relax -ffunction-sections -fdata-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


