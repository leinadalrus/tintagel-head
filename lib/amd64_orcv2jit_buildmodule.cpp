#pragma warning(pop)
#if _MSC_VER > 1400
#pragma warning(disable : 6102 6103)
#endif

#include "../inc/ndebug_variadic_args.hpp"
#include "amd64_orcv2jit_function_offload.hpp"

#ifdef DETOURS_ORCV2

extern "C" BYTE Speppe_Entry_Codes[]; // SPE into PPE Entry Codes

// Build-module with DLL
// class BuildmoduleJit {
//   std::unique_ptr<ExecutionSession> execution_session;
//   DataLayout data_layout;
//   MangleAndInterner mangle_and_interner;
//   RTDyldObjectLinkingLayer object_layer;
//   IRCompileLayer ircompile_layer;
//   JITDylib &main_dynamic_library;
// };

HANDLE Hwnd_Child_Process = nullptr;
HANDLE Hwnd_Child_Thread = nullptr;

__declspec(noreturn) void Handle_Api_Failure(const char *api) {
  DWORD last_error = GetLastError();
  std::cout << "Payload Executable:\t" << api << "\nfailed: #[(" << last_error
            << ")]" << std::endl;

  if (Hwnd_Child_Thread != NULL)
    CloseHandle(Hwnd_Child_Thread);

  if (Hwnd_Child_Process != NULL) {
    TerminateProcess(Hwnd_Child_Process, 1);
    CloseHandle(Hwnd_Child_Process);
  }

  ExitProcess(1);
}

inline const uint16_t fetch_entrylist_opcode(intptr_t *opcode_ptr) {
  uint16_t opcode = (uint16_t)opcode_ptr[0];

  if (opcode >= 0xe800)
    opcode = (opcode << 16) | (uint16_t)opcode_ptr[2];

  return opcode;
}

#endif // !DETOURS_ORCV2
