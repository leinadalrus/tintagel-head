#ifndef AMD_COMPTIME_INTERPRETER_H
#define AMD_COMPTIME_INTERPRETER_H

enum Amd64GuestPolicy {
  NODBG = 0x0000,
  NOKS = 0x0001,
  ES = 0x0002,
  NOSEND = 0x0003,
  DOMAIN = 0x0004,
  SEV = 0x0005,
  RESERVED = 0x0000,  // Reserved. Should be zero. Bit(s) are := 15:6
  API_MAJOR = 0x0007, // Bit(s) is := 7:0
  API_MINOR = 0x0007, // Bit(s) is := 7:0
}; // The guest must not be transmitted to another platform with a lower
   // firmware version.

typedef struct ArenaData {
} ArenaData; // NOTE TODO Arrays-of-Structs

typedef struct ArenaState {
  enum Amd64GuestPolicy guest_policy;
  ArenaData *arena_data;
} ArenaState;

typedef struct Amd64Interpreter {
  enum Amd64GuestPolicy guest_policy;
} Amd64Interpreter;

typedef struct Amd64Recompiler {
} Amd64Recompiler;

#endif // AMD_COMPTIME_INTERPRETER_H
