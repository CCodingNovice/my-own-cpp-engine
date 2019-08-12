#include <cmath>

#include "Physics.hpp"
#include "AABB.hpp"

void Physics::MoveRight(RigidBody &rigidBody, std::vector<RigidBody> objects) {
    if (objects.empty()) {
        rigidBody.SetPos(vector2i(rigidBody.GetPos().x + velocity.x, rigidBody.GetPos().y));
        return;
    }
    for (auto &object : objects) {
        if (!Collision(rigidBody, object, 1, 'X')) {
            rigidBody.SetPos(vector2i(rigidBody.GetPos().x + velocity.x, rigidBody.GetPos().y));
        }
        if (Collision(rigidBody, object, 1, 'X')) {
            rigidBody.SetPos(vector2i(object.GetPos().x - (rigidBody.GetHitboxMax().x - rigidBody.GetHitboxMin().x),
                                      rigidBody.GetPos().y));
        }
    }
}

void Physics::MoveLeft(RigidBody &rigidBody, std::vector<RigidBody> objects) {
    if (objects.empty()) {
        rigidBody.SetPos(vector2i(rigidBody.GetPos().x - velocity.x, rigidBody.GetPos().y));
        return;
    }
    for (auto &object : objects) {
        if (!Collision(rigidBody, object, -1, 'X')) {
            rigidBody.SetPos(vector2i(rigidBody.GetPos().x - velocity.x, rigidBody.GetPos().y));
        }
        if (Collision(rigidBody, object, -1, 'X')) {
            rigidBody.SetPos(vector2i(object.GetHitboxMax().x, rigidBody.GetPos().y));
        }
    }
}

void Physics::MoveUp(RigidBody &rigidBody, std::vector<RigidBody> objects) {
    if (objects.empty()) {
        rigidBody.SetPos(vector2i(rigidBody.GetPos().x, rigidBody.GetPos().y - velocity.y));
        return;
    }
    for (auto &object : objects) {
        if (!Collision(rigidBody, object, -1, 'Y')) {
            rigidBody.SetPos(vector2i(rigidBody.GetPos().x, rigidBody.GetPos().y - velocity.y));
        }
        if (Collision(rigidBody, object, -1, 'Y')) {
            rigidBody.SetPos(vector2i(rigidBody.GetPos().x, object.GetHitboxMax().y));
        }
    }
}

void Physics::MoveDown(RigidBody &rigidBody, std::vector<RigidBody> objects) {
    if (objects.empty()) {
        rigidBody.SetPos(vector2i(rigidBody.GetPos().x, rigidBody.GetPos().y + velocity.y));
        return;
    }
    for (auto &object : objects) {
        if (!Collision(rigidBody, object, 1, 'Y')) {
            rigidBody.SetPos(vector2i(rigidBody.GetPos().x, rigidBody.GetPos().y + velocity.y));
        }
        if (Collision(rigidBody, object, 1, 'Y')) {
            rigidBody.SetPos(vector2i(rigidBody.GetPos().x, object.GetHitboxMin().y -
                                                            (rigidBody.GetHitboxMax().y - rigidBody.GetHitboxMin().y)));
        }
    }
}

bool Physics::Collision(RigidBody rb1, RigidBody rb2, int sign, char c) {
    AABB a,b;
    a = rb1;
    b = rb2;
    if (c == 'X') { return a.AABBvsAABB(b, velocity.x * sign, 0); }
    if (c == 'Y') { return a.AABBvsAABB(b, 0, velocity.y * sign); }
    else return true;
}

Physics::Physics(vector2i vel) {
    velocity = vel;
}

int Physics::Get_x_velocity() {
    return velocity.x;
}

int Physics::Get_y_velocity() {
    return velocity.y;
}

void Physics::SetVelocity(vector2i vel) {
    velocity = vel;
}

bool Physics::OnGround(RigidBody rigidBody, std::vector<RigidBody> objects) {
    if (objects.empty()) {
        return false;
    }
    for (auto &object : objects) {
        if (rigidBody.GetHitboxMax().y == object.GetHitboxMin().y)
            return true;
    }
    return false;
}
