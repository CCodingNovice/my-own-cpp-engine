#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <SDL.h>

namespace my_engine{
    class Engine{
    public:
        Engine(const char* title, int weight, int height);
        Engine();

        void RenderFrame();
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
    };
}
#endif //ENGINE_ENGINE_HPP
