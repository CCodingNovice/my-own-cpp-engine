#include "Engine.hpp"
using namespace my_engine;

Engine::Engine(const char *title, int weight, int height) {
    SDL_Init(SDL_INIT_EVERYTHING);
    auto window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, weight, height, SDL_WINDOW_SHOWN);
    auto renderer = SDL_CreateRenderer(window, -1, 0);
}
Engine::Engine() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = nullptr;
    renderer = nullptr;
}

void my_engine::Engine::RenderFrame() {

}


