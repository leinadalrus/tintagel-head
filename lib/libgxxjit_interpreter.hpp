#ifndef libgxxJIT_INTERPRETER_HPP
#define libgxxJIT_INTERPRETER_HPP

#include "function_offload_phantom_marker.hpp"
#include "cellbe_function_offload_hook.hpp"
#include <cstdint>

#ifdef LIBGXXJIT_INTERPRETER_HPP
extern int libgxxjit_interpreter_toggle;
#endif

#ifndef VECTOR_SLICE_CHUNK
#define VECTOR_SLICE_CHUNK 255
#endif

typedef struct MemoryRegion {
  uint8_t memory;
  uint32_t mask;
} MemoryRegion;

typedef struct LibgxxInternalClock {
  uint32_t processing_unit_clock_address;
} LibgxxInternalClock;

typedef struct LibgxxRegionBundle {
  MemoryRegion *memory_region;
  LibgxxInternalClock libgxxinternal_clock;
} LibgxxRegionBundle;

void load_initialized_coreboot_bios();
int get_libgxxmemory_region(uint32_t address, int is_written,
                            MemoryRegion *memory_region);

uint32_t
get_processing_unit_controller(uint32_t processing_unit_controller_address);
uint64_t get_internal_system_clock_cycles(int n_cycles);
uint64_t set_libgxxmemory_region_timings(uint32_t starting_address,
                                         uint32_t ending_address,
                                         uint32_t memory_region, int bus_width,
                                         int non_sequential, int sequential);
void run_internal_system_clock_cycler(uint32_t processing_unit_clock_address);

typedef struct LibgxxJit {
} LibgxxJit;

typedef struct LibgxxJitAdapter {
} LibgxxJitAdapter;

typedef struct LibgxxJitInterpreter {
  FunctionOffloadPhantomMarker *phantom_marker;
} LibgxxJitInterpreter;

typedef struct LibgxxDataBundle {
  LibgxxJit *jit;
  LibgxxJitAdapter *adapter;
  LibgxxJitInterpreter *interpreter;
} LibgxxDataBundle;

int libgxxjit_startup_sentinel();

int initialise_external_jit_interpreter(LibgxxJitInterpreter *interpreter);
void deinitialise_external_jit_interpreter(LibgxxJitInterpreter *interpreter);
void reset_external_jit_interpreter(LibgxxJitInterpreter *interpreter);
void start_external_jit_interpreter(LibgxxJitInterpreter *interpreter);
void stop_external_jit_interpreter(LibgxxJitInterpreter *interpreter);

#endif // !LIBGXXJIT_INTERPRETER_HPP
