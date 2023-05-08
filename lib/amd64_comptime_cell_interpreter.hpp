#ifndef AMD_64_64_CELL_INTERPRETER_HPP
#define AMD_64_64_CELL_INTERPRETER_HPP

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "amd64_comptime_cell_arenas.hpp"

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

// TODO decompiler/recompiler for cross-platform usage
template <typename T> class Amd64ArenaAllocator {
  ArenaState *member_any_opaque_state;

public:
  void allocate_arena_initial_bundles(T *generic_opaque_type,
                                      ArenaState *user_state) {
    this->member_any_opaque_state = malloc(sizeof(
        char)); // need to use x86-64 architecture instruction/registry values
  }
};

class Amd64AbstractSyntaxTree {};

class Amd64Treesitter {
  Amd64AbstractSyntaxTree *abstract_syntax_tree;
};

class Amd64Lexer {
  Amd64AbstractSyntaxTree *abstract_syntax_tree;
  Amd64Treesitter *ast_treesitter;
};

#endif // AMD_64_64_CELL_INTERPRETER_HPP
