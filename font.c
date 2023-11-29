#include "font.h"

// initialize sdl_ttf
void decaf_font_init(void) {

    TTF_Init();

}

// closes out sdl_ttf
void decaf_font_quit(void) {

    TTF_Quit();

}

// loads font from given path and sets font size
TTF_Font *decaf_font_load(const char* path, int size) {

    TTF_Font* font = TTF_OpenFont(path, size);
    return font;

}

// frees font from memory
void decaf_font_destroy(TTF_Font* font) {

    TTF_CloseFont(font);

}

// draws text with given font and color
void decaf_font_draw(TTF_Font* font, const char* text, int x, int y, decaf_color color) {

    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(decaf_get_renderer(), surface);

    int tex_w = 0;
    int tex_h = 0;

    SDL_QueryTexture(texture, NULL, NULL, &tex_w, &tex_h);

    SDL_Rect rect = {x, y, tex_w, tex_h};

    SDL_RenderCopy(decaf_get_renderer(), texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);

}