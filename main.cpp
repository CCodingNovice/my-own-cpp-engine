#include <iostream>
#include "src/core/Engine.hpp"
using namespace my_engine;
int main(int argc, char **argv) {
    Engine engine = Engine("sas", 800, 600);
    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            //If user closes the window
            if (e.type == SDL_QUIT){
                quit = true;
            }
            //If user presses any key
            if (e.type == SDL_KEYDOWN){
                quit = true;
            }
            //If user clicks the mouse
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
        }
    }
    return 0;
}