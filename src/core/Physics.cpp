#include <cmath>

#include "Physics.hpp"
#include "AABB.hpp"

void Physics::moveRight(Player &rigidBody, std::vector<RigidBody> objects) {
    if (objects.empty()) {
        rigidBody.setPos(vector2i(rigidBody.getPos().x + velocity.x, rigidBody.getPos().y));
        return;
    }
    for (auto &object : objects) {
        if (!collision(rigidBody, object, 1, 'X')) {
            rigidBody.setPos(vector2i(rigidBody.getPos().x + velocity.x, rigidBody.getPos().y));
        }
        if (collision(rigidBody, object, 1, 'X')) {
            rigidBody.setPos(vector2i(object.getPos().x - (rigidBody.getHitboxMax().x - rigidBody.getHitboxMin().x),
                                      rigidBody.getPos().y));
        }
    }
}

void Physics::moveLeft(Player &rigidBody, std::vector<RigidBody> objects) {
    if (objects.empty()) {
        rigidBody.setPos(vector2i(rigidBody.getPos().x - velocity.x, rigidBody.getPos().y));
        return;
    }
    for (auto &object : objects) {
        if (!collision(rigidBody, object, -1, 'X')) {
            rigidBody.setPos(vector2i(rigidBody.getPos().x - velocity.x, rigidBody.getPos().y));
        }
        if (collision(rigidBody, object, -1, 'X')) {
            rigidBody.setPos(vector2i(object.getHitboxMax().x, rigidBody.getPos().y));
        }
    }
}

void Physics::moveUp(Player &rigidBody, std::vector<RigidBody> objects) {
    if (objects.empty()) {
        rigidBody.setPos(vector2i(rigidBody.getPos().x, rigidBody.getPos().y - velocity.y));
        return;
    }
    for (auto &object : objects) {
        if (!collision(rigidBody, object, -1, 'Y')) {
            rigidBody.setPos(vector2i(rigidBody.getPos().x, rigidBody.getPos().y - velocity.y));
        }
        if (collision(rigidBody, object, -1, 'Y')) {
            rigidBody.setPos(vector2i(rigidBody.getPos().x, object.getHitboxMax().y));
        }
    }
}

void Physics::moveDown(Player &rigidBody, std::vector<RigidBody> objects) {
    if (objects.empty()) {
        rigidBody.setPos(vector2i(rigidBody.getPos().x, rigidBody.getPos().y + velocity.y));
        return;
    }
    for (auto &object : objects) {
        if (!collision(rigidBody, object, 1, 'Y')) {
            rigidBody.setPos(vector2i(rigidBody.getPos().x, rigidBody.getPos().y + velocity.y));
        }
        if (collision(rigidBody, object, 1, 'Y')) {
            rigidBody.setPos(vector2i(rigidBody.getPos().x, object.getHitboxMin().y -
                                                            (rigidBody.getHitboxMax().y - rigidBody.getHitboxMin().y)));
        }
    }
}

bool Physics::collision(Player rb1, RigidBody rb2, int sign, char c) {
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

int Physics::get_x_velocity() {
    return velocity.x;
}

int Physics::get_y_velocity() {
    return velocity.y;
}

void Physics::setVelocity(vector2i vel) {
    velocity = vel;
}

bool Physics::onGround(Player rigidBody, std::vector<RigidBody> objects) {
    if (objects.empty()) {
        return false;
    }
    for (auto &object : objects) {
        if (rigidBody.getHitboxMax().y == object.getHitboxMin().y)
            return true;
    }
    return false;
}
