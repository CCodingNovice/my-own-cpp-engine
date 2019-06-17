#include "Physics.hpp"
#include "AABB.hpp"

void Physics::MoveRight(RigidBody &rigidBody, std::vector<RigidBody> objects) {
    for (auto &object : objects) {
        if(!Collision(rigidBody, object, 1) && rigidBody.Is_movable()){
            rigidBody.ChangeX(rigidBody.Get_x() + x_velocity);
        }
    }
}

void Physics::MoveLeft(RigidBody &rigidBody, std::vector<RigidBody> objects) {
    for (auto &object : objects) {
        if(!Collision(rigidBody, object, -1) && rigidBody.Is_movable()){
            rigidBody.ChangeX(rigidBody.Get_x() - x_velocity);
        }
    }
}

void Physics::MoveUp(RigidBody &rigidBody) {

}

void Physics::MoveDown(RigidBody &rigidBody) {

}

bool Physics::Collision(RigidBody rb1, RigidBody rb2, int sign) {
    AABB a,b;
    a = rb1;
    b = rb2;
    return a.AABBvsAABB(b, sign*x_velocity);
}

Physics::Physics(int xvel, int yvel) {
    x_velocity = xvel;
    y_velocity = yvel;
}

int Physics::Get_x_velocity() {
    return x_velocity;
}

int Physics::Get_y_velocity() {
    return y_velocity;
}
