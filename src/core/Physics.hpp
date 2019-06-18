#ifndef ENGINE_PHYSICS_HPP
#define ENGINE_PHYSICS_HPP

#include <vector>
#include "RigidBody.hpp"

class Physics{
public:
    Physics(int xvel, int yvel);

    bool Collision(RigidBody rb1, RigidBody rb2, int sign, char c);
    void MoveRight(RigidBody &rigidBody, std::vector<RigidBody> objects);
    void MoveLeft(RigidBody &rigidBody, std::vector<RigidBody> objects);
    void MoveUp(RigidBody &rigidBody, std::vector<RigidBody> objects);
    void MoveDown(RigidBody &rigidBody, std::vector<RigidBody> objects);

    /*void Jump(RigidBody &rigidBody, std::vector<RigidBody> objects);*/
    int Get_x_velocity();

    int Get_y_velocity(RigidBody rigidBody);
private:
    int x_velocity, y_velocity;
};


#endif //ENGINE_PHYSICS_HPP
