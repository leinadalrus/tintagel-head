#ifndef HANDLING_HPP
#define HANDLING_HPP

#if _WIN32
#include <C:\\raylib\\raylib\\src\\raylib.h>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#elif __linux__
#include <raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#endif // !_WIN32 ||  !__linux__

#include "components.hpp"

enum class OpcodeMessages {
  ZERO = 0x0,
  XXV = 0x25,
  FF = 0xFF,
};

class Command {
public:
  virtual ~Command() {}
  virtual void execute() = 0;
};

class AttackCommand : public Command {
  int attack();

public:
  virtual void execute() { attack(); }
};

class DelayCommand : public Command {
  int delay();

public:
  virtual void execute() { delay(); }
};

class SustainCommand : public Command {
  int sustain();

public:
  virtual void execute() { sustain(); }
};

class ReleaseCommand : public Command {
  int release();

public:
  virtual void execute() { release(); }
};

class InputHandler { // Command Input Bundle(d)
  AttackCommand attack_command;
  DelayCommand delay_command;
  SustainCommand sustain_command;
  ReleaseCommand release_Command;
};

#endif // !HANDLING_HPP
