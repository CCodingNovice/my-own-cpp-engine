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
    virtual my_engine::vector2i getPos();
    virtual my_engine::vector2i getSize();
    virtual void setPos(my_engine::vector2i pos);
    virtual void setSize(my_engine::vector2i s);
    virtual SDL_Rect getRect();
    virtual SDL_Color getPrimaryColor();
    virtual SDL_Color getSecondaryColor();
    virtual const char *getText();
protected:
    my_engine::vector2i position;
    my_engine::vector2i size;
    std::string text;
    SDL_Color primary_color, secondary_color;
    SDL_Rect widget_background;
};

class Button : virtual public ScreenWidget {
public:
    Button();
    Button(const char *w_text, SDL_Color pr_color, SDL_Color sec_color);
    Button(my_engine::vector2i pos, my_engine::vector2i s, const char *w_text, SDL_Color pr_color, SDL_Color sec_color);
    my_engine::vector2i getPos() override;
    my_engine::vector2i getSize() override;
    void setPos(my_engine::vector2i pos) override;
    void setSize(my_engine::vector2i s) override;
    SDL_Rect getRect() override;
    SDL_Color getPrimaryColor() override;
    SDL_Color getSecondaryColor() override;

    bool onClick(my_engine::vector2i mouse_pos);
};

#endif //ENGINE_SCREENMENU_HPP
