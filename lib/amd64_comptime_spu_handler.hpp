#ifndef AMD64_COMPTIME_SPU_HANDLER_HPP
#define AMD64_COMPTIME_SPU_HANDLER_HPP

#include <cstdint>
#include <cstdio>

class SynergyProcessHandler {
  FILE *file;

public:
  void initialise_distributed_hashtable();
  void deinitialise_distributed_hashtable();

  uint8_t read_file_encoded_u8(uint32_t address_offset);
  uint16_t read_file_encoded_u16(uint32_t address_offset);
  uint32_t read_file_encoded_u32(uint32_t address_offset);

  void write_file_encoded_u8(uint32_t address_offset, uint8_t address_sizetype);
  void write_file_encoded_u16(uint32_t address_offset,
                              uint16_t address_sizetype);
  void write_file_encoded_u32(uint32_t address_offset,
                              uint32_t address_sizetype);
};

class SynergyProcessChannel {};

class SynergyProcessUnitCapture {};

#endif // AMD64_COMPTIME_SPU_HANDLER_HPP
