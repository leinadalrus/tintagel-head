#ifndef SPE_FUNCTION_ARENA_DATA_H
#define SPE_FUNCTION_ARENA_DATA_H

#include <cstdint>

typedef struct ArenaData {
  void *destination, *source, *table_data;
  uint16_t data_size;
} ArenaData;

typedef struct ArenaState {
  ArenaData arena_data;
} ArenaState;

#endif // SPE_FUNCTION_ARENA_DATA_H
