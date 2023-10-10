#include "audio.h"

void decaf_audio_init() {

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {

        printf("SDL Error: %s", SDL_GetError());
    }

}

Mix_Chunk *decaf_audio_loadSound(char *path) {

    Mix_Chunk *sound = Mix_LoadWAV(path);

    if(sound != NULL) {

        printf("sound loaded: %s\n", path);

    }

    return sound;

}

void decaf_audio_playSound(Mix_Chunk *sound) {

    Mix_PlayChannel(-1, sound, 0);

}

Mix_Music *decaf_audio_loadMusic(char *path) {

    Mix_Music *music = Mix_LoadMUS(path);

    if(music != NULL) {

        printf("music loaded: %s\n", path);

    }

    return music;

}

void decaf_audio_playMusic(Mix_Music *music) {

    if(Mix_PlayingMusic() == 0) {

        Mix_PlayMusic(music, -1);

    }

}

void decaf_audio_stopMusic() {

    Mix_HaltMusic();

}

void decaf_audio_pauseMusic() {

    Mix_PauseMusic();

}

void decaf_audio_resumeMusic() {

    Mix_ResumeMusic();

}

void decaf_audio_setMusicVolume(int volume) {

    Mix_VolumeMusic(volume);

}

void decaf_audio_setSoundVolume(int volume) {

    Mix_Volume(-1, volume);

}

void decaf_audio_quit() {

    Mix_CloseAudio();

}

void decaf_audio_destroySound(Mix_Chunk *sound) {

    Mix_FreeChunk(sound);

}

void decaf_audio_destroyMusic(Mix_Music *music) {

    Mix_FreeMusic(music);

}