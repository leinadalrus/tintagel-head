#ifndef FUNCTION_OFFLOAD_MODEL_HOOK_H
#define FUNCTION_OFFLOAD_MODEL_HOOK_H

#include "function_offload_arena_data.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Thread {
} Thread;

Thread *create_thread(Thread *anyopaque);
void free_thread(Thread *thread);
void block_thread(Thread *thread);

typedef struct Mutex {
} Mutex;

Mutex *create_mutex();
void free_mutex(Mutex *mutex);
void lock_mutex(Mutex *mutex);
void unlock_mutex(Mutex *mutex);
int try_lock_mutex(Mutex *mutex);

void sleep_linting(uint64_t seconds);

typedef struct MicroProgramCounter {
} MicroProgramCounter;

int initialize_microprogram_counter();
void deinitialize_microprogram_counter();
void begin_microprogram_counter();
void end_microprogram_counter();

int send_microprogram_counters_packet(uint8_t data, int length,
                                      uint8_t timestamp);
int receive_microprogram_counters_packet(uint8_t data, int length,
                                         uint8_t timestamp);
int send_microprogram_counters_command(uint8_t data, int length,
                                       uint8_t timestamp);
int send_microprogram_counters_reply(uint8_t data, uint8_t timestamp,
                                     uint16_t bitmask);
int send_microprogram_counters_acknowledgement(uint8_t data, int length,
                                               uint8_t timestamp);
int send_microprogram_counters_host_packet(uint8_t data, int length,
                                           uint8_t timestamp);
int receive_microprogram_counters_replies(uint8_t data, uint8_t timestamp,
                                          uint16_t bitmask);

typedef struct MicroProgramBundle {
  Thread thread;
  Mutex mutex;
  MicroProgramCounter microprogram_counter;
} MicroProgramBundle;

#endif // !FUNCTION_OFFLOAD_MODEL_HOOK_H
