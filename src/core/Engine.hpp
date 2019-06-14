#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <SDL.h>
#include "Object_2d.hpp"

namespace my_engine{
    class Engine{
    public:
        Engine(const char* title, int weight, int height);
        Engine();
        SDL_Renderer* GetRenderer();
        SDL_Window* GetWindow();
        void RenderFrame();
        void RenderTexture(Object_2d object2d, int width, int height);

    private:
        SDL_Renderer *renderer;
        SDL_Window *window;
    };
}
#endif //ENGINE_ENGINE_HPP
