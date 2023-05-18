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
#include <stdint.h>
#ifdef DETOURS_INTERNAL
#include <detours.h> // NOTE: ifdef detours.h
#endif
#include <handleapi.h>
#include <iostream>
#include <memory>
#ifndef PCONTEXT
#define PCONTEXT
#define pContextRecord
#include <processthreadsapi.h>
#include <windows.h>
#include <winnt.h>
#endif // !_CONTEXT
#endif

#define ASSERT_VA_ARGS(_str)                                                   \
  {                                                                            \
    if (!(__VA_ARGS__))                                                        \
      Assert_Variadic_Arguments(#_str, __FILE__, __LINE__);                    \
  }

void assert_message(const char *sz_message) {
  printf("%s in %s, line: %d", sz_message, __FILE__, __LINE__);
}

void assert_message(const char *sz_message, const char *sz_file,
                    unsigned long xn_line) {
  printf("%s in %s, line %ld", sz_message, sz_file, xn_line);
}
