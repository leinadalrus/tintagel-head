#ifndef PASND_AUDIO_SERVICE_HPP
#define PASND_AUDIO_SERVICE_HPP

#include <cstdio>
#include <cstdlib>

class PasndService
{
public:
  PasndService(PasndService *rhs[]); // move constructor
  PasndService(PasndService &rhs);   // copy constructor

  void run_sound(int sound_id);
  void mute_sound(int sound_id);
};

class AudioServiceLocator
{
  static PasndService *audio_service;
  NullAudioService *null_audio_service = &NullAudioService{}; // we are going to have -Waddress-of-temporary occur with this member.

public:
  void initialise_service() { audio_service = null_audio_service; } // identifier "null_audio_service" must be undefined
  static PasndService *retreive_service() { return audio_service; }
  void provide_service(PasndService *audio) // removed static keyword to prevent type-relativity error
  {
    if (audio == 0)
    {
      initialise_service();
    }

    audio_service = audio;
  }
};

class NullAudioService : public PasndService
{
public:
  NullAudioService();
  void run_sound(int sound_id)
  { /* Do nothing. */
  }
  void mute_sound(int sound_id)
  { /* Do nothing. */
  }
};

#endif // PASND_AUDIO_SERVICE_HPP