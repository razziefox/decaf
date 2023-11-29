#include "audio.h"

// initializes sdl_mixer
void decaf_audio_init(void) {

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {

        printf("SDL Error: %s", SDL_GetError());
    }

}

// loads wav file from given path
Mix_Chunk *decaf_audio_loadSound(char *path) {

    Mix_Chunk *sound = Mix_LoadWAV(path);

    if(sound != NULL) {

        printf("sound loaded: %s\n", path);

    }

    return sound;

}

// plays audio (does not loop)
void decaf_audio_playSound(Mix_Chunk *sound) {

    Mix_PlayChannel(-1, sound, 0);

}

// loads music audio
Mix_Music *decaf_audio_loadMusic(char *path) {

    Mix_Music *music = Mix_LoadMUS(path);

    if(music != NULL) {

        printf("music loaded: %s\n", path);

    }

    return music;

}

// plays music (is loop)
void decaf_audio_playMusic(Mix_Music *music) {

    // checks if theres music currently playing
    if(Mix_PlayingMusic() == 0) {

        Mix_PlayMusic(music, -1);

    }

}

// stops music thats currently playing
void decaf_audio_stopMusic(void) {

    Mix_HaltMusic();

}

// pauses music thats currently playing
void decaf_audio_pauseMusic(void) {

    Mix_PauseMusic();

}

// resumes music that was playing
void decaf_audio_resumeMusic(void) {

    Mix_ResumeMusic();

}

// sets music volume
void decaf_audio_setMusicVolume(int volume) {

    Mix_VolumeMusic(volume);

}

// sets sound audio
void decaf_audio_setSoundVolume(int volume) {

    Mix_Volume(-1, volume);

}

// closes out sdl_mixer
void decaf_audio_quit(void) {

    Mix_CloseAudio();

}

// frees sound from memory
void decaf_audio_destroySound(Mix_Chunk *sound) {

    Mix_FreeChunk(sound);

}

// frees music from memory
void decaf_audio_destroyMusic(Mix_Music *music) {

    Mix_FreeMusic(music);

}