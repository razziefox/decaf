#ifndef AUDIO_TEST_H
#define AUDIO_TEST_H

#include "libs/miniaudio/miniaudio.h"
#include "SDL.h"

typedef ma_sound decaf_mini_sound;

int mini_init(void);
int mini_play(void);
void mini_unload(void);
ma_sound *mini_load(char *audio_path);
void mini_play_file(ma_sound *sound);
void mini_stop(ma_sound *sound);
bool mini_ended(ma_sound *sound);

#endif