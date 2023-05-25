#include "libgxxjit_interpreter.hpp"
#include "cellbe_treewalk_linter.hpp" // this contains the ArenaState classes
// need to have this include file separated
// and outside of include guards

#ifndef LIBGXXJIT_INTERPRETER_HPP
extern int libgxxjit_interpreter_toggle;
#endif

#if _WIN32
#include <cstdint>
#include <cstring>
#elif __linux__
#include <stdint.h>
#include <string.h>
#endif

void load_initialized_coreboot_bios() {}

int get_libgxxmemory_region(uint32_t address, int is_written,
                            MemoryRegion *memory_region) {
  return 0;
}

uint32_t
get_processing_unit_controller(uint32_t processing_unit_controller_address) {
  return 0;
}

uint64_t get_internal_system_clock_cycles(int n_cycles) { return 0; }

uint64_t set_libgxxmemory_region_timings(uint32_t starting_address,
                                         uint32_t ending_address,
                                         uint32_t memory_region, int bus_width,
                                         int non_sequential, int sequential) {
  return 0;
}

void run_internal_system_clock_cycler(uint32_t processing_unit_clock_address) {}

int libgxxjit_startup_sentinel() {
  switch (libgxxjit_interpreter_toggle) {
  case 0:
  case 1:
  default:
    break;
  }

  return 0;
}

int initialise_external_jit_interpreter(LibgxxJitInterpreter *interpreter) {
  LibgxxDataBundle *libgxxdata_bundle;
  ArenaState *arena_state;
  MemoryRegion *memory_region;

  uint8_t destination = (unsigned char)arena_state->arena_state().d();
  // arena_data->destination is mutable:
  destination = destination >> memory_region->memory;
  // arena_data->table_data is the bitmask for bit-ops
  uint32_t table = (unsigned int)arena_state->arena_state().td();
  table = table >> memory_region->mask;

  return 0;
}

void deinitialise_external_jit_interpreter(LibgxxJitInterpreter *interpreter) {
  free(interpreter);
  interpreter = NULL;
  LibgxxJitInterpreter new_interpreter =
      LibgxxJitInterpreter{.phantom_marker = std::nullptr_t()};
  // std::nullptr_t() is in-turn the keyword: nullptr
  // .phantom_marker is a scalar without a pointer within the struct's member
  // properties
  interpreter = &new_interpreter;
}

void reset_external_jit_interpreter(LibgxxJitInterpreter *interpreter) {
  free(interpreter);
  interpreter = NULL;
  libgxxjit_startup_sentinel();
}

void start_external_jit_interpreter(LibgxxJitInterpreter *interpreter) {}

void stop_external_jit_interpreter(LibgxxJitInterpreter *interpreter) {}
