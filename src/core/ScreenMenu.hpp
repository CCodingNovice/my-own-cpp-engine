#ifndef ENGINE_SCREENMENU_HPP
#define ENGINE_SCREENMENU_HPP

#include "vector.hpp"
#include <string>
#include <SDL.h>

class ScreenWidget {
public:
    ScreenWidget();

    ScreenWidget(const char *w_text, SDL_Color pr_color, SDL_Color sec_color);

    ScreenWidget(my_engine::vector2i pos, my_engine::vector2i s, const char *w_text, SDL_Color pr_color,
                 SDL_Color sec_color);

    virtual my_engine::vector2i GetPos();

    virtual my_engine::vector2i GetSize();

    virtual void SetPos(my_engine::vector2i pos);

    virtual void SetSize(my_engine::vector2i s);

    virtual SDL_Rect GetRect(); // Орнул
    virtual SDL_Color GetPrimaryColor();

    virtual SDL_Color GetSecondaryColor();

protected:
    my_engine::vector2i position;
    my_engine::vector2i size;
    std::string text;
    SDL_Color primary_color, secondary_color;
    SDL_Rect widget_background;
};

class Button : virtual public ScreenWidget {
    Button();

    Button(const char *w_text, SDL_Color pr_color, SDL_Color sec_color);

    Button(my_engine::vector2i pos, my_engine::vector2i s, const char *w_text, SDL_Color pr_color, SDL_Color sec_color);
};

#endif //ENGINE_SCREENMENU_HPP
