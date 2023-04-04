#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PASND_AUDIO_COMPONENTS_PRIVATE
#define PASND_AUDIO_COMPONENTS_PRIVATE

const unsigned int SampleRate = 44100;

typedef struct AudioTestData
{
  float left_channel_phase;
  float right_channel_phase;
} AudioTestData;

typedef struct LeftChannelPhaser
{
  float left_channel;
} LeftChannelPhaser;

typedef struct RightChannelPhaser
{
  float right_channel;
} RightChannelPhaser;

typedef struct AudioChannelsPhases
{
  LeftChannelPhaser left_channel;
  RightChannelPhaser right_channel;
} AudioChannelsPhases;

typedef struct PASNDError
{
  AudioTestData data;
} PASNDError;

typedef struct PASNDFilename
{
  const char *filename[sizeof(char)];
} PASNDFilename; // remember, an array bracket `[]` represents a pointer `*`

typedef struct PASNDEntity
{
  char(*entity)(PASNDEntity self);
} PASNDEntity;

typedef struct PASNDBundle
{
  AudioTestData information;
  PASNDFilename filename;
  PASNDEntity entity;
} PASNDBundle;

#endif