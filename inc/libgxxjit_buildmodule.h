#include "function_offload_model_hook.h"
#include "ndebug_testassert_messages.h"

#ifndef LIBGXXJIT_BUILDMODULE_H
#define LIBGXXJIT_BUILDMODULE_H

inline const uint16_t fetch_entrylist_opcode(intptr_t *opcode_ptr) {
  uint16_t opcode = (uint16_t)opcode_ptr[0];

  if (opcode >= 0xe800)
    opcode = (opcode << 16) | (uint16_t)opcode_ptr[2];

  return opcode;
}

#endif // !LIBGXXJIT_BUILDMODULE_H
