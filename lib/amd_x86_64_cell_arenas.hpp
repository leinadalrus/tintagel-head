#ifndef AMD_X86_64_CELL_ARENAS_HPP
#define AMD_X86_64_CELL_ARENAS_HPP

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

class ArenaData {
  void *destination, *source, *table_data;
  uint16_t data_size;
};

class ArenaState {
  ArenaData state;
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

#endif // AMD_X86_64_CELL_ARENAS_HPP
