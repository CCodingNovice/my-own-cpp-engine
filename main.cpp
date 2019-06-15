#include <iostream>
#include <chrono>
#include "src/core/Engine.hpp"
#include "src/core/Object_2d.hpp"
#include "src/core/RigidBody.hpp"

using namespace my_engine;
int main(int argc, char **argv) {
    Engine engine = Engine();
    Object_2d object2d = Object_2d(0, 0, "../src/assets/summer-synthwave-1244.bmp");
    RigidBody rb = RigidBody(object2d, 1, true, 0, false, 0, 6);
    engine.init();
    engine.set_window_options(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, "cool window bro", SDL_WINDOW_FULLSCREEN|SDL_WINDOW_SHOWN);
    engine.set_renderer_options(SDL_RENDERER_ACCELERATED);
    engine.clear_renderer();
    engine.draw_2d_object(object2d, 200, 130, 1.0);
    engine.render_frame();
    SDL_Event e;
    bool quit = false;

    while (!quit){
//        auto start = std::chrono::steady_clock::now();
        while (SDL_PollEvent(&e)){
//            auto end = std::chrono::steady_clock::now();
//            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
            if(e.type == SDL_KEYDOWN){
                switch(e.key.keysym.sym){
                    case SDLK_d:
                        engine.clear_renderer();
                        rb.move_right();
                        engine.draw_2d_object(rb, 200, 130, 1);
                        engine.render_frame();
                        break;
                    case SDLK_a:
                        engine.clear_renderer();
                        rb.move_left();
                        engine.draw_2d_object(rb, 200, 130, 1);
                        engine.render_frame();
                        break;
                    case SDLK_w:
                        engine.clear_renderer();
                        rb.move_up();
                        engine.draw_2d_object(rb, 200, 130, 1);
                        engine.render_frame();
                        break;
                    case SDLK_s:
                        engine.clear_renderer();
                        rb.move_down();
                        engine.draw_2d_object(rb, 200, 130, 1);
                        engine.render_frame();
                        break;
                    default:
                        break;
                }
            }
//            if ( elapsed >= std::chrono::duration<long, std::ratio<1, 60>> ()){
//                engine.render_frame();
//            }

        }

    }
    return 0;
}