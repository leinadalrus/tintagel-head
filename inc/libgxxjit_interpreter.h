#include "function_offload_model_hook.h"
#include "function_offload_phantom_marker.h"

#ifndef LIBGXXJIT_INTERPRETER_H
#define LIBGXXJIT_INTERPRETER_H

#if __linux__
#include <assert.h>
#include <libgccjit.h>
#include <memory.h>
#include <stdint.h>
#include <string.h>
#elif _WIN32
#include <assert.h>
#include <memory.h>
#include <stdint.h>
#include <string.h>
#endif

#ifdef LIBGXXJIT_INTERPRETER_H
extern int libgxxjit_interpreter_toggle;
#endif

typedef struct MemoryRegion {
  uint8_t memory;
  uint32_t mask;
} MemoryRegion;

typedef struct LibGxxInternalClock {
  uint32_t processing_unit_clock_address;
} LibGxxInternalClock;

typedef struct LibGxxRegionBundle {
  MemoryRegion *memory_region;
  LibGxxInternalClock asminternal_clock;
} LibGxxRegionBundle;

void load_maked_coreboot_bios(int(*unix_nan_boxing));
int get_asmmemory_region(uint32_t address, int is_written,
                         MemoryRegion *memory_region);

uint32_t
get_processing_unit_controller(uint32_t processing_unit_controller_address);
uint64_t get_internal_system_clock_cycles(int n_cycles);
uint64_t set_asmmemory_region_timings(uint32_t starting_address,
                                      uint32_t ending_address,
                                      uint32_t memory_region, int bus_width,
                                      int non_sequential, int sequential);
void run_internal_system_clock_cycler(uint32_t processing_unit_clock_address);

typedef struct LibGxxJit {
} LibGxxJit;

typedef struct LibGxxJitAdapter {
} LibGxxJitAdapter;

typedef struct LibGxxJitInterpreter {
  FunctionOffloadPhantomMarker *phantom_marker;
} LibGxxJitInterpreter;

typedef struct LibGxxDataBundle {
  LibGxxJit *jit;
  LibGxxJitAdapter *adapter;
  LibGxxJitInterpreter *interpreter;
} LibGxxDataBundle;

int asmjit_startup_sentinel();

LibGxxJitInterpreter *
initialise_external_jit_interpreter(LibGxxJitInterpreter *interpreter);
void deinitialise_external_jit_interpreter(LibGxxJitInterpreter *interpreter);
void reset_external_jit_interpreter(LibGxxJitInterpreter *interpreter);
void start_external_jit_interpreter(LibGxxJitInterpreter *interpreter,
                                    gcc_jit_context *ctxt);
void stop_external_jit_interpreter(LibGxxJitInterpreter *interpreter,
                                   gcc_jit_context *ctxt);

#endif // !LIBGXXJIT_INTERPRETER_H
