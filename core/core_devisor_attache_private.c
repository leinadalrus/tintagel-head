#include "../inc/core_devisor_attache_private.h"

void *nullify_service(NullService *self) { return self; };

void attach_devise_null_service(DevisorAttache *d_attache,
                                NullService *n_serv)
{
  d_attache = nullify_service(n_serv);
}

void initialise_service(AudioService *audio_service, void *null_service)
{
  audio_service = null_service;
} // identifier "null_audio_service" must be undefined

AudioService *retreive_service(AudioService *audio_service)
{
  return audio_service;
}

void provide_service(
    AudioService *audio_service_prev,
    AudioService *audio_service_next) // removed static keyword to prevent
                                      // type-relativity error
{
  if (audio_service_next == 0)
  {
    initialise_service(audio_service_next, 0);
  }

  audio_service_prev = audio_service_next;
}

void run_sound(int sound_id) {}

void mute_sound(int sound_id) {}

void nullify_sound(int sound_id)
{ /* Do nothing. */
}