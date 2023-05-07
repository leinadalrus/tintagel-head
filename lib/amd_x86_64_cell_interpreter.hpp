#ifndef AMD_X86_64_CELL_INTERPRETER_HPP
#define AMD_X86_64_CELL_INTERPRETER_HPP

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "amd_x86_64_cell_arenas.hpp"

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

class AmdX86Treesitter {
  AmdX86AbstractSyntaxTree *abstract_syntax_tree;
};

class AmdX86Lexer {
  AmdX86AbstractSyntaxTree *abstract_syntax_tree;
  AmdX86Treesitter *ast_treesitter;
};

#endif // AMD_X86_64_CELL_INTERPRETER_HPP
