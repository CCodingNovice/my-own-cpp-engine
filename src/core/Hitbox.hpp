#ifndef ENGINE_HITBOX_HPP
#define ENGINE_HITBOX_HPP

#include "core/vector.hpp"

class Hitbox {
public:
    virtual my_engine::vector2i GetHitboxMin();

    virtual my_engine::vector2i GetHitboxMax();

    virtual void SetHitboxPos(my_engine::vector2i deltaL);

protected:
    my_engine::vector2i min, max;
};

#endif //ENGINE_HITBOX_HPP
