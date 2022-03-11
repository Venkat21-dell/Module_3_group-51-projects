CC= arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS=-c -mcpu=$(MACH) -mthumb -std=gnull -Wall -o0
all:main.o MyStm32f407xx_gpio_driver.o stm32_startup.o finalled.elf

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^
Mystm32f407xx_gpio_driver.o:Mystm32f407xx_gpio_driver.c
	$(CC) $(CFLAGS) -o $@ $^

stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^
finalled.elf:main.o MyStm32f4o7xx_gpio_driver.o stm32_startup.o
	$(CC) $(LDFLAGS) -O $@ $^
clean:
	rm -rf  *.o *.elf