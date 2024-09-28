CC = i386-elf-gcc

CFLAGS = -ffreestanding -O2 -Wall -Wextra -std=gnu99

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c, %.o, $(SRC))

all: $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o