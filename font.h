#ifndef FONT_H
#define FONT_H

#include "decaf.h"
#include "graphics.h"

#include "SDL_ttf.h"

typedef TTF_Font decaf_font;

void decaf_font_init();
void decaf_font_quit();
TTF_Font *decaf_font_load(const char *filename, int size);
void decaf_font_destroy(TTF_Font *font);
void decaf_font_draw(TTF_Font *font, const char *text, int x, int y, decaf_color color);

#endif
