#ifndef ENGINE_PLAYER_HPP
#define ENGINE_PLAYER_HPP

#include "Hitbox.hpp"
#include "RigidBody.hpp"

class Player : RigidBody {
public:
    bool Is_movable() override;

    vector2i GetPos() override;

    vector2ui GetSize() override;

    vector2i GetHitboxMin() override;

    vector2i GetHitboxMax() override;

    char *GetPath() override;

    float GetMass() override;

    bool UsingGravity() override;

    void SetPos(vector2i pos) override;

};

#endif //ENGINE_PLAYER_HPP
