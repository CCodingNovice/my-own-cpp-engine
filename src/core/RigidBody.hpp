#ifndef ENGINE_RIGIDBODY_HPP
#define ENGINE_RIGIDBODY_HPP

#include <set>
#include "Object_2d.hpp"

class RigidBody : Object_2d{
public:
    RigidBody();
    RigidBody(float m, bool gravity, bool movable);
    RigidBody& operator = (Object_2d &object2d);
    bool Is_movable();
    int Get_x() override;
    int Get_y() override;
    int Get_width() override;
    int Get_height() override;
    char* GetPath() override;
    void ChangeX(int x0);
    void ChangeY(int y0);
    float GetMass();
    bool UsingGravity();
private:
    float mass;
    bool use_gravity;
    bool is_movable;
};

#endif //ENGINE_RIGIDBODY_HPP
