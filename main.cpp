#include <iostream>
#include <direct.h>
#include "src/core/Engine.hpp"
#include "src/core/Object_2d.hpp"
using namespace my_engine;
int main(int argc, char **argv) {
    Engine engine = Engine();
    Object_2d object2d = Object_2d(0, 0, "../src/assets/summer-synthwave-1244.bmp");
    engine.init();
    engine.set_window_options(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, "cool window bro", SDL_WINDOW_FULLSCREEN|SDL_WINDOW_SHOWN);
    engine.set_renderer_options(SDL_RENDERER_ACCELERATED);
    engine.clear_renderer();
    engine.draw_2d_object(object2d, 2048, 1280, 1.0);
    engine.render_frame();
    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
        }

    }
    return 0;
}