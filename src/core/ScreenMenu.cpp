#include "ScreenMenu.hpp"

my_engine::vector2i ScreenWidget::GetPos() {
    return position;
}

my_engine::vector2i ScreenWidget::GetSize() {
    return size;
}

void ScreenWidget::SetPos(my_engine::vector2i pos) {
    position = pos;
}

void ScreenWidget::SetSize(my_engine::vector2i s) {
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

SDL_Rect ScreenWidget::GetRect() {
    return widget_background;
}

SDL_Color ScreenWidget::GetPrimaryColor() {
    return primary_color;
}

SDL_Color ScreenWidget::GetSecondaryColor() {
    return secondary_color;
}

const char *ScreenWidget::GetText() {
    return text.c_str();
}

Button::Button() : ScreenWidget::ScreenWidget() {}

Button::Button(const char *w_text, SDL_Color pr_color, SDL_Color sec_color) : ScreenWidget(w_text, pr_color,
                                                                                           sec_color) {}

Button::Button(my_engine::vector2i pos, my_engine::vector2i s, const char *w_text, SDL_Color pr_color,
               SDL_Color sec_color) : ScreenWidget(pos, s, w_text, pr_color, sec_color) {}

my_engine::vector2i Button::GetPos() {
    return ScreenWidget::GetPos();
}

my_engine::vector2i Button::GetSize() {
    return ScreenWidget::GetSize();
}

void Button::SetPos(my_engine::vector2i pos) {
    ScreenWidget::SetPos(pos);
}

void Button::SetSize(my_engine::vector2i s) {
    ScreenWidget::SetSize(s);
}

SDL_Rect Button::GetRect() {
    return ScreenWidget::GetRect();
}

SDL_Color Button::GetPrimaryColor() {
    return ScreenWidget::GetPrimaryColor();
}

SDL_Color Button::GetSecondaryColor() {
    return ScreenWidget::GetSecondaryColor();
}

bool Button::OnClick(my_engine::vector2i mouse_pos) {
    return mouse_pos.x > position.x && mouse_pos.x < position.x + size.x
           && mouse_pos.y > position.y && mouse_pos.y < position.y + size.y;
}
