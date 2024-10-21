#include "terminal.h"

size_t terminal_row;
size_t terminal_column;

size_t cursor_row;
size_t cursor_column;


uint8_t terminal_color;
uint16_t* terminal_buffer;

// Initialises the terminal
void terminal_initialize(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

// Sets the color of the terminal
void terminal_setcolor(uint8_t color) 
{
	terminal_color = color;
}

// Places a entry (charater) given a color and a x and y coordinate
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

// Scrolls the terminal
void terminal_scroll() {
    for (int i = 0; i < VGA_HEIGHT - 2; i++) {
        memcpy(terminal_buffer + i * VGA_WIDTH,
               terminal_buffer + (i + 1) * VGA_WIDTH,
               VGA_WIDTH * sizeof(*terminal_buffer));
    }
    for (size_t x = 0; x < VGA_WIDTH; x++) {
        terminal_buffer[(VGA_HEIGHT - 2) * VGA_WIDTH + x] = vga_entry(' ', terminal_color);
    }
}

// Clears a line of the terminal
void terminal_clearline(size_t line) {
	for (size_t x = 0; x < VGA_WIDTH; x++) {
		const size_t index = line * VGA_WIDTH + x;
		terminal_buffer[index] = vga_entry(' ', terminal_color);
	}
}

// Sets the next line for the print statement
void terminal_nextline() {
	terminal_row++;
	if (terminal_row > VGA_HEIGHT - 2) {
		terminal_scroll();
		terminal_row -= 1;
	}

	terminal_column = 0;
}

// Places a charater in the terminal
void terminal_putchar(char c) 
{
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_nextline();
	}
}

// Writes data given some data and its size
void terminal_write(const char* data, size_t size) 
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

// Writes a string to the terminal
void terminal_writestring(const char* data) 
{
	terminal_write(data, strlen(data));
}

// Writes a string at a specific position (Centered)
void terminal_writestring_pos(const char* data, int screenx, int screeny) 
{
    const size_t length = strlen(data);

    for (size_t i = 0; i < length; i++) {
		terminal_putentryat(data[i], terminal_color, screenx - length / 2 + i, screeny);
    }
}

// Writes a string on a specific line
void terminal_writestring_Y(const char* data, int screeny) {
	const size_t length = strlen(data);

    for (size_t i = 0; i < length; i++) {
		terminal_putentryat(data[i], terminal_color, i, screeny);
	}
}

// Writes a string at a specific position (At start)
void terminal_writestring_XY(const char* data, int screenx, int screeny) {
	const size_t length = strlen(data);

    for (size_t i = 0; i < length; i++) {
		terminal_putentryat(data[i], terminal_color, screenx + i, screeny);
	}
}


// General commands

// Completly clears the terminal
void terminal_clear() {
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
    terminal_row = 0;
    terminal_column = 0;
}

// Displays a crash message and halts the OS
void terminal_crash(const char* data) {
    terminal_setcolor(vga_entry_color(VGA_COLOR_RED, VGA_COLOR_RED));
    terminal_clear();
    
    terminal_setcolor(vga_entry_color(VGA_COLOR_BLACK, VGA_COLOR_WHITE));

    const size_t center_x = VGA_WIDTH / 2;
    const size_t center_y = (VGA_HEIGHT / 2) - 5;

    terminal_writestring_pos("[ GOOBER OS ]", center_x, center_y - 4);
	terminal_writestring_pos("[ KERNEL CRASH ]", center_x, center_y - 2);
	terminal_writestring_pos(data, center_x, center_y + 2);
	terminal_writestring_pos("please shut down computer", center_x, center_y + 4);

	// Prevent anything else happening
	for (;;) {}
}

void terminal_disable_cursor()
{
	outPortB(0x3D4, 0x0A);
	outPortB(0x3D5, 0x20);
}

void terminal_setcursorpos(int x, int y)
{
	uint16_t pos = y * VGA_WIDTH + x;

	outPortB(0x3D4, 0x0F);
	outPortB(0x3D5, (uint8_t) (pos & 0xFF));
	outPortB(0x3D4, 0x0E);
	outPortB(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}