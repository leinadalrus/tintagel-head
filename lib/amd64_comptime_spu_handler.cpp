#include "../lib/amd64_comptime_spu_handler.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>

int SynergisticProcessingUnitHandler::initialize_table_data() { return 0; }

void SynergisticProcessingUnitHandler::deinitialize_table_data() {}

void SynergisticProcessingUnitHandler::reset_processing_unit() {}

void SynergisticProcessingUnitHandler::stop_processing_unit() {}

void SynergisticProcessingUnitHandler::set_microprogram_power_count(
    uint32_t power_count) {}

void SynergisticProcessingUnitHandler::set_bias(uint16_t bias) {}

void SynergisticProcessingUnitHandler::set_degrade_bit_by_ten(int enable) {
  switch (enable) {}
}

void SynergisticProcessingUnitHandler::set_apply_bias(int enable) {
  switch (enable) {}
}

uint8_t SynergisticProcessingUnitHandler::read_file_encoded_u8(
    uint32_t address_offset) {
  return 0;
}

uint16_t SynergisticProcessingUnitHandler::read_file_encoded_u16(
    uint32_t address_offset) {
  return 0;
}

uint32_t SynergisticProcessingUnitHandler::read_file_encoded_u32(
    uint32_t address_offset) {
  return 0;
}

void SynergisticProcessingUnitHandler::write_file_encoded_u8(
    uint32_t address_offset, uint8_t address_sizetype) {}

void SynergisticProcessingUnitHandler::write_file_encoded_u16(
    uint32_t address_offset, uint16_t address_sizetype) {}

void SynergisticProcessingUnitHandler::write_file_encoded_u32(
    uint32_t address_offset, uint32_t address_sizetype) {}

template <typename T>
void SynergisticProcessingUnitCapture<T>::fifo_flush_data() {}

template <typename T> T SynergisticProcessingUnitCapture<T>::fifo_write_data() {
  return 0;
}

template <typename T>
void SynergisticProcessingUnitCapture<T>::set_count(uint8_t data) {}

template <typename T>
void SynergisticProcessingUnitCapture<T>::set_destination_address(
    uint32_t data) {}

template <typename T>
void SynergisticProcessingUnitCapture<T>::set_timer_reload(uint32_t data) {}

template <typename T>
void SynergisticProcessingUnitCapture<T>::set_length(uint32_t) {}

template <typename T> void SynergisticProcessingUnitCapture<T>::start() {}

template <typename T>
void SynergisticProcessingUnitCapture<T>::run(int32_t data) {}

template <typename T>
void SynergisticProcessingUnitCapture<T>::bus_write_u32(uint32_t address,
                                                        uint64_t data) {}
