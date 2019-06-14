#include "Engine.hpp"
#include <direct.h>
#include <string>
#include <cstring>
#include <iostream>
#include <SDL_image.h>

using namespace my_engine;

Engine::Engine(const char *title, int weight, int height) {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, 20, 20, weight, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}
Engine::Engine() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = nullptr;
    renderer = nullptr;
}

void my_engine::Engine::RenderFrame() {

}

SDL_Renderer *Engine::GetRenderer() {
    return renderer;
}

SDL_Window *Engine::GetWindow() {
    return window;
}

void Engine::RenderTexture(Object_2d object2d, int width, int height) {
    SDL_Rect ObjectRect;
    ObjectRect.x = object2d.Get_x();
    ObjectRect.y = object2d.Get_y();
    ObjectRect.w = width;
    ObjectRect.h = height;
    SDL_Texture *player =  IMG_LoadTexture(renderer, object2d.GetPath());
    SDL_RenderClear(renderer); //Очистка рендера
    SDL_RenderCopy(renderer, player, NULL, &ObjectRect); //Копируем в рендер персонажа
    SDL_RenderPresent(renderer); //Погнали!!
}



