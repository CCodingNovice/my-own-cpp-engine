#ifndef ENGINE_RIGIDBODY_HPP
#define ENGINE_RIGIDBODY_HPP

#include "Object_2d.hpp"
#include "Hitbox.hpp"

class RigidBody : public Object_2d, public Hitbox {
public:
    RigidBody();
    RigidBody(bool isMovable);
    RigidBody(int x, int y, unsigned int width, unsigned int height, const char *texturePath);
    RigidBody(vector2i HitboxMin, vector2i HitboxMax);
    ~RigidBody();
    RigidBody& operator = (Object_2d &object2d);
    virtual bool is_movable();
    vector2i getPos() override;
    virtual vector2i getTexturePos();
    vector2ui getSize() override;
    char* getPath() override;
    void setPos(vector2i pos) override;
    vector2i getHitboxMin() override;
    vector2i getHitboxMax() override;
    SDL_Texture *getTexture() override;

protected:
    bool movable;
};

#endif //ENGINE_RIGIDBODY_HPP
