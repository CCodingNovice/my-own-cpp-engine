#include "AABB.hpp"

bool AABB::AABBvsAABB(AABB object, int x_velocity, int y_velocity) {
    if (max.x + x_velocity < object.min.x || min.x + x_velocity > object.max.x) return false;
    return !(max.y + y_velocity < object.min.y || min.y + y_velocity > object.max.y);
}

AABB &AABB::operator=(RigidBody rigidBody) {
    min.x = rigidBody.Get_x();
    min.y = rigidBody.Get_y();
    max.x = rigidBody.Get_x() + rigidBody.Get_width();
    max.y = rigidBody.Get_y() + rigidBody.Get_height();
    return *this;
}

AABB::AABB() {
    max.x = 0;
    max.y = 0;
    min.x = 0;
    min.x = 0;
}
