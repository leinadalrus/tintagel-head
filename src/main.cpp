#pragma GCC diagnostic warning "-Wformat"
#pragma GCC diagnostic error "-Wuninitialized"

#if _WIN32
#include <C:\\raylib\\raylib\\src\\raylib.h>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#elif __linux__
#include <assert.h>
#include <raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#endif // !_WIN32 ||  !__linux__

#include "../inc/components.hpp"
#include "../inc/coverage_testassert_debug_mod.hpp"
#include "../inc/handling.hpp"
#include "../inc/ndebug_testassert_messages.h"
#include "../lib/amd64_command_buffer_handler.h"
#include "../lib/amd64_command_ring_buffer.h"
#include "../lib/powerpc_virtual_storage_model.h"

#ifdef ASSERT_VARGS
// #define ASSERT_VARGS(_str, ...) // redefined for re-use
#endif // !ASSERT_VARGS
// extern ASSERT_VARGS(_str, ...)

#define __iomem                                                                \
  __attribute__((                                                              \
      noderef,                                                                 \
      address_space(2))) // temporary definition of __iomem from sparse

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
  COVER_TESTASSERT_SWITCHSTATE(CURRENT_COLUMN, SHORT_OFFSET, SUCCESS,
                               address_offset->rb_status_code);

  return ret_val;
}

uint16_t
write_into_enumerated_header(struct PpuOffsetLookasideBuffer *address_offset,
                             int io_insertions, FILE *buffer_file) {
  FILE *ifloop_file = buffer_file, *switchstate_file = buffer_file;
  COVER_TESTASSERT_IF(CURRENT_COLUMN, SHORT_OFFSET, ifloop_file);
  return 0;
}

int main(int argc, char *argv[]) {
#if defined(X64V3JIT)
  if (argc != 0x25 || argc != 0xFF) {
    ASSERT_VARGS(read_virtual_enumerated_header);
    ASSERT_VARGS(write_into_enumerated_header);
  }
#endif

  InitWindow(600, 400, "High Hunt");

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLANK);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
