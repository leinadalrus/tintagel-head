#ifndef PASND_DEVICE_ATTACHE_CONFIG_H
#define PASND_DEVICE_ATTACHE_CONFIG_H

#include <usb.h>

typedef enum UsbCompletes
{
} UsbCompletes,
    *UsbCompletesPtr;

class UsbRequestBlockConfig
{
  // (IN) device and pipe specify the endpoint queue
  typedef struct usb_device *associated_device; // pointer to associated USB device
  unsigned int endpoint_information;            // endpoint information aka pipe

  unsigned int transfer_flags; // URB_ISO_ASAP, URB_SHORT_NOT_OK, etc.

  // (IN) all urbs need completion routines
  void *context;                // context for completion routine
  UsbCompletesPtr complete_ptr; // pointer to completion routine

  // (OUT) status after each completion
  int status; // returned status

  // (IN) buffer used for data transfers
  void *transfer_buffer;                // associated data buffer
  unsigned long transfer_buffer_length; // data buffer length
  int number_of_packets;                // size of iso_frame_desc

  // (OUT) sometimes only part of CTRL/BULK/INTR transfer_buffer is used
  unsigned long actual_length; // actual data buffer length

  // (IN) setup stage for CTRL (pass a struct usb_ctrlrequest)
  unsigned char *setup_packet; // setup packet (control only)

  // Only for PERIODIC transfers (ISO, INTERRUPT)
  // (IN/OUT) start_frame is set unless URB_ISO_ASAP isn't set
  int start_frame; // start frame
  int interval;    // polling interval

  // ISO only: packets are only "best effort"; each can have errors
  int error_count; // number of errors
  typedef struct UsbIsoPacketDescriptor iso_frame_desc[0];
};

class SerialDeviceConfig
{
  SerialDeviceConfig();
  UsbRequestBlockConfig usb_device_ini =
      UsbRequestBlockConfig{}; // NOTE(Daniel): temporary address occurs with a &&
                               // signature.
public:
  constexpr unsigned int
  usb_thruput_callback(unsigned int usb_device_info_flag,
                       void *device_data_input, void *device_data_output,
                       unsigned int device_config_data_size);
};

#endif // !#ifndef PASND_DEVICE_ATTACHE_CONFIG_H
#define PASND_DEVICE_ATTACHE_CONFIG_H
