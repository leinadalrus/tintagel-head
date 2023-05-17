#include "amd64_orcv2jit_function_offload.hpp"

#ifdef __linux__
#include "/llvm/adt/stringref.h"
#include "/llvm/executionengine/orc/compileutils.h"
#include "/llvm/executionengine/orc/core.h"
#include "/llvm/executionengine/orc/executionutils.h"
#include "/llvm/executionengine/orc/ircompilelayer.h"
#include "/llvm/executionengine/orc/jittargetmachinebuilder.h"
#include "/llvm/executionengine/orc/rtdyldobjectlinkinglayer.h"
#include "/llvm/executionengine/sectionmemorymanager.h"
#include "/llvm/ir/datalayout.h"
#include "/llvm/ir/llvmcontext.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#endif // !__linux__

#ifdef _WIN32
#include <cstdio>
#include <cstdlib>
#ifdef DETOURS_INTERNAL
#include <detours.h> // NOTE: ifdef detours.h
#endif
#include <handleapi.h>
#include <iostream>
#include <memory>
#include <processthreadsapi.h>
#include <windows.h>
#include <winnt.h>
#endif

#ifdef DETOURS_ORCV2

extern "C" BYTE Ppsp_Entry_Codes[]; // SPE into PPE Entry Codes

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

#endif // !DETOURS_ORCV2
