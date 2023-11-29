#include "input.h"

const Uint8 *keyState;

// checks if key is pressed
bool decaf_key_pressed(Uint32 key) {

    if(keyState[key]) {

        return true;

    } else {
            
            return false;
    
    }

}

// sets the current keystate
void decaf_set_KeyboardState(void) {

    keyState = SDL_GetKeyboardState(NULL);

}

// returns the current mouse position x
int decaf_fetch_mouse_x(void) {

    int x, y;
    float log_x, log_y;
    SDL_GetMouseState( &x, &y );

    SDL_RenderWindowToLogical(decaf_get_renderer(), x, y, &log_x, &log_y);

    return log_x;

}

// returns the current mouse position y
int decaf_fetch_mouse_y(void) {

    int x, y;
    float log_x, log_y;
    SDL_GetMouseState( &x, &y );

    SDL_RenderWindowToLogical(decaf_get_renderer(), x, y, &log_x, &log_y);

    return log_y;

}