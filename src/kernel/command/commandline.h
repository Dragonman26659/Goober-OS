#ifndef COMMANDLINE_H
#define COMMANDLINE_H
#include "../terminal.h"
#include "../devices/keyboard.h"
#include "../std/util.h"
#include "../vga.h"

#define COMMAND_PREFIX "$ "


void CommandInit();
void CommandType(char c);
void ResetCommandBuffer();
void executeCommand(const char* data);


#endif // COMMANDLINE_H