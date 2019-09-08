#ifndef ENGINE_PLAYER_HPP
#define ENGINE_PLAYER_HPP

#include "Hitbox.hpp"
#include "RigidBody.hpp"
#include "Animation.hpp"
#include <map>
#include <string>

class Player : public virtual RigidBody {
public:
    Player();
    Player(int x, int y, unsigned int width, unsigned int height, const char *texturePath, vector2i HitboxMin, vector2i HitboxMax);
    ~Player();
    vector2i getPos() override;
    vector2i getTexturePos() override;
    vector2ui getSize() override;
    char* getPath() override;
    void setPos(vector2i pos) override;
    vector2i getHitboxMin() override;
    vector2i getHitboxMax() override;
    SDL_Texture *getTexture() override;
    void addAnimation(const char *name, Animation animation) override;
    int getAnimationsSize() override;
    void startAnimation(const char *name, unsigned int tick) override;
    SDL_Rect getSourceRect(unsigned int ticks) override;

private:
    int score;
};

#endif //ENGINE_PLAYER_HPP
