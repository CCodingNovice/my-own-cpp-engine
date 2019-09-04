#ifndef ENGINE_HITBOX_HPP
#define ENGINE_HITBOX_HPP

#include "core/vector.hpp"

class Hitbox {
public:
    virtual my_engine::vector2i getHitboxMin();

    virtual my_engine::vector2i getHitboxMax();

    virtual void setHitboxPos(my_engine::vector2i deltaL);

protected:
    my_engine::vector2i min, max;
};

#endif //ENGINE_HITBOX_HPP
