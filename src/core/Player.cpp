#include "Player.hpp"

Player::Player() : RigidBody::RigidBody() {
    this->score = 0;
}

Player::Player(int x, int y, unsigned int width, unsigned int height, const char *texturePath, vector2i hitboxMin, vector2i hitboxMax) : RigidBody(x, y, width,
                                                                                                           height,
                                                                                                           texturePath) {
    min = hitboxMin;
    max = hitboxMax;
}

Player::~Player() {
    SDL_DestroyTexture(this->texture);
}

vector2i Player::getPos() {
    return RigidBody::getPos();
}

vector2i Player::getTexturePos() {
    return RigidBody::getTexturePos();
}

vector2ui Player::getSize() {
    return RigidBody::getSize();
}

char *Player::getPath() {
    return RigidBody::getPath();
}

void Player::setPos(vector2i pos) {
    RigidBody::setPos(pos);
}

vector2i Player::getHitboxMin() {
    return RigidBody::getHitboxMin();
}

vector2i Player::getHitboxMax() {
    return RigidBody::getHitboxMax();
}

SDL_Texture *Player::getTexture() {
    return RigidBody::getTexture();
}

void Player::addAnimation(std:: string name, Animation animation) {
    animations.emplace(name, animation);
}
