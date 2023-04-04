#include "paex_stereo_channels_private.h"
#include "../lib/portaudio/include/portaudio.h"
#include "../lib/libsndfile/include/sndfile.h"
#include <array>
#include <cmath>
#include <csignal>
#include <fstream>
#include <iostream>

#ifndef MATH_PI
#define MATH_PI (3.14159265)
#endif

#define NUMBER_OF_SECONDS (10)
#define SAMPLE_RATE (44100)
#define AMPLITUDE (0.8)
#define FRAMES_PER_BUFFER (64)
#define TABLE_SIZE (200)

class AudioData
{
  float sine[TABLE_SIZE] = {0};
  int phase = 0;

public:
  constexpr int audio_test_callback(const void *input_buffer, void *output_buffer,
                                    unsigned long frames_per_buffer,
                                    const PaStreamCallbackTimeInfo *time_info,
                                    PaStreamCallbackFlags status_flags,
                                    void *user_data)
  {
    auto *test_data = (AudioData *)user_data;
    float *outputs = (float *)output_buffer;
    unsigned long i = 0;
    int retval = 0;
    /* avoid unused variable warnings */
    (void)input_buffer;
    (void)time_info;
    (void)status_flags;

    for (i = 0; i < frames_per_buffer; i++)
    {
      *outputs++ = test_data->sine[test_data->phase]; /* left */
      test_data->phase += 1;
      if (test_data->phase >= TABLE_SIZE)
        test_data->phase -= TABLE_SIZE;
    }

    return retval;
  } // `constexpr` keyword is great for callback functions
};
