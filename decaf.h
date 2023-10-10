#ifndef DECAF_H
#define DECAF_H

#include "SDL2/SDL.h"
#include <stdbool.h>
#include <stdio.h>
#include "input.h"

int decaf_init(char *title, int logic_width, int logic_height, int scale);
void decaf_quit(void (*destroy)(void));
SDL_Renderer *decaf_get_renderer();
SDL_Window *decaf_get_window();
void decaf_toggle_fullscreen();
bool decaf_is_fullscreen();
char decaf_set_window_title(char *title);
char decaf_set_window_icon(char *path);
void decaf_update(void (*update)(float dt), void (*draw)(void));
int decaf_fetch_display_refreshrate();
int decaf_fetch_scale();
int decaf_fetch_window_size();
int decaf_fetch_window_width();
int decaf_fetch_window_height();
int decaf_fetch_render_width();
int decaf_fetch_render_height();
void decaf_set_modding(bool choice);
bool decaf_fetch_modding_allowed();
bool decaf_is_file_exists(const char *filename);

#endif
