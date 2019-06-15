#include "Physics.hpp"

Physics::Physics() {
    mass = 1;
    acceleration = 0;
    impulse = 0;
    inertion = mass*acceleration;
}

bool Physics::collision(RigidBody player, std::set<RigidBody> rigid_bodies) {
    for(auto rb : rigid_bodies){

    }
}
