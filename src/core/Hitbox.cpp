
#include "Hitbox.hpp"

my_engine::vector2i Hitbox::getHitboxMin() {
    return min;
}

my_engine::vector2i Hitbox::getHitboxMax() {
    return max;
}

void Hitbox::setHitboxPos(my_engine::vector2i offset) {
    min.x = Hitbox::getHitboxMin().x + offset.x;
    min.y = Hitbox::getHitboxMin().y + offset.y;
    max.x = Hitbox::getHitboxMax().x + offset.x;
    max.y = Hitbox::getHitboxMax().y + offset.y;
}
