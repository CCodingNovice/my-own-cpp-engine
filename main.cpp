#include <iostream>
#include "src/core/Engine.hpp"
#include "src/core/Object_2d.hpp"
using namespace my_engine;
int main(int argc, char **argv) {
    Engine engine = Engine("lol", 900, 600);
    Object_2d sample = Object_2d(0, 0, "C:\\Users\\nikit\\CLionProjects\\engine\\src\\assets\\summer-synthwave-1244.bmp");
    engine.RenderTexture(sample, 900, 600);
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