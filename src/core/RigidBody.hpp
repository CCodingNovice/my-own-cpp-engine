#ifndef ENGINE_RIGIDBODY_HPP
#define ENGINE_RIGIDBODY_HPP

#include "Object_2d.hpp"
#include "Hitbox.hpp"

class RigidBody : Object_2d, Hitbox {
public:
    RigidBody();

    RigidBody(float m, bool gravity, bool movable);

    RigidBody(vector2i HitboxMin, vector2i HitboxMax);

    ~RigidBody();
    RigidBody& operator = (Object_2d &object2d);

    virtual bool Is_movable();

    vector2i GetPos() override;

    virtual vector2i GetTexturePos();

    vector2ui GetSize() override;
    char* GetPath() override;

    virtual float GetMass();

    virtual bool UsingGravity();

    void SetPos(vector2i pos) override;

    vector2i GetHitboxMin() override;

    vector2i GetHitboxMax() override;

    SDL_Texture *GetTexture() override;

protected:
    float inertion;
    float mass;
    float acceleration;
    bool use_gravity;
    bool is_movable;
};

#endif //ENGINE_RIGIDBODY_HPP
