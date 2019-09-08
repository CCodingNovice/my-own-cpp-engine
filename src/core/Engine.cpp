#include "Engine.hpp"
#include <SDL_image.h>
#include <cmath>

using namespace my_engine;

Engine::Engine() {
    window = nullptr;
    renderer = nullptr;
    MODE = true;
}

void Engine::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

void Engine::set_window_options(int x_pos, int y_pos, int width, int height, const char *title, Uint32 flags) {
    window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
}

void Engine::set_renderer_options(Uint32 flags) {
    renderer = SDL_CreateRenderer(window, -1, flags);
}

void Engine::clear_renderer() {
    SDL_RenderClear(renderer);
}

void Engine::draw(Object_2d object2d, float scale) {
    SDL_Rect object_rect;
    object_rect.x = object2d.getPos().x;
    object_rect.y = object2d.getPos().y;
    object_rect.w = int(object2d.getSize().x * scale);
    object_rect.h = int(object2d.getSize().y * scale);
    SDL_Texture *tex = IMG_LoadTexture(renderer, object2d.getPath());
    if(!object2d.getAnimationsSize()) {
        SDL_RenderCopy(renderer, tex, nullptr, &object_rect);
    }
    else{
        SDL_Rect src = object2d.getSourceRect(currTicks);
        SDL_RenderCopy(renderer, tex, &src, &object_rect);
    }
    SDL_DestroyTexture(tex);
}

void Engine::render_frame() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}

void Engine::draw(RigidBody rb, float scale) {
    SDL_Rect object_rect;
    object_rect.x = rb.getTexturePos().x;
    object_rect.y = rb.getTexturePos().y;
    object_rect.w = int(rb.getSize().x * scale);
    object_rect.h = int(rb.getSize().y * scale);
    SDL_Texture *tex = rb.getTexture();
    if (tex == nullptr) {
        tex = IMG_LoadTexture(renderer, rb.getPath());
    }
    if(!rb.getAnimationsSize()) {
        SDL_RenderCopy(renderer, tex, nullptr, &object_rect);
    }
    else{
        SDL_Rect src = rb.getSourceRect(currTicks);
        SDL_RenderCopy(renderer, tex, &src, &object_rect);
    }
    SDL_DestroyTexture(tex);
}

Engine::~Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Engine::Engine(std::string md) {
    window = nullptr;
    renderer = nullptr;
    MODE = !(md == "DEBUG");
}

void Engine::draw(std::vector<RigidBody *> &objects) {
    SDL_Rect object_rect;
    SDL_Texture *tex;
    for (auto &object : objects) {
        tex = IMG_LoadTexture(renderer, object->getPath());
        object_rect.x = object->getTexturePos().x;
        object_rect.y = object->getTexturePos().y;
        object_rect.w = object->getSize().x;
        object_rect.h = object->getSize().y;
        if(!object->getAnimationsSize()) {
            SDL_RenderCopy(renderer, tex, nullptr, &object_rect);
        }
        else{
            SDL_Rect src = object->getSourceRect(currTicks);
            SDL_RenderCopy(renderer, tex, &src, &object_rect);
        }
        SDL_DestroyTexture(tex);
    }
    if (!MODE) {
        for (auto &object : objects) {
            object_rect.x = object->getHitboxMin().x;
            object_rect.y = object->getHitboxMin().y;
            object_rect.w = object->getHitboxMax().x - object->getHitboxMin().x;
            object_rect.h = object->getHitboxMax().y - object->getHitboxMin().y;
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderDrawRect(renderer, &object_rect);
        }
    }
}

void Engine::draw(Text text, vector2i pos) {
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, text.getSurface());
    SDL_Rect rect;
    rect.x = pos.x;
    rect.y = pos.y;
    rect.w = text.getSurface()->w;
    rect.h = text.getSurface()->h;
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
}

void Engine::draw(ScreenWidget widget) {
    SDL_Rect rect = widget.getRect();
    SDL_RenderFillRect(renderer, &rect);
    auto FONT = TTF_OpenFont("../src/assets/fonts/ARIAL.ttf", 104);
    auto surface = TTF_RenderText_Solid(FONT, widget.getText(), widget.getSecondaryColor());
    TTF_CloseFont(FONT);
    auto tex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, tex, nullptr, &rect);
    SDL_DestroyTexture(tex);
    SDL_FreeSurface(surface);
}

void Engine::draw(Button button) {
    SDL_Rect rect = button.getRect();
    SDL_RenderFillRect(renderer, &rect);
    auto FONT = TTF_OpenFont("../src/assets/fonts/ARIAL.ttf", 104);
    auto surface = TTF_RenderText_Solid(FONT, button.getText(), button.getSecondaryColor());
    TTF_CloseFont(FONT);
    auto tex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, tex, nullptr, &rect);
    SDL_DestroyTexture(tex);
    SDL_FreeSurface(surface);
}

void Engine::draw(Player player, float scale) {
    SDL_Rect object_rect;
    object_rect.x = player.getTexturePos().x;
    object_rect.y = player.getTexturePos().y;
    object_rect.w = int(player.getSize().x * scale);
    object_rect.h = int(player.getSize().y * scale);
    SDL_Texture *tex = player.getTexture();
    if (tex == nullptr) {
        tex = IMG_LoadTexture(renderer, player.getPath());
    }
    if(!player.getAnimationsSize()) {
        SDL_RenderCopy(renderer, tex, nullptr, &object_rect);
    }
    else{
        SDL_Rect src = player.getSourceRect(currTicks);
        SDL_RenderCopy(renderer, tex, &src, &object_rect);
    }
    SDL_DestroyTexture(tex);
    if(!MODE){
        object_rect.x = player.getHitboxMin().x;
        object_rect.y = player.getHitboxMin().y;
        object_rect.w = player.getHitboxMax().x - player.getHitboxMin().x;
        object_rect.h = player.getHitboxMax().y - player.getHitboxMin().y;
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderDrawRect(renderer, &object_rect);
    }
}

void Engine::setCurrTicks(Uint32 t) {
    currTicks = t;
}
