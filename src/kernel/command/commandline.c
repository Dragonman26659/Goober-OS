#include "commandline.h"

char commandBuffer[VGA_W - 2];
int commandIndex = 0;
bool exeCMD = false;

void Display_shell_prompt() {
    terminal_setcursorpos(commandIndex + 2, VGA_HEIGHT - 1);
    terminal_setcolor(vga_entry_color(VGA_COLOR_BLACK, VGA_COLOR_LIGHT_GREY));
    terminal_clearline(VGA_HEIGHT - 1);
    terminal_writestring_XY("$>", 0 ,VGA_HEIGHT - 1);
    terminal_writestring_XY(commandBuffer, 2 ,VGA_HEIGHT - 1);
    terminal_setcolor(vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK));
}

void CommandInit() {
    ResetCommandBuffer();
    Display_shell_prompt();
}

void ResetCommandBuffer() {
    memset(commandBuffer, 0, sizeof(commandBuffer));
    commandIndex = 0;
}

void ConsoleClear() {
    terminal_clear();
    Display_shell_prompt();
}

void CommandType(char c) {
    switch (c) {
        case '\n':
            exeCMD = true;
            break;
        case '\b':
            if (commandIndex > 0) {
                commandBuffer[--commandIndex] = 0;
            }
            break;
        default:
            if (commandIndex < VGA_W - 1) {
                commandBuffer[commandIndex++] = c;
            }
            break;
    }
}

void UpdateTerminal() {
    if (exeCMD) {
        executeCommand(commandBuffer);
        ResetCommandBuffer();
        exeCMD = false;
    }

    // Display shell
    Display_shell_prompt();
}

void executeCommand(const char* data) {
    char* command[30];
    char* operand[255];

    
    if (strcmp(command, "crash") == 0 && operand != NULL) {
        terminal_crash(operand);
    } else if (strcmp(command, "echo") == 0 && operand != NULL) {
        printf("%s", operand);
    }else if (strcmp(command, "clr") == 0) {
        ConsoleClear();
    }
}