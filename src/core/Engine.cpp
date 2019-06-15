#include "Engine.hpp"
#include <direct.h>
#include <string>
#include <cstring>
#include <iostream>
#include <SDL_image.h>

using namespace my_engine;

Engine::Engine() {
    window = nullptr;
    renderer = nullptr;
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

void Engine::draw_2d_object(Object_2d object2d, int width, int height, float scale) {
    SDL_Rect object_rect;
    object_rect.x = object2d.Get_x();
    object_rect.y = object2d.Get_y();
    object_rect.w = width;
    object_rect.h = height;
    SDL_Texture *tex = IMG_LoadTexture(renderer, object2d.GetPath());
    SDL_RenderCopy(renderer, tex, nullptr, &object_rect);
}

void Engine::render_frame() {
    SDL_RenderPresent(renderer);
}


