#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "decaf.h"

#include "stdio.h"

#include "SDL.h"

typedef SDL_Texture decaf_texture;

typedef SDL_Rect decaf_rect;
typedef SDL_FRect decaf_frect;

typedef SDL_Color decaf_color;

void decaf_set_bg_color(int r, int g, int b);
SDL_Texture *decaf_graphics_load(char *path);

void decaf_graphics_image(SDL_Texture *texture, SDL_Rect *rect);
void decaf_graphics_imagef(SDL_Texture *texture, SDL_FRect *rect);
void decaf_graphics_sprite(SDL_Texture *texture, int cell, SDL_Rect *rect);
void decaf_graphics_spritef(SDL_Texture *texture, int cell, SDL_FRect *rect);
void destroy_texture(SDL_Texture *texture);

#endif
