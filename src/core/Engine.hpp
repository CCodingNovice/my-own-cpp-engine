#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <SDL.h>
#include "Object_2d.hpp"
#include "RigidBody.hpp"
namespace my_engine{
    class Engine{
        friend class RigidBody;
    public:
        Engine();

        ~Engine();
        void init();
        void set_window_options(int x_pos, int y_pos, int width, int height, const char title[100], Uint32 flags);
        void set_renderer_options(Uint32 flags);
        void clear_renderer();
        void draw_2d_object(Object_2d object2d, float scale);
        void draw_2d_object(RigidBody rb, float scale);
        void render_frame();

    private:
        SDL_Renderer *renderer;
        SDL_Window *window;
    };
}
#endif //ENGINE_ENGINE_HPP
