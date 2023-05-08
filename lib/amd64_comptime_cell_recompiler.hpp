#ifndef AMD64_COMPTIME_CELL_RECOMPILER_HPP
#define AMD64_COMPTIME_CELL_RECOMPILER_HPP

#include "amd64_comptime_cell_arenas.hpp"
#include "amd64_comptime_cell_interpreter.hpp"

template <typename T> class Amd64Recompiler {
  Amd64ArenaAllocator<T> *amd64_arena_state;
};

#endif // AMD64_COMPTIME_CELL_RECOMPILER_HPP
