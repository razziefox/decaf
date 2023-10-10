#include "graphics.h"

void decaf_set_bg_color(int r, int g, int b) {

    //SDL_Renderer *renderer = decaf_get_renderer();

    SDL_SetRenderDrawColor(decaf_get_renderer(), r, g, b, 255);
    SDL_Rect rect = {0, 0, 256, 144};
    SDL_RenderFillRect(decaf_get_renderer(), &rect);

    SDL_SetRenderDrawColor(decaf_get_renderer(), 0, 0, 0, 255);
    
}

//function to load images using sdl_image
SDL_Texture *decaf_graphics_load(char *path) {

    char strarray[256] = "test";
    char another[256];

    strcpy(another, path);
    strncat(strarray, another, 255);

    printf("%s\n", strarray);

    if (decaf_fetch_modding_allowed() == true && decaf_is_file_exists(path) == true) {

        SDL_Surface *surface = SDL_LoadBMP(path);

    } else {

        SDL_Surface *surface = SDL_LoadBMP(path);

    }
    //loads image onto a surface
    SDL_Surface *surface = SDL_LoadBMP(path);

    if (surface != NULL) {
        
        printf("image loaded: %s\n", path);

    }

    //converts the surface into a texture
    SDL_Texture *texture = SDL_CreateTextureFromSurface(decaf_get_renderer(), surface);

    //unloads surface from earlier
    SDL_FreeSurface(surface);

    //returns back the texture given
    return texture;

}


//functon to draw images using sdl_image
void decaf_graphics_image(SDL_Texture *texture, SDL_Rect *rect) {

    //draws the texture onto the renderer
    SDL_RenderCopy(decaf_get_renderer(), texture, NULL, rect);
    return;

}

void decaf_graphics_imagef(SDL_Texture *texture, SDL_FRect *rect) {

    SDL_RenderCopyF(decaf_get_renderer(), texture, NULL, rect);
    return;

}

void decaf_graphics_sprite(SDL_Texture *texture, int cell, SDL_Rect *rect) {

    struct spriteData {
        int x;
        int y;
        int w;
        int h;
    };

    struct SDL_Rect sprite = {cell*8, 0, 8, 8};

    SDL_RenderCopy(decaf_get_renderer(), texture, &sprite, rect);
    return;

}

void decaf_graphics_spritef(SDL_Texture *texture, int cell, SDL_FRect *rect) {

    struct spriteData {
        int x;
        int y;
        int w;
        int h;
    };

    struct SDL_Rect sprite = {cell*8, 0, 8, 8};

    SDL_RenderCopyF(decaf_get_renderer(), texture, &sprite, rect);
    return;

}

void destroy_texture(SDL_Texture *texture) {

    SDL_DestroyTexture(texture);
    return;

}