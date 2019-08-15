
#include "Hitbox.hpp"

my_engine::vector2i Hitbox::GetHitboxMin() {
    return min;
}

my_engine::vector2i Hitbox::GetHitboxMax() {
    return max;
}

void Hitbox::SetHitboxPos(my_engine::vector2i l) {
    min.x = Hitbox::GetHitboxMin().x + l.x;
    min.y = Hitbox::GetHitboxMin().y + l.y;
    max.x = Hitbox::GetHitboxMax().x + l.x;
    max.y = Hitbox::GetHitboxMax().y + l.y;
}
