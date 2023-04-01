#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum class Errors {
  None = 0,
  Found = 1,
};

template <typename T, typename E> class Result {
  Result(T type, E expected);
};

class UserName(string);
class UserEntity;
class UserBundle {
  UserName *name;
  UserEntity *entity;
};

class UserCommand {
public:
  void execute_user_command();
};

class UserHandler : public UserCommand {
  UserCommand *user_command;

public:
  void execute_user_command() {
    handle_user_command(*UserHandler::user_command);
  }
  UserBundle *init_user_table() {
    UserBundle *user_bundle = &UserBundle{};
    return user_bundle;
  }
  void handle_user_command(UserCommand user_command);
};

class LeftChannelPhase;
class RightChannelPhase;

class AudioTestData {
  float left_channel_phase;
  float right_channel_phase;
};

#endif // COMPONENTS_H