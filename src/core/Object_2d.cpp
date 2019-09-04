#include "Object_2d.hpp"

#include <cstring>

Object_2d::Object_2d() {
    texture = nullptr;
}

Object_2d::Object_2d(int x, int y, unsigned int w, unsigned int h, const char texturePath[100]) {
    pos.x = x;
    pos.y = y;
    size.x = w;
    size.y = h;
    texture = nullptr;
    strcpy(tex_path, texturePath);
}

char *Object_2d::getPath() {
    return tex_path;
}

void Object_2d::setPos(vector2i offset) {
    pos.x = pos.x + offset.x;
    pos.y = pos.y + offset.y;
}

vector2i Object_2d::getPos() {
    return pos;
}

vector2ui Object_2d::getSize() {
    return size;
}

Object_2d::~Object_2d() {
    SDL_DestroyTexture(texture);
}

SDL_Texture *Object_2d::getTexture() {
    return texture;
}
