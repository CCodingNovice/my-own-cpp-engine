#ifndef ENGINE_HITBOX_HPP
#define ENGINE_HITBOX_HPP

#include "core/vector.hpp"

using namespace my_engine;

class Hitbox {
public:
    virtual vector2i GetHitboxMin();

    virtual vector2i GetHitboxMax();

    virtual void SetHitboxPos(vector2i deltaL);

protected:
    vector2i min, max;
};

#endif //ENGINE_HITBOX_HPP
