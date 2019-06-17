#ifndef ENGINE_PHYSICS_HPP
#define ENGINE_PHYSICS_HPP

#include <vector>
#include "RigidBody.hpp"

class Physics{
public:
    Physics(int xvel, int yvel);
    bool Collision(RigidBody rb1, RigidBody rb2, int sign);
    void MoveRight(RigidBody &rigidBody, std::vector<RigidBody> objects);
    void MoveLeft(RigidBody &rigidBody, std::vector<RigidBody> objects);
    void MoveUp(RigidBody &rigidBody);
    void MoveDown(RigidBody &rigidBody);
    int Get_x_velocity();
    int Get_y_velocity();
private:
    int x_velocity, y_velocity;
};


#endif //ENGINE_PHYSICS_HPP
