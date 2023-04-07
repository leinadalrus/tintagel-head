#include "../inc/pasnd_device_attache_config.hpp"

SerialDeviceConfig::SerialDeviceConfig() {}

constexpr unsigned int SerialDeviceConfig::usb_thruput_callback(
    unsigned int usb_device_info_flag, void *device_data_input,
    void *device_data_output, unsigned int device_config_data_size)
{
  return usb_device_info_flag;
}
