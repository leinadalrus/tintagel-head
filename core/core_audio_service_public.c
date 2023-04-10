#include "../lib/libsndfile/include/sndfile.h"
#include "../lib/portaudio/include/portaudio.h"
#include "../inc/core_audio_components_private.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_signalled_exit(int index)
{
  switch (index)
  {
  case SIGTERM:
    break;
  }
} // Best way to exit a program gracefully without using pkill (no date).
  // Available at: https://stackoverflow.com/a/8906773.

const unsigned int level_document_callback(FILE document, char *user,
                                           char *data, const unsigned char size,
                                           const unsigned char nmemb)
{
  // user = @intToPtr(std.ArrayList(i32), user);
  // data = @intToPtr(std.ArrayList(i32), data);
  // size = std.heap.ArenaAllocator.init(std.heap.c_allocator);
  // nmemb = @intToPtr([*]u8, @ptrToInt(nmemb));
  // template = @intToPtr(data, user);
  // return imps.File{};
  return 0;
} // TODO: single-threading must be done. No Singleton! No!

const unsigned int transpose_level_document(FILE document, const unsigned char data_size,
                                            char *items_expected,
                                            char *items_parsed)
{
  unsigned int callbacker = level_document_callback(
      document, items_parsed, items_expected, data_size, 0);
  if (callbacker != 1)
  {
    printf("An error has occurred!");
    signal(SIGTERM, handle_signalled_exit);
  }

  return callbacker;
}

PaStreamCallback *
audio_test_callback(const void *input_buffer, void *output_buffer,
                    unsigned long frames_per_buffer,
                    const PaStreamCallbackTimeInfo *time_info,
                    PaStreamCallbackFlags status_flags, void *user_data)
{

  PaStreamCallback *stream_callback;
  AudioTestData *audio_tester = (AudioTestData *)user_data;
  float *output = (float *)output_buffer;
  unsigned int index = 0;

  // for (index = 0; index < frames_per_buffer; index++) {
  //   output += audio_tester->left_channel_phase;
  //   output += audio_tester->right_channel_phase;
  // }

  return stream_callback;
}

const unsigned int init_audio_system()
{
  PaError pa_err = Pa_Initialize();
  if (pa_err == paNoError)
  {
    pa_err = Pa_Terminate();
  }
  printf("PortAudio error: %s\n", Pa_GetErrorText(pa_err));

  Pa_Sleep(44100);

  return pa_err;
}

const unsigned int open_default_audio(PaStream *audio_stream, char *user_data)
{
  AudioTestData *audio_data = (AudioTestData *)user_data;
  PaError pa_err =
      Pa_OpenDefaultStream(&audio_stream, 0, 2, paFloat32, SampleRate, 256,
                           audio_test_callback, &audio_data);
  if (pa_err == paNoError)
  {
    pa_err = Pa_StopStream(audio_data);
  }

  return 0;
}