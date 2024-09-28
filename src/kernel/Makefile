CC = i386-elf-gcc
AS = nasm -f elf32

CFLAGS = -ffreestanding -O2 -Wall -Wextra -std=gnu99

SRC=$(wildcard *.c)
ASM=$(wildcard *.s)
OBJA=$(patsubst %.s, %.o, $(ASM))
OBJ=$(patsubst %.c, %.o, $(SRC))

all: $(OBJA) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(AS) $< -o $@

clean:
	rm *.o