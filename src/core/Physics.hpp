#ifndef ENGINE_PHYSICS_HPP
#define ENGINE_PHYSICS_HPP

#include <set>
#include "RigidBody.hpp"
#define GRAVITY_FORCE 9.81

class Physics{
public:
    Physics();
    bool collision(RigidBody player, std::set<RigidBody> rigid_bodies);
private:
    float mass, acceleration, inertion, impulse;
};
#endif //ENGINE_PHYSICS_HPP
