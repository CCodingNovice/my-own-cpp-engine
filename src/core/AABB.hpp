#ifndef ENGINE_AABB_HPP
#define ENGINE_AABB_HPP

#include <vector>
#include "RigidBody.hpp"
class cords {
public:
    int x, y;
};

class AABB {
public:
    AABB();

    bool AABBvsAABB(AABB object, int xvelocity, int yvelocity);
    AABB& operator = (RigidBody rigidBody);
private:
    cords min;
    cords max;
};


#endif //ENGINE_AABB_HPP
