#define FRAMES_PER_BUFFER (64)
#define SAMPLE_RATE (44100)
#define CHANNEL_COUNT (2)
#include "../inc/pasnd_components_wrangler_private.hpp"
#include "../lib/portaudio/include/pa_asio.h"
#include <array>
#include <fstream>
#include <iostream>

template <class T, class E>
Result<T, E>::Result(T type, E expected) {}

constexpr bool level_document_callback(FILE document, char *user, char *data, uint8_t size, uint8_t nmemb)
{
  // user = @intToPtr(std.ArrayList(i32), user);
  // data = @intToPtr(std.ArrayList(i32), data);
  // size = std.heap.ArenaAllocator.init(std.heap.c_allocator);
  // nmemb = @intToPtr([*]u8, @ptrToInt(nmemb));
  // template = @intToPtr(data, user);
  // return imps.File{};
  return false;
} // TODO: single-threading must be done. No Singleton! No!

constexpr bool transpose_level_document(FILE document, uint8_t data_size, char *items_expected, char *items_parsed)
{
  bool callbacker = level_document_callback(document, items_parsed, items_expected, data_size, 0);
  if (callbacker != true)
  {
    std::printf("An error has occurred!");
    signal(SIGTERM, handle_signalled_exit);
  }

  return callbacker;
}

constexpr LevelDatum *discriminate_orthographic_layers()
{
  LevelForeground foreground = LevelForeground{};
  LevelBackground background = LevelBackground{};
  // TODO(Daniel): std::move std::copy
  LevelDatum *level_datum = &LevelDatum(foreground, background); // NOTE(Daniel): -Waddress-of-temporary

  return level_datum;
} // NOTE: constexpr cannot have an non-literal return type

const bool
init_audio_system()
{
  auto pa_err = Pa_Initialize();
  if (pa_err == paNoError)
  {
    pa_err = Pa_Terminate();
    printf("PortAudio error: %s\n", Pa_GetErrorText(pa_err));
  }

  Pa_Sleep(44100);

  return pa_err;
}

constexpr PaStream *open_default_audio(PaStream *audio_stream, char *user_data)
{
  AudioData *audio_data = (AudioData *)user_data;
  PaError pa_err = Pa_OpenDefaultStream(&audio_stream, 0, 2, paFloat32, SAMPLE_RATE, 256, audio_data_callback, &audio_data);
  if (pa_err == paNoError)
  {
    pa_err = Pa_StopStream(audio_data);
  }

  return audio_stream;
}

const bool query_devisor_attache()
{
  PaError pa_err = Pa_Initialize();

  int device_amount = 1;
  device_amount = Pa_GetDeviceCount();
  const PaDeviceInfo *device_info = 0;

  const PaStreamParameters *input_parameters = 0;
  const PaStreamParameters *output_parameters = 0;

  if (device_amount < 0)
  {
    pa_err = device_amount;
    signal(SIGTERM, handle_signalled_exit);
  }

  for (int index = 0; index < device_amount; index++)
  {
    device_info = Pa_GetDeviceInfo(index);
  }

  pa_err = Pa_IsFormatSupported(input_parameters, output_parameters, SAMPLE_RATE);
  if (pa_err == paFormatIsSupported)
  {
    printf("Hooray!\n");
  }
  else
  {
    printf("Too Bad.\n");
  }

  return false;
}

constexpr bool stream_processed_data(PaStream *audio_stream, void *user_data)
{
  if (signal(SIGTERM, handle_signalled_exit))
  {
    Pa_Terminate();
  }

  PaStreamParameters *input_parameters = (PaStreamParameters *)user_data;
  PaStreamParameters *output_parameters = (PaStreamParameters *)user_data;
  PaAsioStreamInfo *asio_output_info = (PaAsioStreamInfo *)user_data;

  return false;

  auto audio_data = new AudioData;
  PaError pa_err = Pa_OpenDefaultStream(&audio_stream, 0, 2, paFloat32, SAMPLE_RATE, 256, audio_data_callback, &audio_data);
  // unsigned long frames_per_buffer = 64; // could be paFramesPerBufferUnspecified, in which case PortAudio will do its best to manage it for you, but, on some platforms, the framesPerBuffer will change in each call to the callback

  int input_device_amount = 1;
  int output_device_amount = 1;
  input_device_amount = Pa_GetDeviceCount();
  output_device_amount = Pa_GetDeviceCount();

  // bzero(&input_parameters, sizeof(input_parameters)); // not necessary if you are filling in all the fields
  input_parameters->channelCount = 2;
  input_parameters->device = input_device_amount;
  input_parameters->hostApiSpecificStreamInfo = NULL;
  input_parameters->sampleFormat = paFloat32;
  input_parameters->suggestedLatency = Pa_GetDeviceInfo(input_device_amount)->defaultLowInputLatency;
  input_parameters->hostApiSpecificStreamInfo = NULL; // See you specific host's API docs for info on using this field
  // bzero(&output_parameters, sizeof(output_parameters)); // not necessary if you are filling in all the fields
  output_parameters->channelCount = 2;
  output_parameters->device = output_device_amount;
  output_parameters->hostApiSpecificStreamInfo = NULL;
  output_parameters->sampleFormat = paFloat32;
  output_parameters->suggestedLatency = Pa_GetDeviceInfo(output_device_amount)->defaultLowOutputLatency;
  output_parameters->hostApiSpecificStreamInfo = NULL; // See you specific host's API docs for info on using this field

  /* Use an ASIO specific structure. WARNING - this is not portable. */
  asio_output_info->size = sizeof(PaAsioStreamInfo);
  asio_output_info->hostApiType = paASIO;
  asio_output_info->version = 1;
  asio_output_info->flags = paAsioUseChannelSelectors;
  int output_channel_selectors[2] = {0, 1}; /* skip channel 0 and use the second (right) ASIO device channel */
  asio_output_info->channelSelectors = output_channel_selectors;
  output_parameters->hostApiSpecificStreamInfo = &asio_output_info;

  pa_err = Pa_OpenStream(
      &audio_stream,
      input_parameters,
      output_parameters,
      SAMPLE_RATE,
      FRAMES_PER_BUFFER,
      paNoFlag,            // flags that can be used to define dither, clip settings and more
      audio_data_callback, // your callback function
      (void *)0);          // data to be passed to callback. In C++, it is frequently (void *)this
  // don't forget to check errors!
  return false;
}

void UserData::handle_user_command(UserCommand user_command)
{
  query_devisor_attache();
  stream_processed_data(open_default_audio, this->selfish());
}