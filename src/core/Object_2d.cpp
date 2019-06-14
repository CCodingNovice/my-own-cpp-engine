#include "Object_2d.hpp"
#include "Engine.hpp"
#include <SDL.h>

#include <SDL_image.h>
#include <cstring>

Object_2d::Object_2d() {
    x_pos = 0;
    y_pos = 0;
    strcpy(tex_path,"");
}

Object_2d::Object_2d(int x, int y, const char texturePath[100]) {
    x_pos = x;
    y_pos = y;
    strcpy(tex_path, texturePath);
}

Object_2d::~Object_2d() {

}

int Object_2d::Get_x() {
    return x_pos;
}

int Object_2d::Get_y() {
    return y_pos;
}

char *Object_2d::GetPath() {
    return tex_path;
}


