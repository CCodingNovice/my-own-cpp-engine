#include <cstring>
#include "RigidBody.hpp"

RigidBody::RigidBody() {
    mass = 1;
    use_gravity = false;
    is_movable = false;
}

RigidBody::RigidBody(float m, bool gravity, bool movable) {
    mass = m;
    use_gravity = gravity;
    is_movable = movable;
}

RigidBody &RigidBody::operator=(Object_2d &object2d) {
    pos = object2d.GetPos();
    size = object2d.GetSize();
    strcpy(tex_path, object2d.GetPath());
    return *this;
}

char *RigidBody::GetPath() {
    return Object_2d::GetPath();
}

bool RigidBody::Is_movable() {
    return is_movable;
}

float RigidBody::GetMass() {
    return mass;
}

bool RigidBody::UsingGravity() {
    return use_gravity;
}

vector2i RigidBody::GetPos() {
    return Hitbox::GetHitboxMin();
}


vector2ui RigidBody::GetSize() {
    return size;
}

void RigidBody::SetPos(vector2i pos) {
    vector2i temp;
    temp = Hitbox::GetHitboxMin();
    temp.x = pos.x - temp.x;
    temp.y = pos.y - temp.y;
    Hitbox::SetHitboxPos(temp);
    Object_2d::SetPos(temp);
}

vector2i RigidBody::GetHitboxMax() {
    return Hitbox::GetHitboxMax();
}

vector2i RigidBody::GetHitboxMin() {
    return Hitbox::GetHitboxMin();
}

RigidBody::RigidBody(vector2i HitboxMin, vector2i HitboxMax) {
    min = HitboxMin;
    max = HitboxMax;
}

vector2i RigidBody::GetTexturePos() {
    return pos;
}

SDL_Texture *RigidBody::GetTexture() {
    return Object_2d::GetTexture();
}


RigidBody::~RigidBody() = default;
