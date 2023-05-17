#ifndef SPU_TREEWALK_LINTER_HPP
#define SPU_TREEWALK_LINTER_HPP

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace External {
namespace Coreboot {
// enum class Amd64Entry {};
}; // namespace Coreboot
}; // namespace External

namespace SynergisticProcessingUnit {
namespace Lint {
class Thread {};

Thread *create_thread(Thread *anyopaque);
void free_thread(Thread *thread);
void block_thread(Thread *thread);

class Mutex {};

Mutex *create_mutex();
void free_mutex(Mutex *mutex);
void lock_mutex(Mutex *mutex);
void unlock_mutex(Mutex *mutex);
int try_lock_mutex(Mutex *mutex);

void sleep_linting(uint64_t seconds);
}; // namespace Lint
}; // namespace SynergisticProcessingUnit

namespace MicroProgramCounter {
class MicroProgramCounter {};

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
}; // namespace MicroProgramCounter

class ArenaData {
  intptr_t destination, source, table_data;
  uint16_t data_size;

public:
  intptr_t d() { return this->destination; }
  intptr_t s() { return this->source; }
  intptr_t td() { return this->table_data; }
  uint16_t sz() { return this->data_size; }
};

class ArenaState {
  ArenaData state;

public:
  ArenaData arena_state() { return state; }
};

class LintArenaBundle {
  SynergisticProcessingUnit::Lint::Thread thread;
  SynergisticProcessingUnit::Lint::Mutex mutex;
  MicroProgramCounter::MicroProgramCounter microprogram_counter;
};

// TODO Singleton-Strategy Pattern for Contextual-Root-Objects'(s data)
template <typename T> class SingletonStrategy : ArenaState {
  // NOTE members not given a "private:" label before a class body init'd is
  // already privated
  friend class ArenaState; // we want our friend class to be private to be
                           // immutable
  ArenaState _private_arena_state;

protected:
  ArenaState __protected_arena_state__ =
      this->_private_arena_state; // "protected" also means shared between
                                  // inherited classes
};

#endif // SPU_TREEWALK_LINTER_HPP
