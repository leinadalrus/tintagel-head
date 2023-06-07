#ifndef FUNCTION_OFFLOAD_ARENA_DATA_H
#define FUNCTION_OFFLOAD_ARENA_DATA_H

#include <stdint.h>

typedef struct ArenaData {
  intptr_t destination, source, table_data;
  uint16_t data_size;
} ArenaData;

typedef struct ArenaState {
  ArenaData arena_data;
} ArenaState;

#endif // !FUNCTION_OFFLOAD_ARENA_DATA_H
