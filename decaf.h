#ifndef DECAF_H
#define DECAF_H

#include "SDL.h"
#include <stdbool.h>
#include <stdio.h>
#include "input.h"

int decaf_init(char *title, int logic_width, int logic_height, int scale);
int decaf_quit(void (*destroy)(void));
SDL_Renderer *decaf_get_renderer(void);
SDL_Window *decaf_get_window(void);
void decaf_toggle_fullscreen(void);
bool decaf_is_fullscreen(void);
char decaf_set_window_title(char *title);
char decaf_set_window_icon(char *path);
void decaf_update(void (*update)(float dt), void (*draw)(void));
int decaf_fetch_display_refreshrate(void);
int decaf_fetch_scale(void);
int decaf_fetch_window_size(void);
int decaf_fetch_window_width(void);
int decaf_fetch_window_height(void);
int decaf_fetch_render_width(void);
int decaf_fetch_render_height(void);
void decaf_modding_set(bool choice);
bool decaf_modding_allowed(void);
bool decaf_file_exists(const char *filename);
void decaf_event(SDL_Event event);

#endif
