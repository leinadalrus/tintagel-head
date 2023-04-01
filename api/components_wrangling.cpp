#define SAMPLE_RATE (44100)
#include "components_wrangler_private.h"
#include "../lib/portaudio/include/portaudio.h"
#include "../lib/libsndfile/include/sndfile.h"

template <class T, class E>
Result<T, E>::Result(T type, E expected) {}

void UserHandler::handle_user_command(UserCommand user_command) {}

const int audio_test_callback(const void *input_buffer, void *output_buffer,
                               unsigned long frames_per_buffer,
                               const PaStreamCallbackTimeInfo *time_info,
                               PaStreamCallbackFlags status_flags,
                               void *user_data)
{
  AudioTestData *audio_tester = (AudioTestData *)user_data;
  float *output = (float *)output_buffer;
  unsigned int index = 0;

  // for (index = 0; index < frames_per_buffer; index++) {
  //   output += audio_tester->left_channel_phase;
  //   output += audio_tester->right_channel_phase;
  // }

  return 0;
}

const bool init_pa_system()
{
  auto pa_err = Pa_Initialize();
  if (pa_err == paNoError) {
    pa_err = Pa_Terminate();
  }
  printf("PortAudio error: %s\n", Pa_GetErrorText(pa_err));

  Pa_Sleep(44100);

  return pa_err;
}

const bool open_audio_as_defaulted(PaStream *audio_stream, char *user_data)
{
  AudioTestData *audio_data = (AudioTestData *)user_data;
  PaError pa_err = Pa_OpenDefaultStream(&audio_stream, 0, 2, paFloat32, SAMPLE_RATE, 256, audio_test_callback, &audio_data);
  if (pa_err == paNoError) {
    pa_err = Pa_StopStream(audio_data);;
  }

  return 0;
}