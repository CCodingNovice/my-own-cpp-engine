#ifndef ENGINE_AUDIO_HPP
#define ENGINE_AUDIO_HPP

#include <SDL_mixer.h>
#include <string>

class Music {
public:
    Music();

    explicit Music(const char *name);

    ~Music();

    void MusicPlay();

    void MusicPause();

    void MusicStop();

private:
    Mix_Music *music;
};

#endif //ENGINE_AUDIO_HPP
