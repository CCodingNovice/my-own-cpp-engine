#include <iostream>
#include <chrono>
#include "src/core/Physics.hpp"
#include "src/core/Engine.hpp"
#include "src/core/Object_2d.hpp"
#include "src/core/RigidBody.hpp"
#include <vector>

const Uint8 *keys = SDL_GetKeyboardState(nullptr);
using namespace my_engine;

int main(int argc, char **argv) {
    Engine engine = Engine();
    Object_2d object2d = Object_2d(0, 0, 300, 250, "../src/assets/summer-synthwave-1244.bmp");
    Object_2d object2d2 = Object_2d(500, 0, 300, 250, "../src/assets/summer-synthwave-1244.bmp");
    RigidBody rigidBody = RigidBody(50, true, true);
    RigidBody rigidBody2 = RigidBody(50, true, true);
    rigidBody = object2d;
    rigidBody2 = object2d2;
    std::vector<RigidBody> objects;
    objects.emplace_back(rigidBody2);
    engine.init();
    engine.set_window_options(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, "cool window bro",
                              SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN);
    engine.set_renderer_options(SDL_RENDERER_ACCELERATED);
    SDL_Event e;
    bool is_stop = true;
    bool quit = false;
    Physics physics = Physics(3, 3);
    engine.clear_renderer();
    engine.draw_2d_object(rigidBody, 1);
    engine.draw_2d_object(rigidBody2, 1);
    engine.render_frame();
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_MOUSEBUTTONDOWN || e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }
        }
        is_stop = !(keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_S] ||
                    keys[SDL_SCANCODE_A]);
        if (!is_stop) {
            if (keys[SDL_SCANCODE_D])
                physics.MoveRight(rigidBody, objects);
            if (keys[SDL_SCANCODE_A])
                physics.MoveLeft(rigidBody, objects);
            /*if (keys[SDL_SCANCODE_W])
                rigidBody.move_up();
            if (keys[SDL_SCANCODE_S])
                rigidBody.move_down();*/
        }
        engine.clear_renderer();
        engine.draw_2d_object(rigidBody, 1);
        engine.draw_2d_object(rigidBody2, 1);
        engine.render_frame();

    }
    return 0;
}