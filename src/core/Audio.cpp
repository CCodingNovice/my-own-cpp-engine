#include "Audio.hpp"

Music::Music() {
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    music = nullptr;
}

Music::~Music() {
    Mix_CloseAudio();
    Mix_FreeMusic(music);
}

void Music::musicPlay() {
    if (Mix_PausedMusic()) {
        Mix_ResumeMusic();
    } else {
        Mix_PlayMusic(music, 10);
    }
}

void Music::musicPause() {
    Mix_PauseMusic();
}

void Music::musicStop() {
    Mix_HaltMusic();
}

Music::Music(const char *name) {
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    music = Mix_LoadMUS(name);
}
