#include "spe_function_offload_hook.hpp"

#ifndef FUNCTION_OFFLOAD_PHANTOM_MARKER_HPP
#define FUNCTION_OFFLOAD_PHANTOM_MARKER_HPP

#ifndef VECTOR_SLICE_CHUNK
#define VECTOR_SLICE_CHUNK 255
#endif

typedef struct FunctionOffloadPhantomMarker {
  int *marker[]; // equivalent to a cursor[][]
} FunctionOffloadPhantomMarker;

#endif // !FUNCTION_OFFLOAD_PHANTOM_MARKER_HPP
