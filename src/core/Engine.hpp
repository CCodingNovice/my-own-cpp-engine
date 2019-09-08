#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <SDL.h>
#include "Object_2d.hpp"
#include "RigidBody.hpp"
#include "Player.hpp"
#include <string>
#include <vector>
#include "ScreenText.hpp"
#include "ScreenMenu.hpp"

namespace my_engine{
    class Engine{
        friend class RigidBody;
    public:
        Engine();

        explicit Engine(std::string md);
        ~Engine();
        void init();
        void set_window_options(int x_pos, int y_pos, int width, int height, const char title[100], Uint32 flags);
        void set_renderer_options(Uint32 flags);
        void clear_renderer();
        void draw(Object_2d object2d, float scale);
        void draw(RigidBody rb, float scale);
        void draw(std::vector<RigidBody *> &objects);
        void render_frame();
        void draw(Text text, vector2i pos);
        void draw(ScreenWidget widget);
        void draw(Button button);
        void draw(Player player, float scale);
        void setCurrTicks(Uint32 t);

    private:
        SDL_Renderer *renderer;
        SDL_Window *window;
        bool MODE;
        Uint32 currTicks;
    };
}
#endif //ENGINE_ENGINE_HPP
