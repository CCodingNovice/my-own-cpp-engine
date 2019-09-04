#include "ScreenMenu.hpp"

my_engine::vector2i ScreenWidget::getPos() {
    return position;
}

my_engine::vector2i ScreenWidget::getSize() {
    return size;
}

void ScreenWidget::setPos(my_engine::vector2i pos) {
    position = pos;
}

void ScreenWidget::setSize(my_engine::vector2i s) {
    size = s;
}

ScreenWidget::ScreenWidget() {
    position = {0, 0};
    size = {100, 100};
    text = "sample text";
    primary_color = {0, 0, 0};
    secondary_color = {255, 255, 255};
    widget_background.x = position.x;
    widget_background.y = position.y;
    widget_background.w = size.x;
    widget_background.h = size.y;
}

ScreenWidget::ScreenWidget(const char *w_text, SDL_Color pr_color, SDL_Color sec_color) {
    position = {0, 0};
    size = {100, 100};
    text = w_text;
    primary_color = pr_color;
    secondary_color = sec_color;
    widget_background.x = position.x;
    widget_background.y = position.y;
    widget_background.w = size.x;
    widget_background.h = size.y;
}

ScreenWidget::ScreenWidget(my_engine::vector2i pos,
                           my_engine::vector2i s, const char *w_text,
                           SDL_Color pr_color, SDL_Color sec_color) {
    position = pos;
    size = s;
    text = w_text;
    primary_color = pr_color;
    secondary_color = sec_color;
    widget_background.x = position.x;
    widget_background.y = position.y;
    widget_background.w = size.x;
    widget_background.h = size.y;
}

SDL_Rect ScreenWidget::getRect() {
    return widget_background;
}

SDL_Color ScreenWidget::getPrimaryColor() {
    return primary_color;
}

SDL_Color ScreenWidget::getSecondaryColor() {
    return secondary_color;
}

const char *ScreenWidget::getText() {
    return text.c_str();
}

Button::Button() : ScreenWidget::ScreenWidget() {}

Button::Button(const char *w_text, SDL_Color pr_color, SDL_Color sec_color) : ScreenWidget(w_text, pr_color,
                                                                                           sec_color) {}

Button::Button(my_engine::vector2i pos, my_engine::vector2i s, const char *w_text, SDL_Color pr_color,
               SDL_Color sec_color) : ScreenWidget(pos, s, w_text, pr_color, sec_color) {}

my_engine::vector2i Button::getPos() {
    return ScreenWidget::getPos();
}

my_engine::vector2i Button::getSize() {
    return ScreenWidget::getSize();
}

void Button::setPos(my_engine::vector2i pos) {
    ScreenWidget::setPos(pos);
}

void Button::setSize(my_engine::vector2i s) {
    ScreenWidget::setSize(s);
}

SDL_Rect Button::getRect() {
    return ScreenWidget::getRect();
}

SDL_Color Button::getPrimaryColor() {
    return ScreenWidget::getPrimaryColor();
}

SDL_Color Button::getSecondaryColor() {
    return ScreenWidget::getSecondaryColor();
}

bool Button::onClick(my_engine::vector2i mouse_pos) {
    return mouse_pos.x > position.x && mouse_pos.x < position.x + size.x
           && mouse_pos.y > position.y && mouse_pos.y < position.y + size.y;
}
