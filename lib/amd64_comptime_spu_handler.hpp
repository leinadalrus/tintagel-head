#ifndef AMD64_COMPTIME_SPU_HANDLER_HPP
#define AMD64_COMPTIME_SPU_HANDLER_HPP

#include "spu_treewalk_linter.hpp"
#include <cstdint>
#include <cstdio>

class SynergisticProcessingUnitHandler {
  FILE *file;

public:
  int initialize_table_data();
  void deinitialize_table_data();
  void reset_processing_unit();
  void stop_processing_unit();

  void set_microprogram_power_count(uint32_t power_count);
  void set_bias(uint16_t bias);
  void set_degrade_bit_by_ten(int enable);
  void set_apply_bias(int enable);

  uint8_t read_file_encoded_u8(uint32_t address_offset);
  uint16_t read_file_encoded_u16(uint32_t address_offset);
  uint32_t read_file_encoded_u32(uint32_t address_offset);

  void write_file_encoded_u8(uint32_t address_offset, uint8_t address_sizetype);
  void write_file_encoded_u16(uint32_t address_offset,
                              uint16_t address_sizetype);
  void write_file_encoded_u32(uint32_t address_offset,
                              uint32_t address_sizetype);
};

template <typename T> class SynergisticProcessingUnitCapture {
  uint32_t number;
  uint32_t count;
  uint32_t source_address;
  uint32_t destination_address;

  uint16_t timer_reload;
  uint32_t cursor_position;
  uint32_t length;

  uint32_t fifo[8];
  uint32_t fifo_read_position;
  uint32_t fifo_write_position;
  uint32_t fifo_read_offset;
  uint32_t fifo_write_offset;
  uint32_t fifo_level;

  void fifo_flush_data();
  T fifo_write_data();

  void set_count(uint8_t data);
  void set_destination_address(uint32_t data);
  void set_timer_reload(uint32_t data);
  void set_length(uint32_t);

  void start();
  void run(int32_t data);

  void bus_write_u32(uint32_t address, uint64_t data);
};

#endif // AMD64_COMPTIME_SPU_HANDLER_HPP
