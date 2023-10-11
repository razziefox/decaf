#include "decaf.h"

SDL_Window *window;
SDL_Renderer *renderer;
bool running = true;
SDL_Event event;
bool allow_mods = false;

int decaf_init(char *title, int logic_width, int logic_height, int scale) {

    //starts up sdl2
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {

        printf("Error with starting sdl2! More details: %s", SDL_GetError());
        return 1;

    }

    #ifdef __APPLE__
        Uint32 flags = SDL_WINDOW_METAL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
    #elif __linux__
        Uint32 flags = SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
    #elif _WIN32
        Uint32 flags = SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
    #elif _WIN64
        Uint32 flags = SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
    #elif __ANDROID__
        Uint32 flags = SDL_WINDOW_VULKAN | SDL_WINDOW_ALLOW_HIGHDPI;
    #elif __NX__
        Uint32 flags = SDL_WINDOW_VULKAN | SDL_WINDOW_ALLOW_HIGHDPI;
    #else
        Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;
    #endif

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, logic_width*scale, logic_height*scale, flags);

    //*decaf_window = *window;

    //checks if window variable is null
    if (window == NULL) {

        //displays error screen and quits out
        printf("Error with creating window! More details: %s", SDL_GetError());
        return 1;

    }

    // Create a renderer (accelerated and in sync with the display refresh rate)
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {

        //displays error screen and quits out
        printf("Error with creating renderer! More details: %s", SDL_GetError());
        return 1;

    }
    
    //sets renderer resolution (this is important for locking a aspect ratio!)
    SDL_RenderSetLogicalSize(renderer, logic_width, logic_height);

    // sets integer scaling
    SDL_RenderSetIntegerScale(renderer, true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    //sets background color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    //printf("refresh rate: %d\n", decaf_fetch_display_refreshrate());

    return 0;

}

void decaf_update(void (*update)(float dt), void (*draw)(void)) {

    float t = 0.0;
    const float dt = 1.0 / (float)decaf_fetch_display_refreshrate();

    float currentTime = ((float)(SDL_GetTicks()) / 1000.0f);
    float accumulator = 0.0;

    //game loop
    while(running) {

        //sdl event loop
        while(SDL_PollEvent(&event)) {

            //if the event type is SDL_QUIT, then quit game
            if(event.type == SDL_QUIT) {
                running = false;
            }

        }

        float newTime = ((float)(SDL_GetTicks()) / 1000.0f);
        float frameTime = (newTime - currentTime);

        if (frameTime > 0.25) {

            frameTime = 0.25;

        }
        currentTime = newTime;

        accumulator += frameTime;

        //update function for game.c
        while(accumulator >= dt) {
            update(dt);
            accumulator -= dt;
            //frameTime -= dt;
        }

        //update();

        if(decaf_key_pressed(DECAF_KEY_ESCAPE)) { running = false;}

        if(decaf_key_pressed(DECAF_KEY_F4) || decaf_key_pressed(DECAF_KEY_F11)) { decaf_toggle_fullscreen(); }

        //clears out the screen
        SDL_RenderClear(decaf_get_renderer());

        //SDL_RenderSetViewport(decaf_get_renderer(), &viewport);

        //draws renderer
        draw();

        //show whats currently being drawn to renderer
        SDL_RenderPresent(decaf_get_renderer());

    }

}

void decaf_quit(void (*destroy)(void)) {

    destroy();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

SDL_Renderer *decaf_get_renderer() {

    return renderer;

}

SDL_Window *decaf_get_window() {

    return window;

}

void decaf_toggle_fullscreen() {

    bool isFullscreen = SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN;

    //toggles between fullscreen and windowed
    SDL_SetWindowFullscreen(window, !isFullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP:0);

}

bool decaf_is_fullscreen() {

    //printf("window state: %s", fullscreenlol ? "fullscreen" : "windowed");

    return SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN;

}

char decaf_set_window_title(char *title) {

    SDL_SetWindowTitle(window, title);

    return 0;

}

char decaf_set_window_icon(char *path) {

    SDL_Surface *icon = SDL_LoadBMP(path);

    if (icon == NULL) {

        printf("Error with loading icon! More details: %s", SDL_GetError());
        return 1;

    }

    SDL_SetWindowIcon(window, icon);

    return 0;

}

void decaf_set_window_size(int width, int height) {

    SDL_SetWindowSize(window, width, height);

}

void decaf_set_window_position(int x, int y) {

    SDL_SetWindowPosition(window, x, y);

}
int decaf_fetch_display_refreshrate() {

    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(0, &mode);
    return mode.refresh_rate;

}

int decaf_fetch_scale() {

    return SDL_RenderGetIntegerScale(renderer);

}

int decaf_fetch_window_size(){

    return 0;

}

int decaf_fetch_window_width(){

    int w;
    int h;

    SDL_GetWindowSize(window, &w, &h);

    return w;

}

int decaf_fetch_window_height() {

    int w;
    int h;

    SDL_GetWindowSize(window, &w, &h);


    return h;

}

int decaf_fetch_render_width() {

    int w;
    int h;

    SDL_GetRendererOutputSize(renderer, &w, &h);

    return w;


}

int decaf_fetch_render_height() {

    int w;
    int h;

    SDL_GetRendererOutputSize(renderer, &w, &h);

    return h;


}

void decaf_modding_set(bool choice) {

    allow_mods = choice;

}

bool decaf_modding_allowed() {

    return allow_mods;

}

bool decaf_file_exists(const char *filename) {

    FILE *file = fopen(filename, "r");
    
    if (file != NULL) {

        fclose(file);
        return true;

    } else {

        fclose(file);
        return false;

    }

}