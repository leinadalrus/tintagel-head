#if _MSC_VER > 1400
#pragma warning(disable : 6102 6103)
#endif

#include "../inc/ndebug_testassert_messages.h"
#include "cellbe_function_offload_model.hpp"

extern "C" const char *PpuEntries[]; // SPU into PPU Entry Codes
extern "C" const char *SpuEntries[]; // SPU into PPU Entry Codes

// Build-module with DLL
// class BuildmoduleJit {
//   std::unique_ptr<ExecutionSession> execution_session;
//   DataLayout data_layout;
//   MangleAndInterner mangle_and_interner;
//   RTDyldObjectLinkingLayer object_layer;
//   IRCompileLayer ircompile_layer;
//   JITDylib &main_dynamic_library;
// };

inline const uint16_t fetch_entrylist_opcode(intptr_t *opcode_ptr) {
  uint16_t opcode = (uint16_t)opcode_ptr[0];

  if (opcode >= 0xe800)
    opcode = (opcode << 16) | (uint16_t)opcode_ptr[2];

  return opcode;
}
