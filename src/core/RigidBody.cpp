//
// Created by nikit on 15.06.2019.
//

#include <cstring>
#include "RigidBody.hpp"

RigidBody::RigidBody() {
    weight = 0;
    is_movable = false;
    friction = 1;
    is_rotate = false;
    angle = 0;
    reaction = 1;
}

RigidBody::RigidBody(Object_2d object2d, float mass, bool move, float friction_force, bool rotation, float a, double react) {
    x_pos = object2d.Get_x();
    y_pos = object2d.Get_y();
    strcpy(path,object2d.GetPath());
    weight = mass;
    is_movable = move;
    friction = friction_force;
    is_rotate = rotation;
    angle = a;
    reaction = react;
}

int RigidBody::GetX() {
    return x_pos;
}

int RigidBody::GetY() {
    return y_pos;
}

char *RigidBody::GetPath() {
    return path;
}

void RigidBody::move_right() {
    if(is_movable) {
        x_pos += int(reaction);
    }
}

void RigidBody::move_left() {
    if(is_movable){
        x_pos -= int(reaction);
    }
}

void RigidBody::move_up() {
    if(is_movable){
        y_pos -= int(reaction);
    }
}

void RigidBody::move_down() {
    if(is_movable){
        y_pos += int(reaction);
    }
}
