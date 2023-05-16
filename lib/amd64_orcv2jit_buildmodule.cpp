// #include "llvm/adt/stringref.h"
// #include "llvm/executionengine/orc/compileutils.h"
// #include "llvm/executionengine/orc/core.h"
// #include "llvm/executionengine/orc/executionutils.h"
// #include "llvm/executionengine/orc/ircompilelayer.h"
// #include "llvm/executionengine/orc/jittargetmachinebuilder.h"
// #include "llvm/executionengine/orc/rtdyldobjectlinkinglayer.h"
// #include "llvm/executionengine/sectionmemorymanager.h"
// #include "llvm/ir/datalayout.h"
// #include "llvm/ir/llvmcontext.h"
#include <memory>

class BuildmoduleJit {
  std::unique_ptr<ExecutionSession> execution_session;
  DataLayout data_layout;
  MangleAndInterner mangle_and_interner;
  RTDyldObjectLinkingLayer object_layer;
  IRCompileLayer ircompile_layer;
  JITDylib &main_dynamic_library;
};
