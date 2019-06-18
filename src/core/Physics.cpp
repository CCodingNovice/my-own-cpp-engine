#include <cmath>
#include "Physics.hpp"
#include "AABB.hpp"

void Physics::MoveRight(RigidBody &rigidBody, std::vector<RigidBody> objects) {
    for (auto &object : objects) {
        if (!Collision(rigidBody, object, 1, 'X') && rigidBody.Is_movable()) {
            rigidBody.ChangeX(rigidBody.Get_x() + x_velocity);
        }
        if (Collision(rigidBody, object, 1, 'X') && rigidBody.Is_movable()) {
            rigidBody.ChangeX(object.Get_x() - rigidBody.Get_width() - 1);
        }
    }
}

void Physics::MoveLeft(RigidBody &rigidBody, std::vector<RigidBody> objects) {
    for (auto &object : objects) {
        if (!Collision(rigidBody, object, -1, 'X') && rigidBody.Is_movable()) {
            rigidBody.ChangeX(rigidBody.Get_x() - x_velocity);
        }
        if (Collision(rigidBody, object, 1, 'X') && rigidBody.Is_movable()) {
            rigidBody.ChangeX(object.Get_x() + object.Get_width() + 1);
        }
    }
}

void Physics::MoveUp(RigidBody &rigidBody, std::vector<RigidBody> objects) {
    for (auto &object : objects) {
        if (!Collision(rigidBody, object, -1, 'Y') && rigidBody.Is_movable()) {
            rigidBody.ChangeY(rigidBody.Get_y() - y_velocity);
        }
        if (Collision(rigidBody, object, 1, 'Y') && rigidBody.Is_movable()) {
            rigidBody.ChangeY(object.Get_y() + object.Get_height() + 1);
        }
    }
}

void Physics::MoveDown(RigidBody &rigidBody, std::vector<RigidBody> objects) {
    for (auto &object : objects) {
        if (!Collision(rigidBody, object, 1, 'Y') && rigidBody.Is_movable()) {
            rigidBody.ChangeY(rigidBody.Get_y() + y_velocity);
        }
    }
}

bool Physics::Collision(RigidBody rb1, RigidBody rb2, int sign, char c) {
    AABB a,b;
    a = rb1;
    b = rb2;
    if (c == 'X') { return a.AABBvsAABB(b, x_velocity * sign, 0); }
    if (c == 'Y') { return a.AABBvsAABB(b, 0, y_velocity * sign); }
}

Physics::Physics(int xvel, int yvel) {
    x_velocity = xvel;
    y_velocity = yvel;
}

int Physics::Get_x_velocity() {
    return x_velocity;
}

int Physics::Get_y_velocity(RigidBody rigidBody) {
    y_velocity = static_cast<int>(y_velocity + floor(9.81 * 1 / 60));
    return y_velocity;
}

/*void Physics::Jump(RigidBody &rigidBody, std::vector<RigidBody> objects) {
    for (auto &object : objects) {
        if (!Collision(rigidBody, object, 1, 'Y') && rigidBody.Is_movable()) {
            rigidBody.ChangeY(rigidBody.Get_y() + Get_y_velocity(rigidBody));
        }
    }
}*/
