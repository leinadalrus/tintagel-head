#pragma GCC diagnostic warning "-Wformat"
#pragma GCC diagnostic error "-Wuninitialized"

#if _WIN32
#include <C:\\raylib\\raylib\\src\\raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#elif __linux__
#include <assert.h>
#include <raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#endif // !_WIN32 ||  !__linux__

#include "../inc/amd64_command_buffer_handler.h"
#include "../inc/amd64_command_ring_buffer.h"
#include "../inc/cellbe_harvard_style_cache.h"
#include "../inc/cellbe_spu_command_handler.h"
#include "../inc/components.h"
#include "../inc/coverage_testassert_debug_mod.h"
#include "../inc/handling.h"
#include "../inc/ndebug_testassert_messages.h"

#ifdef ASSERT_VARGS
// #define ASSERT_VARGS(_str, ...) // redefined for re-use
#endif // !ASSERT_VARGS
// extern ASSERT_VARGS(_str, ...)

uint16_t read_virtual_enumerated_header(
    struct PpuOffsetLookasideBuffer *address_offset) {
  uint64_t ret_val = 0;

  FILE *ifloop_file, *switchstate_file;
  DecryptedCommandBufferTree *command_buffer_tree;
  COVER_TESTASSERT_IF(CURRENT_COLUMN, SHORT_OFFSET, ifloop_file->_cur_column);

  switch (address_offset->rb_status_code) {
  case SUCCESS:
    ret_val =
        (uint64_t)
            address_offset->ppe_translation_lookaside_buffer.address_offset;
    assert(address_offset->rb_status_code);
    assert(SUCCESS);

  default:
    ret_val = 1;
  }
  COVER_TESTASSERT_SWITCHSTATE(
      CURRENT_COLUMN, SHORT_OFFSET,
      address_offset->ppe_translation_lookaside_buffer.address_offset,
      switchstate_file->_vtable_offset);

  return ret_val;
}

uint16_t
write_into_enumerated_header(struct PpuOffsetLookasideBuffer *address_offset,
                             int io_insertions, FILE *buffer_file) {
  FILE *ifloop_file = buffer_file, *switchstate_file = buffer_file;
  COVER_TESTASSERT_IF(CURRENT_COLUMN, SHORT_OFFSET, ifloop_file);
  return 0;
}

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

void fifo_flush_data() {}

int fifo_write_data() { return 0; }

void set_count(uint8_t data) {}

void set_destination_address(uint32_t data) {}

void set_timer_reload(uint32_t data) {}

void set_length(uint32_t data_size) {}

void start(uint32_t address_offset, uint32_t address_sizetype, uint32_t data) {}

void run(int32_t data) {}

void bus_write_u32(uint32_t address, uint64_t data) {}
