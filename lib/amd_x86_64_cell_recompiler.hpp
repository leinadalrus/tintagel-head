#ifndef AMD_X86_64_CELL_RECOMPILER_HPP
#define AMD_X86_64_CELL_RECOMPILER_HPP

#include "amd_x86_64_cell_arenas.hpp"
#include "amd_x86_64_cell_interpreter.hpp"

template <typename T> class AmdX86EngineRecompiler {
  AmdX86ArenaAllocator<T> *amd_x86_arena_state;
};

#endif // AMD_X86_64_CELL_RECOMPILER_HPP
