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

int mini_play(void) {

    char exec_path[strlen(SDL_GetBasePath()) + 1];
    strcpy(exec_path, SDL_GetBasePath());
    char file_path[256];

    strcpy(file_path, "/sound.wav");

    char file[strlen(exec_path) + strlen(file_path) + 1];

    strncat(exec_path, file_path, 512);

    ma_engine_play_sound(&engine, exec_path, NULL);
    return 0;

}

void mini_unload(void) {

    ma_engine_uninit(&engine);

}