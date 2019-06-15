#include <iostream>
#include <chrono>
#include "src/core/Engine.hpp"
#include "src/core/Object_2d.hpp"
#include "src/core/RigidBody.hpp"

const Uint8 *keys = SDL_GetKeyboardState(NULL);
using namespace my_engine;

int main(int argc, char **argv) {
    Engine engine = Engine();
    Object_2d object2d = Object_2d(0, 0, "../src/assets/summer-synthwave-1244.bmp");
    RigidBody rb = RigidBody(object2d, 1, true, 0, false, 0, 6);
    engine.init();
    engine.set_window_options(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, "cool window bro",
                              SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN);
    engine.set_renderer_options(SDL_RENDERER_ACCELERATED);
    engine.clear_renderer();
    engine.draw_2d_object(object2d, 200, 130, 1.0);
    engine.render_frame();
    SDL_Event e;
    bool is_stop = true;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_MOUSEBUTTONDOWN || e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }
        }
        if (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_S] ||
            keys[SDL_SCANCODE_A]) { is_stop = false; }
        else is_stop = true;
        if (!is_stop) {
            if (keys[SDL_SCANCODE_D])
                rb.move_right();
            if (keys[SDL_SCANCODE_A])
                rb.move_left();
            if (keys[SDL_SCANCODE_W])
                rb.move_up();
            if (keys[SDL_SCANCODE_S])
                rb.move_down();
        }
        engine.clear_renderer();
        engine.draw_2d_object(rb, 300, 150, 1);
        engine.render_frame();

    }
    return 0;
}