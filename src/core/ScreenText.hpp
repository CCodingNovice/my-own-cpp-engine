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
    SDL_Surface *getSurface();
    SDL_Texture *getTexture(SDL_Renderer *ren);
    void editText(const char *text);

private:
    std::string name;
    int8_t size;
    SDL_Color color;
    TTF_Font *FONT;
    SDL_Surface *surface;
};

#endif //ENGINE_SCREENTEXT_HPP
