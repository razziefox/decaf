#ifndef AUDIO_H
#define AUDIO_H

#include "SDL_mixer.h"

typedef Mix_Chunk decaf_sound;
typedef Mix_Music decaf_music;

void decaf_audio_init(void);
Mix_Chunk *decaf_audio_loadSound(char *filename);
void decaf_audio_playSound(Mix_Chunk *sound);
Mix_Music *decaf_audio_loadMusic(char *filename);
void decaf_audio_playMusic(Mix_Music *music);
void decaf_audio_stopMusic(void);
void decaf_audio_pauseMusic(void);
void decaf_audio_resumeMusic(void);
void decaf_audio_setMusicVolume(int volume);
void decaf_audio_setSoundVolume(int volume);
void decaf_audio_quit(void);
void decaf_audio_destroySound(Mix_Chunk *sound);
void decaf_audio_destroyMusic(Mix_Music *music);

#endif
