#ifndef SPE_FUNCTION_OFFLOAD_HOOK_HPP
#define SPE_FUNCTION_OFFLOAD_HOOK_HPP

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct PpeRootRemnant {
  char (*main_image)();
  char (*ppe_stub)(); // must result into a PPE Stub.
} PpeRootRemnant;

typedef struct SpeRootRemnant {
  char (*spe_stub)(); // must result into an SPE Stub
                      // ... transforming for a PPE Stub.
} SpeRootRemnant;

#endif // SPE_FUNCTION_OFFLOAD_HOOK_HPP
