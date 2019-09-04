#include <cstring>
#include "RigidBody.hpp"

RigidBody::RigidBody() : Object_2d::Object_2d() {
    this->movable = true;
}

RigidBody::RigidBody(bool isMovable) : Object_2d::Object_2d() {
    this->movable = isMovable;
}

RigidBody &RigidBody::operator=(Object_2d &object2d) {
    pos = object2d.getPos();
    size = object2d.getSize();
    strcpy(tex_path, object2d.getPath());
    return *this;
}

char *RigidBody::getPath() {
    return Object_2d::getPath();
}

bool RigidBody::is_movable() {
    return movable;
}

vector2i RigidBody::getPos() {
    return Hitbox::getHitboxMin();
}

vector2ui RigidBody::getSize() {
    return size;
}

void RigidBody::setPos(vector2i pos) {
    vector2i temp;
    temp = Hitbox::getHitboxMin();
    temp.x = pos.x - temp.x;
    temp.y = pos.y - temp.y;
    Hitbox::setHitboxPos(temp);
    Object_2d::setPos(temp);
}

vector2i RigidBody::getHitboxMax() {
    return Hitbox::getHitboxMax();
}

vector2i RigidBody::getHitboxMin() {
    return Hitbox::getHitboxMin();
}

RigidBody::RigidBody(vector2i HitboxMin, vector2i HitboxMax) {
    min = HitboxMin;
    max = HitboxMax;
}

vector2i RigidBody::getTexturePos() {
    return pos;
}

SDL_Texture *RigidBody::getTexture() {
    return Object_2d::getTexture();
}

RigidBody::RigidBody(int x, int y, unsigned int width, unsigned int height, const char *texturePath) : Object_2d(x, y,
                                                                                                                 width,
                                                                                                                 height,
                                                                                                                 texturePath){
    this->movable = true;
}

RigidBody::~RigidBody() = default;
