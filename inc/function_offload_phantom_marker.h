#ifndef FUNCTION_OFFLOAD_PHANTOM_MARKER_H
#define FUNCTION_OFFLOAD_PHANTOM_MARKER_H

#ifndef VECTOR_SLICE_CHUNK
#define VECTOR_SLICE_CHUNK 255
#endif // !VECTOR_SLICE_CHUNK

typedef struct FunctionOffloadPhantomMarker {
  int *marker[VECTOR_SLICE_CHUNK];
} FunctionOffloadPhantomMarker;

#endif // !FUNCTION_OFFLOAD_PHANTOM_MARKER_H
