#ifndef ENGINE_SCREENTEXT_HPP
#define ENGINE_SCREENTEXT_HPP

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

class Text {
public:
    Text();

    Text(const char *, int s, SDL_Color c, const char *);

    ~Text();

    SDL_Surface *GetSurface();

    SDL_Texture *GetTexture(SDL_Renderer *ren);

    void EditText(const char *text);

private:
    std::string name;
    int8_t size;
    SDL_Color color;
    TTF_Font *FONT;
    SDL_Surface *surface;
};

#endif //ENGINE_SCREENTEXT_HPP
