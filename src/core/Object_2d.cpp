#include "Object_2d.hpp"

#include <cstring>

Object_2d::Object_2d() = default;

Object_2d::Object_2d(int x, int y, unsigned int w, unsigned int h, const char texturePath[100]) {
    pos.x = x;
    pos.y = y;
    size.x = w;
    size.y = h;
    strcpy(tex_path, texturePath);
}

char *Object_2d::GetPath() {
    return tex_path;
}

void Object_2d::SetPos(vector2i l) {
    pos.x = pos.x + l.x;
    pos.y = pos.y + l.y;
}

vector2i Object_2d::GetPos() {
    return pos;
}

vector2ui Object_2d::GetSize() {
    return size;
}
