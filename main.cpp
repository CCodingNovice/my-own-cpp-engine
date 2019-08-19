#include <iostream>
#include <chrono>
#include "src/core/Physics.hpp"
#include "src/core/Engine.hpp"
#include "src/core/Audio.hpp"

#define SCREENWIDTH 1920
#define SCREENHEIGHT 1080

int SCORE = 0;
const Uint8 *keys = SDL_GetKeyboardState(nullptr);
using namespace my_engine;

int main(int argc, char **argv) {
    TTF_Init();
    Engine engine = Engine("DEBUG");

    SDL_Color color = {255, 255, 255};
    Text ScoreDisplay = Text("../src/assets/fonts/ARIAL.ttf", 104, color, ("SCORE:" + std::to_string(SCORE)).c_str());

    Object_2d object2d = Object_2d(800, 800, 400, 330, "../src/assets/Car.png");
    Object_2d En = Object_2d(720, 150, 400, 330, "../src/assets/Enemy.png");
    Object_2d background2 = Object_2d(0, 0, SCREENWIDTH, SCREENWIDTH, "../src/assets/background_100px_2.png");

    RigidBody rigidBody = RigidBody(vector2i(920, 970), vector2i(1080, 1050));
    RigidBody enemy1 = RigidBody(vector2i(840, 360), vector2i(1020, 450));
    RigidBody enemy2 = RigidBody(vector2i(840, 360), vector2i(1020, 450));
    RigidBody enemy3 = RigidBody(vector2i(840, 360), vector2i(1020, 450));
    RigidBody left_bound = RigidBody(vector2i(0, 800), vector2i(420, 1080));
    RigidBody right_bound = RigidBody(vector2i(1500, 800), vector2i(1920, 1080));

    rigidBody = object2d;
    enemy1 = En;
    enemy2 = En;
    enemy3 = En;

    std::vector<RigidBody> objects;
    std::vector<RigidBody *> to_render;

    objects.push_back(left_bound);
    objects.push_back(right_bound);

    to_render.push_back(&enemy1);
    to_render.push_back(&rigidBody);
    to_render.push_back(&left_bound);
    to_render.push_back(&right_bound);

    bool en2 = false;
    bool en3 = false;
    vector2i a;
    a.x = 4;
    a.y = 6;
    Physics physics = Physics(a);

    bool menu = true;
    Button start_btn = Button(vector2i(840, 600), vector2i(1020, 750), "START", {100, 100, 200}, {255, 255, 255});

    engine.init();
    engine.set_window_options(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, "Example game",
                              SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN);
    engine.set_renderer_options(SDL_RENDERER_ACCELERATED);

    Music soundtrack = Music("../src/assets/Music/Lost_Control.mp3");
    soundtrack.MusicPlay();

    SDL_Event e;
    bool is_stop;
    bool esc_stop;
    bool quit = false;


    srand(unsigned(std::time(nullptr)));
    int seed = std::rand() % 1000;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }
        }
        is_stop = !(keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_D]);
        physics.SetVelocity(vector2i(1, 0));
        if (physics.Collision(rigidBody, enemy1, 1, 'Y') || physics.Collision(rigidBody, enemy2, 1, 'Y') ||
            physics.Collision(rigidBody, enemy3, 1, 'Y')) {
            return 0;
        }
        enemy1.SetPos(vector2i(enemy1.GetPos().x, enemy1.GetPos().y + 1));
        if (to_render.size() == 4 && enemy1.GetPos().y > 600) {
            if (seed > 500) {
                enemy2.SetPos(vector2i(680, 350));
                to_render.push_back(&enemy2);
                en2 = true;
            } else {
                enemy3.SetPos(vector2i(970, 350));
                to_render.push_back(&enemy3);
                en3 = true;
            }
        }
        if (enemy2.GetPos().y - 350 > 200 && en2 && !en3) {
            enemy3.SetPos(vector2i(970, 350));
            to_render.push_back(&enemy3);
            en3 = true;
        }
        if (enemy3.GetPos().y - 350 > 200 && en3 && !en2) {
            enemy2.SetPos(vector2i(680, 350));
            to_render.push_back(&enemy2);
            en2 = true;
        }
        if (en2) {
            if (enemy2.GetPos().y % 3 == 0)
                enemy2.SetPos(vector2i(enemy2.GetPos().x - 1, enemy2.GetPos().y + 1));
            else enemy2.SetPos(vector2i(enemy2.GetPos().x, enemy2.GetPos().y + 1));
        }
        if (en3) {
            if (enemy3.GetPos().y % 3 == 0)
                enemy3.SetPos(vector2i(enemy3.GetPos().x + 1, enemy3.GetPos().y + 1));
            else enemy3.SetPos(vector2i(enemy3.GetPos().x, enemy3.GetPos().y + 1));
        }

        if (enemy1.GetPos().y > rigidBody.GetHitboxMax().y + 60) {
            enemy1.SetPos(vector2i(enemy1.GetPos().x, 350));
            ++SCORE;
            ScoreDisplay.EditText(("SCORE:" + std::to_string(SCORE)).c_str());
        }

        if (enemy2.GetPos().y > rigidBody.GetHitboxMax().y + 60) {
            enemy2.SetPos(vector2i(700, 350));
            ++SCORE;
            ScoreDisplay.EditText(("SCORE:" + std::to_string(SCORE)).c_str());
        }
        if (enemy3.GetPos().y > rigidBody.GetHitboxMax().y + 60) {
            enemy3.SetPos(vector2i(900, 350));
            ++SCORE;
            ScoreDisplay.EditText(("SCORE:" + std::to_string(SCORE)).c_str());
        }
        if (is_stop) {
            physics.SetVelocity(vector2i(0, 0));
        } else {
            if (keys[SDL_SCANCODE_D]) {
                physics.SetVelocity(vector2i(3, 0));
                physics.MoveRight(rigidBody, objects);
            }
            if (keys[SDL_SCANCODE_A]) {
                physics.SetVelocity(vector2i(3, 0));
                physics.MoveLeft(rigidBody, objects);
            }
        }
        engine.clear_renderer();
        engine.draw_2d_object(background2, 1.0);
        engine.draw_objects(to_render);
        engine.render_text(ScoreDisplay, vector2i(0, 0));
        engine.render_frame();
    }
    soundtrack.MusicStop();
    return 0;
}
