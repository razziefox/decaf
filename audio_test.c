#ifdef __APPLE__
    #define MA_NO_RUNTIME_LINKING
#endif

#define MINIAUDIO_IMPLEMENTATION


#include "audio_test.h"

ma_engine engine;

int mini_init(void) {

    ma_result result;

    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        return -1;
    }

    return 0;

}

ma_sound *mini_load(char *audio_path) {

    static ma_sound sound;

    char exec_path[strlen(SDL_GetBasePath()) + 1];
    strcpy(exec_path, SDL_GetBasePath());

    char asset_path[256];

    strcpy(asset_path, audio_path);

    char file[strlen(exec_path) + strlen(asset_path) + 1];

    strncat(exec_path, asset_path, 512);

    strcpy(file, exec_path);

    printf("audio loaded: %s\n", file);

    ma_sound_init_from_file(&engine, file, 0, NULL, NULL, &sound);


    return &sound;

}

void mini_play_file(ma_sound *sound) {
    ma_result result;

    result = ma_sound_start(sound);
    if (result != MA_SUCCESS) {
        printf("%d", result);
    }

}

int mini_play(void) {

    char exec_path[strlen(SDL_GetBasePath()) + 1];
    strcpy(exec_path, SDL_GetBasePath());

    char asset_path[256];

    strcpy(asset_path, "assets/audio/test.wav");

    char file[strlen(exec_path) + strlen(asset_path) + 1];

    strncat(exec_path, asset_path, 512);

    strcpy(file, exec_path);

    ma_engine_play_sound(&engine, file, NULL);
    return 0;

}

void mini_stop(ma_sound *sound) { ma_sound_stop(sound); }

bool mini_ended(ma_sound *sound) { return ma_sound_at_end(sound); }

void mini_unload(void) {

    ma_engine_uninit(&engine);

}