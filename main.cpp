#include <iostream>
#include <chrono>
#include "src/core/Physics.hpp"
#include "src/core/Engine.hpp"

const Uint8 *keys = SDL_GetKeyboardState(nullptr);
using namespace my_engine;

int main(int argc, char **argv) {
    Engine engine = Engine("DEBUG");
    Object_2d object2d = Object_2d(0, 0, 300, 250, "../src/assets/summer-synthwave-1244.bmp");
    Object_2d object2d2 = Object_2d(500, 400, 300, 250, "../src/assets/summer-synthwave-1244.bmp");
    RigidBody rigidBody = RigidBody(vector2i(0, 0), vector2i(200, 200));
    RigidBody rigidBody2 = RigidBody(vector2i(550, 450), vector2i(700, 600));
    rigidBody = object2d;
    rigidBody2 = object2d2;
    std::vector<RigidBody> objects;
    std::vector<RigidBody *> to_render;

    to_render.push_back(&rigidBody);
    to_render.push_back(&rigidBody2);
    objects.emplace_back(rigidBody2);

    vector2i a;
    a.x = 4;
    a.y = 4;
    Physics physics = Physics(a);

    engine.init();
    engine.set_window_options(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, "cool window bro",
                              SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN);
    engine.set_renderer_options(SDL_RENDERER_ACCELERATED);
    SDL_Event e;
    bool is_stop = true;
    bool quit = false;

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
        if (is_stop) {
            physics.SetVelocity(vector2i(0, 0));
        } else {
            if (keys[SDL_SCANCODE_D]) {
                physics.SetVelocity(vector2i(5, 0));
                physics.MoveRight(rigidBody, objects);
            }
            if (keys[SDL_SCANCODE_A]) {
                physics.SetVelocity(vector2i(5, 0));
                physics.MoveLeft(rigidBody, objects);
            }
            if (keys[SDL_SCANCODE_W]) {
                physics.SetVelocity(vector2i(0, 5));
                physics.MoveUp(rigidBody, objects);
            }
            if (keys[SDL_SCANCODE_S]) {
                physics.SetVelocity(vector2i(0, 5));
                physics.MoveDown(rigidBody, objects);
            }
//            if (keys[SDL_SCANCODE_SPACE])
//                physics.Jump(rigidBody, objects, 4);
        }
        engine.clear_renderer();
        engine.draw_objects(to_render);
        engine.render_frame();

    }
    return 0;
}