#include "Player.hpp"

vector2ui Player::GetSize() {
    return RigidBody::GetSize();
}

vector2i Player::GetPos() {
    return RigidBody::GetPos();
}

bool Player::Is_movable() {
    return RigidBody::Is_movable();
}

char *Player::GetPath() {
    return RigidBody::GetPath();
}

float Player::GetMass() {
    return RigidBody::GetMass();
}

bool Player::UsingGravity() {
    return RigidBody::UsingGravity();
}

void Player::SetPos(vector2i pos) {
    RigidBody::SetPos(pos);
}

vector2i Player::GetHitboxMin() {
    return RigidBody::GetHitboxMin();
}

vector2i Player::GetHitboxMax() {
    return RigidBody::GetHitboxMax();
}
