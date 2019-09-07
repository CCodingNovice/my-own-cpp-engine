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

    Object_2d En = Object_2d(720, 150, 400, 330, "../src/assets/Enemy.png");
    Object_2d background2 = Object_2d(0, 0, SCREENWIDTH, SCREENWIDTH, "../src/assets/background_100px_2.png");
    Player player = Player(800, 800, 400, 330, "../src/assets/Car.png", vector2i(920, 970), vector2i(1080, 1050));
    RigidBody enemy1 = RigidBody(vector2i(840, 360), vector2i(1020, 450));
    RigidBody enemy2 = RigidBody(vector2i(840, 360), vector2i(1020, 450));
    RigidBody enemy3 = RigidBody(vector2i(840, 360), vector2i(1020, 450));
    RigidBody left_bound = RigidBody(vector2i(0, 800), vector2i(420, 1080));
    RigidBody right_bound = RigidBody(vector2i(1500, 800), vector2i(1920, 1080));

    enemy1 = En;
    enemy2 = En;
    enemy3 = En;

    std::vector<RigidBody> objects;
    std::vector<RigidBody *> to_render;

    objects.push_back(left_bound);
    objects.push_back(right_bound);

    to_render.push_back(&enemy1);
    to_render.push_back(&left_bound);
    to_render.push_back(&right_bound);

    Animation toLeft = Animation(4, 1, {vector2i(50, 0)});
    player.addAnimation("left", toLeft);

    bool en2 = false;
    bool en3 = false;
    vector2i a;
    a.x = 4;
    a.y = 6;
    Physics physics = Physics(a);

    bool menu = true;
    Button start_btn = Button(vector2i(840, 600), vector2i(200, 100), "START", {100, 100, 200}, {255, 255, 255});
    Button resume_btn = Button(vector2i(840, 600), vector2i(200, 100), "RESUME", {100, 100, 200}, {255, 255, 255});
    Button quit_btn = Button(vector2i(840, 750), vector2i(200, 100), "EXIT", {100, 100, 200}, {255, 255, 255});

    engine.init();
    engine.set_window_options(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, "Example game",
                              SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    engine.set_renderer_options(SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    Music soundtrack = Music("../src/assets/Music/Lost_Control.mp3");
    soundtrack.musicPlay();

    SDL_Event e;
    bool is_stop;
    bool quit = false;

    while (menu) {
        engine.clear_renderer();
        engine.draw(background2, 1.0);
        engine.draw(start_btn);
        engine.render_frame();
        while (SDL_PollEvent(&e)) {
            if (e.key.keysym.sym == SDLK_ESCAPE) {
                menu = false;
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                vector2i pos;
                SDL_GetMouseState(&pos.x, &pos.y);
                if (start_btn.onClick(pos)) {
                    menu = false;
                }
            }
        }
    }

    srand(unsigned(std::time(nullptr)));
    int seed = std::rand() % 1000;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.key.keysym.sym == SDLK_ESCAPE) {
                menu = true;
            }
        }

        is_stop = !(keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_D]);
        physics.setVelocity(vector2i(1, 0));
        if (physics.collision(player, enemy1, 1, 'Y') || physics.collision(player, enemy2, 1, 'Y') ||
            physics.collision(player, enemy3, 1, 'Y')) {
            return 0;
        }
        enemy1.setPos(vector2i(enemy1.getPos().x, enemy1.getPos().y + 3));
        if (to_render.size() == 3 && enemy1.getPos().y > 600) {
            if (seed > 500) {
                enemy2.setPos(vector2i(680, 350));
                to_render.push_back(&enemy2);
                en2 = true;
            } else {
                enemy3.setPos(vector2i(990, 350));
                to_render.push_back(&enemy3);
                en3 = true;
            }
        }
        if (enemy2.getPos().y - 350 > 200 && en2 && !en3) {
            enemy3.setPos(vector2i(990, 350));
            to_render.push_back(&enemy3);
            en3 = true;
        }
        if (enemy3.getPos().y - 350 > 200 && en3 && !en2) {
            enemy2.setPos(vector2i(680, 350));
            to_render.push_back(&enemy2);
            en2 = true;
        }
        if (en2) {
            if (enemy2.getPos().y % 2 == 0)
                enemy2.setPos(vector2i(enemy2.getPos().x - 2, enemy2.getPos().y + 3));
            else enemy2.setPos(vector2i(enemy2.getPos().x, enemy2.getPos().y + 3));
        }
        if (en3) {
            if (enemy3.getPos().y % 2 == 0)
                enemy3.setPos(vector2i(enemy3.getPos().x + 2, enemy3.getPos().y + 3));
            else enemy3.setPos(vector2i(enemy3.getPos().x, enemy3.getPos().y + 3));
        }

        if (enemy1.getPos().y > player.getHitboxMax().y + 60) {
            enemy1.setPos(vector2i(enemy1.getPos().x, 350));
            ++SCORE;
            ScoreDisplay.editText(("SCORE:" + std::to_string(SCORE)).c_str());
        }

        if (enemy2.getPos().y > player.getHitboxMax().y + 60) {
            enemy2.setPos(vector2i(700, 350));
            ++SCORE;
            ScoreDisplay.editText(("SCORE:" + std::to_string(SCORE)).c_str());
        }
        if (enemy3.getPos().y > player.getHitboxMax().y + 60) {
            enemy3.setPos(vector2i(990, 350));
            ++SCORE;
            ScoreDisplay.editText(("SCORE:" + std::to_string(SCORE)).c_str());
        }
        if (is_stop) {
            physics.setVelocity(vector2i(0, 0));
        } else {
            if (keys[SDL_SCANCODE_D]) {
                physics.setVelocity(vector2i(5, 0));
                physics.moveRight(player, objects);
            }
            if (keys[SDL_SCANCODE_A]) {
                physics.setVelocity(vector2i(5, 0));
                physics.moveLeft(player, objects);
            }
        }

        engine.clear_renderer();
        engine.draw(background2, 1.0);
        engine.draw(to_render);
        engine.draw(player, 1.0);
        engine.draw(ScoreDisplay, vector2i(0, 0));
        engine.render_frame();
        while (menu) {
            engine.clear_renderer();
            engine.draw(background2, 1.0);
            engine.draw(resume_btn);
            engine.draw(quit_btn);
            engine.render_frame();
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_MOUSEBUTTONDOWN) {
                    vector2i pos;
                    SDL_GetMouseState(&pos.x, &pos.y);
                    if (start_btn.onClick(pos)) {
                        menu = false;
                    }
                    if (quit_btn.onClick(pos)) {
                        menu = false;
                        quit = true;
                    }
                }
            }
        }
    }
    soundtrack.musicStop();
    return 0;
}
