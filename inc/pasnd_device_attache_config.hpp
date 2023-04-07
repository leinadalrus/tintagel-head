#ifndef PASND_DEVICE_ATTACHE_CONFIG_H
#define PASND_DEVICE_ATTACHE_CONFIG_H

// #include <usb.h> // unknown file-type discrepancy occurring in Windows 10 SDK

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
  const unsigned int
  usb_thruput_callback(unsigned int usb_device_info_flag,
                       void *device_data_input, void *device_data_output,
                       unsigned int device_config_data_size);

  constexpr UsbRequestBlockConfig discriminate_frame_value_start(void *device_data_input, unsigned int data_size_last_index, void *device_data_output);
};

class RequestBlockCommand
{
public:
  RequestBlockCommand();                                            // just for general purpose inheritance
  RequestBlockCommand(const UsbRequestBlockConfig &copyable_rhs);   // contructor for 'rhs' copying
  RequestBlockCommand(const UsbRequestBlockConfig *moveable_rhs[]); // in a sense I have created: `**moveable_rhs`
public:
  void execute_command_block_request();
};

class RequestBlockHandler : public RequestBlockCommand
{
  RequestBlockCommand urb_command = RequestBlockCommand{};

public:
  void execute_command_block_request()
  {
    handle_command_block_request();
  }

  void handle_command_block_request();
};

// Structure of Arrays vs Array of Structures (no date). Available at: https://stackoverflow.com/a/17924782.
// If you are going to be accessing the R/G/B components of each pixel concurrently then AoS usually makes sense,
// since the successive reads of R, G, B components will be contiguous and usually contained within the same cache line.
// For CUDA this also means memory read/write coalescing.
template <typename Chunksize>
class RequestBlockAos
{
public:
  char *device_data_input;
  char *device_data_output;
  Chunksize device_config_data_size;
}; // Request Block Array of Structures

// However if you are going to process color planes separately then SoA might be preferred, 
// e.g. if you want to scale all R values by some scale factor, 
// then SoA means that all R components will be contiguous.
template <typename Definition, typename Slice>
class RequestBlockSoa
{
public:
  Definition device_data_input[Slice];
  Definition device_data_output[Slice];
  Definition device_config_data[Slice];
}; // Request Block Structure of Arrays

#endif // !#ifndef PASND_DEVICE_ATTACHE_CONFIG_H
