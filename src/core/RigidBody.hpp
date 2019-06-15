#ifndef ENGINE_RIGIDBODY_HPP
#define ENGINE_RIGIDBODY_HPP

#include "Object_2d.hpp"

class RigidBody{
public:
    RigidBody();
    RigidBody(Object_2d object2d, float mass, bool move, float friction_force, bool rotation, float a, double react);
    void move_right();
    void move_left();
    void move_up();
    void move_down();
    int GetX();
    int GetY();
    char *GetPath();
private:
    int x_pos, y_pos;
    char path[100];
    float weight;
    bool is_movable;
    float friction;
    bool is_rotate;
    float angle;
    double reaction;
};

#endif //ENGINE_RIGIDBODY_HPP
