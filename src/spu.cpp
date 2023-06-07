#pragma GCC diagnostic warning "-Wformat"
#pragma GCC diagnostic error "-Wuninitialized"

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>

#include "../ext/asmjit-oldstable/src/asmjit/asmjit.h"

#include "../inc/cellbe_memorymap.h"
#include "../inc/cellbe_spu_command_handler.h"
#include "../inc/function_offload_arena_data.h"
#include "../inc/function_offload_model_hook.h"
#include "../inc/function_offload_phantom_marker.h"

enum class SpuChannelMnemonics {
  SPU_RD_EVENT_STAT = 0,
  SPU_WR_EVENT_MASK = 1,
  SPU_WR_EVENT_ACK = 2,
  SPU_RD_SIG_NOTIFY1 = 3,
  SPU_RD_SIG_NOTIFY2 = 4,
  SPU_WR_DEC = 7,
  SPU_RD_DEC = 8,
  SPU_RD_EVENT_MASK = 11,
  SPU_RD_MACH_STAT = 13,
  SPU_WR_SRR0 = 14,
  SPU_RD_SRR0 = 15,
  SPU_WR_OUT_MBOX = 28, // Mailbox
  SPU_RD_IN_MBOX = 29,
  SPU_WR_OUT_INTR_MBOX = 30,
}; // `enum class` used to further enumeration immutability

class SpuChannel {
  // NOTE: discover: common SPU architecture instructions
};

class SpuCommand {
public:
  void execute();
};

class SpuCommandHandler {
  SpuCommand *command;

public:
  void execute();
  int handle();
};

#ifdef ArenaState
class ArenaState {};
#elif ArenaData
class ArenaData {};
#endif

class MemoryArenaId {
  MemoryArenaId(uint8_t id);
};

class MemoryRegion {};

class MemoryRegionServiceLocator {};

class AnnulMemoryRegionLocator {}; // annul memory region service locator

class MemoryRegionServicePool {};

class ExistentialProcessor {}; // TODO: make unalterable table composition as to
                               // not mutate values already existing

// Synergistic Processing Unit Handler
int initialize_table_data() { return 0; }

void deinitialize_table_data() {}

void reset_processing_unit() {}

void stop_processing_unit() {}

void set_microprogram_power_count(uint32_t power_count) {}

void set_bias(uint16_t bias) {}

void set_degrade_bit_by_ten(int enable) {}

void set_apply_bias(int enable) {}

uint8_t read_file_encoded_u8(uint32_t address_offset) { return address_offset; }

uint16_t read_file_encoded_u16(uint32_t address_offset) {
  return address_offset;
}

uint32_t read_file_encoded_u32(uint32_t address_offset) {
  return address_offset;
}

int write_file_encoded_u8(uint32_t address_offset, uint8_t address_sizetype) {
  return 0;
}

int write_file_encoded_u16(uint32_t address_offset, uint16_t address_sizetype) {
  return 0;
}

int write_file_encoded_u32(uint32_t address_offset, uint32_t address_sizetype) {
  return 0;
}

// Synergistic Processing Unit Capture: Table/Memory (Address) Data
void fifo_flush_data() {}

int fifo_write_data() { return 0; }

int write_into_dword_bus(uint32_t address, uint64_t data) { return 0; }

void set_count(uint8_t data) {}

void set_destination_address(uint32_t data) {}

void set_timer_reload(uint32_t data) {}

void set_length(uint32_t data_size) {}

void start(uint32_t address_offset, uint32_t address_sizetype, uint32_t data) {}

void run(int32_t data) {}
