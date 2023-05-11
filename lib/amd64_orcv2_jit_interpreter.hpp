#ifndef AMD64_ORCV2_JIT_INTERPRETER_HPP
#define AMD64_ORCV2_JIT_INTERPRETER_HPP

#include <cstdint>

#ifdef AMD64_ORC_JIT_INTERPRETER_HPP
extern int amd64_orcv2_jit_interpreter_toggle;
#endif

class MemoryRegion {
public:
  uint8_t memory;
  uint32_t mask;
};

class OrcV2 {};

class OrcV2Jit : OrcV2 {};

class Amd64Interpreter {};

#endif // !AMD64_ORCV2_JIT_INTERPRETER_HPP
