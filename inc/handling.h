#ifndef HANDLING_H
#define HANDLING_H

#if _WIN32
#include <C:\\raylib\\raylib\\src\\raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#elif __linux__
#include <raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#endif // !_WIN32 ||  !__linux__

#include "components.h"

enum OpcodeMessages {
  ZERO = 0x0,
  XXV = 0x25,
  FF = 0xFF,
};

typedef struct Command {
} Command;

typedef struct AttackCommand {
  Command *command;
} AttackCommand;

typedef struct DelayCommand {
  Command *command;
} DelayCommand;

typedef struct SustainCommand {
  Command *command;
} SustainCommand;

typedef struct ReleaseCommand {
  Command *command;
} ReleaseCommand;

typedef struct Handler {
  Command *command;
} Handler;

typedef struct InputHandler { // Command Input Bundle(d)
  Handler *handler;
  AttackCommand attack_command;
  DelayCommand delay_command;
  SustainCommand sustain_command;
  ReleaseCommand release_Command;
} InputHandler;

void execute_command(Command *command_dx);
int handle_input(Handler *handle_index);

#endif // !HANDLING_H
