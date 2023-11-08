#include "input.h"

const Uint8 *keyState;

bool decaf_key_pressed(Uint32 key) {

    if(keyState[key]) {

        return true;

    } else {
            
            return false;
    
    }

}

void decaf_set_KeyboardState() {

    keyState = SDL_GetKeyboardState(NULL);

}

int decaf_fetch_mouse_x() {

    int x, y;
    float log_x, log_y;
    SDL_GetMouseState( &x, &y );

    SDL_RenderWindowToLogical(decaf_get_renderer(), x, y, &log_x, &log_y);

    return log_x;

}

int decaf_fetch_mouse_y() {

    int x, y;
    float log_x, log_y;
    SDL_GetMouseState( &x, &y );

    SDL_RenderWindowToLogical(decaf_get_renderer(), x, y, &log_x, &log_y);

    return log_y;

}