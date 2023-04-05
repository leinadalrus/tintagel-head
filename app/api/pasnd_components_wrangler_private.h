#ifndef PASND_COMPONENTS_WRANGLER_PRIVATE_H
#define PASND_COMPONENTS_WRANGLER_PRIVATE_H

#include "../lib/portaudio/include/portaudio.h"
#include "../lib/libsndfile/include/sndfile.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <csignal>

enum class Errors
{
  None = 0,
  Found = 1,
};

template <typename T, typename E>
class Result
{
  Result(T type, E expected);
};

class UserName
{
  const char *user_name = "";
};
class UserEntity;
class UserBundle
{
  UserName *name;
  UserEntity *entity;
};

class UserCommand
{
public:
  void execute_user_command();
};

class UserHandler : public UserCommand
{
  UserCommand *user_command;

public:
  void execute_user_command()
  {
    handle_user_command(*UserHandler::user_command);
  }
  UserBundle *init_user_table()
  {
    UserBundle *user_bundle = &UserBundle{};
    return user_bundle;
  }
  void handle_user_command(UserCommand user_command);
};

class UserData : public UserHandler
{
  char *user_data = (char *)0;

public:
  void handle_user_command(UserCommand user_command);
  char *selfish()
  {
    return this->user_data;
  }
};

class LeftChannelPhase;
class RightChannelPhase;

class AudioData
{
  float sine[200] = {0};
  int phase = 0;

public:
  const int audio_data_callback(const void *input_buffer, void *output_buffer,
                                unsigned long frames_per_buffer,
                                const PaStreamCallbackTimeInfo *time_info,
                                PaStreamCallbackFlags status_flags,
                                void *user_data)
  {
    AudioData *test_data = (AudioData *)user_data;
    float *out = (float *)output_buffer;
    unsigned long i;
    int finished = 0;
    /* avoid unused variable warnings */
    (void)input_buffer;
    (void)time_info;
    (void)status_flags;

    for (i = 0; i < frames_per_buffer; i++)
    {
      *out++ = test_data->sine[test_data->phase]; /* left */
      test_data->phase += 1;
      if (test_data->phase >= 200)
        test_data->phase -= 200;
    }

    return finished;
  }
};

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

constexpr int audio_data_callback(const void *input_buffer, void *output_buffer,
                                  unsigned long frames_per_buffer,
                                  const PaStreamCallbackTimeInfo *time_info,
                                  PaStreamCallbackFlags status_flags,
                                  void *user_data)
{
  float *outputs = (float *)output_buffer;
  float sine[200] = {0};
  int phase = 0;
  unsigned long i = 0;
  int finished = 0;
  /* avoid unused variable warnings */
  (void)input_buffer;
  (void)time_info;
  (void)status_flags;

  for (i = 0; i < frames_per_buffer; i++)
  {
    *outputs++ = sine[phase]; /* left */
    phase += 1;
    if (phase >= 200)
      phase -= 200;
  }
} // `constexpr` keyword is great for callback functions

void handle_signalled_exit(int index)
{
  switch (index)
  {
  case SIGTERM:
    break;
  }
} // Best way to exit a program gracefully without using pkill (no date). Available at: https://stackoverflow.com/a/8906773.

#endif // PASND_COMPONENTS_WRANGLER_PRIVATE_H