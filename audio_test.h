#ifndef AUDIO_TEST_H
#define AUDIO_TEST_H

#include "libs/miniaudio/miniaudio.h"
#include "SDL.h"

int mini_init(void);
int mini_play(void);
void mini_unload(void);

#endif