#define SAMPLE_RATE (44100)
#include "components_wrangler_private.h"
#include "../lib/portaudio/include/portaudio.h"
#include "../lib/libsndfile/include/sndfile.h"
#include <array>
#include <fstream>
#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

template <class T, class E>
Result<T, E>::Result(T type, E expected) {}

class AudioPhaser
{
  float left_channel;
  float right_channel;
};

class AudioManager
{
};

class SoundName
{
};

class SoundEntity
{
};

class AudioBundle
{
  AudioPhaser *channel_phaser;
  SoundName *soundfile_name;
  SoundEntity *sound_entity;
};

class LevelForeground
{
};

class LevelBackground
{
};

class LevelDatum
{
  LevelForeground foreground;
  LevelBackground background;

public:
  LevelDatum(LevelForeground foreground, LevelBackground background);
};

void handle_signalled_exit(int index)
{
  switch (index)
  {
  case SIGTERM:
    break;
  }
} // Best way to exit a program gracefully without using pkill (no date). Available at: https://stackoverflow.com/a/8906773.

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

  return &LevelDatum::LevelDatum(foreground, background);
} // NOTE: constexpr cannot have an non-literal return type.

constexpr int audio_test_callback(const void *input_buffer, void *output_buffer,
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

const bool init_audio_system()
{
  auto pa_err = Pa_Initialize();
  if (pa_err == paNoError)
  {
    pa_err = Pa_Terminate();
  }
  printf("PortAudio error: %s\n", Pa_GetErrorText(pa_err));

  Pa_Sleep(44100);

  return pa_err;
}

const bool open_default_audio(PaStream *audio_stream, char *user_data)
{
  AudioTestData *audio_data = (AudioTestData *)user_data;
  PaError pa_err = Pa_OpenDefaultStream(&audio_stream, 0, 2, paFloat32, SAMPLE_RATE, 256, audio_test_callback, &audio_data);
  if (pa_err == paNoError)
  {
    pa_err = Pa_StopStream(audio_data);
  }

  return 0;
}

void UserHandler::handle_user_command(UserCommand user_command) {}