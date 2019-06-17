#include <cstring>
#include "RigidBody.hpp"
#include "AABB.hpp"

RigidBody::RigidBody() {
    mass = 1;
    use_gravity = true;
    is_movable = true;
}

RigidBody::RigidBody(float m, bool gravity, bool movable) {
    mass = m;
    use_gravity = gravity;
    is_movable = movable;
}

RigidBody &RigidBody::operator=(Object_2d &object2d) {
    x_pos = object2d.Get_x();
    y_pos = object2d.Get_y();
    width = object2d.Get_width();
    height = object2d.Get_height();
    strcpy(tex_path, object2d.GetPath());
    return *this;
}

int RigidBody::Get_x() {
    return Object_2d::Get_x();
}

char *RigidBody::GetPath() {
    return Object_2d::GetPath();
}

int RigidBody::Get_y() {
    return Object_2d::Get_y();
}

int RigidBody::Get_width() {
    return Object_2d::Get_width();
}

int RigidBody::Get_height() {
    return Object_2d::Get_height();
}

void RigidBody::ChangeX(int x0) {
    x_pos = x0;
}

void RigidBody::ChangeY(int y0) {
    y_pos = y0;
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
