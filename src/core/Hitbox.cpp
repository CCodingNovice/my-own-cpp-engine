
#include "Hitbox.hpp"

vector2i Hitbox::GetHitboxMin() {
    return min;
}

vector2i Hitbox::GetHitboxMax() {
    return max;
}

void Hitbox::SetHitboxPos(vector2i l) {
    min.x = Hitbox::GetHitboxMin().x + l.x;
    min.y = Hitbox::GetHitboxMin().y + l.y;
    max.x = Hitbox::GetHitboxMax().x + l.x;
    max.y = Hitbox::GetHitboxMax().y + l.y;
}
