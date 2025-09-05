#ifndef COMMANDLINE_H
#define COMMANDLINE_H
#include "terminal.h"
#include "keyboard.h"
#include "vga.h"
#include "../std/util.h"

#define COMMAND_PREFIX "$ "


void CommandInit();
void CommandType(char c);
void ResetCommandBuffer();
void executeCommand(const char* data);


#endif // COMMANDLINE_H