#ifndef AMD_64_64_CELL_INTERPRETER_HPP
#define AMD_64_64_CELL_INTERPRETER_HPP

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "amd64_comptime_cell_arenas.hpp"
#include "amd64_hypervisor_guest_policy.h"

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
