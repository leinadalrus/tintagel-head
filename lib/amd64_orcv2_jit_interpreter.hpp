#ifndef AMD64_ORCV2_JIT_INTERPRETER_HPP
#define AMD64_ORCV2_JIT_INTERPRETER_HPP

#include "function_offload_phantom_marker.hpp"
#include "spe_function_offload_hook.hpp"
#include <cstdint>

#ifdef AMD64_ORC_JIT_INTERPRETER_H
extern int amd64_orcv2_jit_interpreter_toggle;
#endif

#ifndef VECTOR_SLICE_CHUNK
#define VECTOR_SLICE_CHUNK 255
#endif

typedef struct MemoryRegion {
  uint8_t memory;
  uint32_t mask;
} MemoryRegion;

typedef struct OrcV2InternalClock {
  uint32_t processing_unit_clock_address;
} OrcV2InternalClock;

typedef struct OrcV2RegionBundle {
  MemoryRegion *memory_region;
  OrcV2InternalClock orcv2_internal_clock;
} OrcV2RegionBundle;

void load_maked_coreboot_bios();
int get_orcv2_memory_region(uint32_t address, int is_written,
                            MemoryRegion *memory_region);

uint32_t
get_processing_unit_controller(uint32_t processing_unit_controller_address);
uint64_t get_internal_system_clock_cycles(int n_cycles);
uint64_t set_orcv2_memory_region_timings(uint32_t starting_address,
                                         uint32_t ending_address,
                                         uint32_t memory_region, int bus_width,
                                         int non_sequential, int sequential);
void run_internal_system_clock_cycler(uint32_t processing_unit_clock_address);

typedef struct OrcV2Jit {
} OrcV2Jit;

typedef struct OrcV2JitAdapter {
} OrcV2JitAdapter;

typedef struct OrcV2JitInterpreter {
  FunctionOffloadPhantomMarker *phantom_marker;
} OrcV2JitInterpreter;

typedef struct OrcV2DataBundle {
  OrcV2Jit *jit;
  OrcV2JitAdapter *adapter;
  OrcV2JitInterpreter *interpreter;
} OrcV2DataBundle;

int orcv2_jit_startup_sentinel();

int initialise_external_jit_interpreter(OrcV2JitInterpreter *interpreter);
void deinitialise_external_jit_interpreter(OrcV2JitInterpreter *interpreter);
void reset_external_jit_interpreter(OrcV2JitInterpreter *interpreter);
void start_external_jit_interpreter(OrcV2JitInterpreter *interpreter);
void stop_external_jit_interpreter(OrcV2JitInterpreter *interpreter);

#endif // !AMD64_ORCV2_JIT_INTERPRETER_HPP
