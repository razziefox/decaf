#ifndef GAME_H
#define GAME_H

#include "decaf/graphics.h"
#include "decaf/input.h"
#include "decaf/audio.h"

void load();
void update(float dt);
void draw();
void destroy();

#endif