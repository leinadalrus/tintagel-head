#ifndef PASND_COMPONENTS_WRANGLER_PRIVATE_H
#define PASND_COMPONENTS_WRANGLER_PRIVATE_H

#include <cstring>
#include <cstdio>
#include <cstdlib>

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

class AudioTestData
{
  float left_channel_phase;
  float right_channel_phase;
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

#endif // PASND_COMPONENTS_WRANGLER_PRIVATE_H