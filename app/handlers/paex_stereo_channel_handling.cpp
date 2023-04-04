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

class AudioTestData
{
    float sine[TABLE_SIZE] = {0};
    int phase = 0;
};

