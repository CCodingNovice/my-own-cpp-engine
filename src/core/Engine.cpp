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

void Engine::draw_2d_object(Object_2d object2d, float scale) {
    SDL_Rect object_rect;
    object_rect.x = object2d.GetPos().x;
    object_rect.y = object2d.GetPos().y;
    object_rect.w = int(object2d.GetSize().x * scale);
    object_rect.h = int(object2d.GetSize().y * scale);
    SDL_Texture *tex = IMG_LoadTexture(renderer, object2d.GetPath());
    SDL_RenderCopy(renderer, tex, nullptr, &object_rect);
    SDL_DestroyTexture(tex);
}

void Engine::render_frame() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}

void Engine::draw_2d_object(RigidBody rb, float scale) {
    SDL_Rect object_rect;
    object_rect.x = rb.GetTexturePos().x;
    object_rect.y = rb.GetTexturePos().y;
    object_rect.w = int(rb.GetSize().x * scale);
    object_rect.h = int(rb.GetSize().y * scale);
    SDL_Texture *tex = rb.GetTexture();
    if (tex == nullptr) {
        tex = IMG_LoadTexture(renderer, rb.GetPath());
    }
    SDL_RenderCopy(renderer, tex, nullptr, &object_rect);
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
    if (md == "DEBUG")
        MODE = false;
    else MODE = true;
}

void Engine::draw_objects(std::vector<RigidBody *> &objects) {
    SDL_Rect object_rect;
    for (auto object : objects) {
        SDL_Texture *tex = object->GetTexture();
        if (tex == nullptr) {
            tex = IMG_LoadTexture(renderer, object->GetPath());
        }
        object_rect.x = object->GetTexturePos().x;
        object_rect.y = object->GetTexturePos().y;
        object_rect.w = object->GetSize().x;
        object_rect.h = object->GetSize().y;
        SDL_RenderCopy(renderer, tex, nullptr, &object_rect);
    }
    if (!MODE) {
        for (auto &object : objects) {
            object_rect.x = object->GetHitboxMin().x;
            object_rect.y = object->GetHitboxMin().y;
            object_rect.w = object->GetHitboxMax().x - object->GetHitboxMin().x;
            object_rect.h = object->GetHitboxMax().y - object->GetHitboxMin().y;
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderDrawRect(renderer, &object_rect);
        }
    }
}

void Engine::render_text(Text text, vector2i pos) {
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, text.GetSurface());
    SDL_Rect rect;
    rect.x = pos.x;
    rect.y = pos.y;
    rect.w = text.GetSurface()->w;
    rect.h = text.GetSurface()->h;
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
}


