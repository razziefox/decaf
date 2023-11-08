#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "decaf.h"

enum input_flags {

    DECAF_KEY_A = 4,
    DECAF_KEY_B = 5,
    DECAF_KEY_C = 6,
    DECAF_KEY_D = 7,
    DECAF_KEY_E = 8,
    DECAF_KEY_F = 9,
    DECAF_KEY_G = 10,
    DECAF_KEY_H = 11,
    DECAF_KEY_I = 12,
    DECAF_KEY_J = 13,
    DECAF_KEY_K = 14,
    DECAF_KEY_L = 15,
    DECAF_KEY_M = 16,
    DECAF_KEY_N = 17,
    DECAF_KEY_O = 18,
    DECAF_KEY_P = 19,
    DECAF_KEY_Q = 20,
    DECAF_KEY_R = 21,
    DECAF_KEY_S = 22,
    DECAF_KEY_T = 23,
    DECAF_KEY_U = 24,
    DECAF_KEY_V = 25,
    DECAF_KEY_W = 26,
    DECAF_KEY_X = 27,
    DECAF_KEY_Y = 28,
    DECAF_KEY_Z = 29,
    DECAF_KEY_1 = 30,
    DECAF_KEY_2 = 31,
    DECAF_KEY_3 = 32,
    DECAF_KEY_4 = 33,
    DECAF_KEY_5 = 34,
    DECAF_KEY_6 = 35,
    DECAF_KEY_7 = 36,
    DECAF_KEY_8 = 37,
    DECAF_KEY_9 = 38,
    DECAF_KEY_0 = 39,
    DECAF_KEY_RETURN = 40,
    DECAF_KEY_ESCAPE = 41,
    DECAF_KEY_BACKSPACE = 42,
    DECAF_KEY_TAB = 43,
    DECAF_KEY_SPACE = 44,
    DECAF_KEY_MINUS = 45,
    DECAF_KEY_EQUALS = 46,
    DECAF_KEY_LEFTBRACKET = 47,
    DECAF_KEY_RIGHTBRACKET = 48,
    DECAF_KEY_BACKSLASH = 49,
    DECAF_KEY_NONUSHASH = 50,
    DECAF_KEY_SEMICOLON = 51,
    DECAF_KEY_APOSTROPHE = 52,
    DECAF_KEY_GRAVE = 53,
    DECAF_KEY_COMMA = 54,
    DECAF_KEY_PERIOD = 55,
    DECAF_KEY_SLASH = 56,
    DECAF_KEY_CAPSLOCK = 57,
    DECAF_KEY_F1 = 58,
    DECAF_KEY_F2 = 59,
    DECAF_KEY_F3 = 60,
    DECAF_KEY_F4 = 61,
    DECAF_KEY_F5 = 62,
    DECAF_KEY_F6 = 63,
    DECAF_KEY_F7 = 64,
    DECAF_KEY_F8 = 65,
    DECAF_KEY_F9 = 66,
    DECAF_KEY_F10 = 67,
    DECAF_KEY_F11 = 68,
    DECAF_KEY_F12 = 69,
    DECAF_KEY_PRINTSCREEN = 70,
    DECAF_KEY_SCROLLLOCK = 71,
    DECAF_KEY_PAUSE = 72,
    DECAF_KEY_INSERT = 73,
    DECAF_KEY_HOME = 74,
    DECAF_KEY_PAGEUP = 75,
    DECAF_KEY_DELETE = 76,
    DECAF_KEY_END = 77,
    DECAF_KEY_PAGEDOWN = 78,
    DECAF_KEY_RIGHT = 79,
    DECAF_KEY_LEFT = 80,
    DECAF_KEY_DOWN = 81,
    DECAF_KEY_UP = 82

};

bool decaf_key_pressed(Uint32 key);
int decaf_fetch_mouse_x();
int decaf_fetch_mouse_y();
void decaf_set_KeyboardState();

#endif
