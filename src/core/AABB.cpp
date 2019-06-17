#include "AABB.hpp"

bool AABB::AABBvsAABB(AABB object, int velocity) {
    if(max.x + velocity < object.min.x || min.x - velocity > object.max.x) return false;
    if(max.y + velocity < object.min.y || min.y - velocity > object.max.y) return false;
    return true;
}

AABB &AABB::operator=(RigidBody rigidBody) {
    min.x = rigidBody.Get_x();
    min.y = rigidBody.Get_y();
    max.x = rigidBody.Get_x() + rigidBody.Get_width();
    max.y = rigidBody.Get_y() + rigidBody.Get_height();
    return *this;
}
