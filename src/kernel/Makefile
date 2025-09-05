CC = i386-elf-gcc
AS = nasm -f elf32

CFLAGS = -ffreestanding -O2 -Wall -Wextra -std=gnu99

SRC=$(wildcard *.c) $(wildcard */*.c) $(wildcard */*/*.c) $(wildcard */*/*/*.c)
ASM=$(wildcard *.s) $(wildcard */*.s) $(wildcard */*/*.s) $(wildcard */*/*/*.s)
OBJA=$(patsubst %.s, %.o, $(ASM))
OBJ=$(patsubst %.c, %.o, $(SRC))
OBJPP=$(patsubst %.cpp, %.o, $(SRCPP))

all: $(OBJA) $(OBJ) $(OBJPP)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -cpp $< -o $@

%.o: %.s
	$(AS) $< -o $@

clean:
	rm *.o
	rm */*.o
