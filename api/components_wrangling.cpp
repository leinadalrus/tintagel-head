#define SAMPLE_RATE (44100)
#include "components_wrangler_private.h"
#include "../lib/portaudio/include/portaudio.h"
#include "../lib/libsndfile/include/sndfile.h"
#include "../lib/soloud/include/soloud.h"

template <class T, class E> Result<T, E>::Result(T type, E expected) {}

void UserHandler::handle_user_command(UserCommand user_command) {}

static int audio_test_callback(const void *input_buffer, void *output_buffer,
                               unsigned long frames_per_buffer,
                               const PaStreamCallbackTimeInfo *time_info,
                               PaStreamCallbackFlags status_flags,
                               void *user_data) {
  AudioTestData *audio_tester = (AudioTestData*)user_data;
  float *output = (float*)output_buffer;
  unsigned int index = 0;

  // for (index = 0; index < frames_per_buffer; index++) {
  //   output += audio_tester->left_channel_phase;
  //   output += audio_tester->right_channel_phase;
  // }

  return 0;
}