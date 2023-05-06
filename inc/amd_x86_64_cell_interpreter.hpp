#ifndef AMD_X86_64_CELL_INTERPRETER_HPP
#define AMD_X86_64_CELL_INTERPRETER_HPP

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

class ArenaData {
  void *destination, *source, *table_data;
  uint16_t data_size;
};

class ArenaState {
  ArenaData state;
};

// TODO decompiler/recompiler for cross-platform usage
template <typename T> class AmdX86ArenaAllocator {
  ArenaState *member_any_opaque_state;

public:
  void allocate_arena_initial_bundles(T *generic_opaque_type,
                                      ArenaState *user_state) {
    this->member_any_opaque_state = malloc(sizeof(
        char)); // need to use x86-64 architecture instruction/registry values
  }
};

class AmdX86AbstractSyntaxTree {};

class AmdX86Treesitter {};

class AmdX86Lexer {};

#endif // AMD_X86_64_CELL_INTERPRETER_HPP
