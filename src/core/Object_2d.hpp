#ifndef ENGINE_OBJECT_2D_HPP
#define ENGINE_OBJECT_2D_HPP

#include <SDL_render.h>
#include <map>
#include "vector.hpp"
#include "Animation.hpp"

using namespace my_engine;
class Object_2d{
public:
    Object_2d();
    Object_2d(int x, int y, unsigned int width, unsigned int height, const char *texturePath);
    ~Object_2d();
    virtual vector2i getPos();
    virtual vector2ui getSize();
    virtual char* getPath();
    virtual void setPos(vector2i l);
    virtual SDL_Texture *getTexture();
    virtual void addAnimation(const char *name, Animation animation);
    virtual int getAnimationsSize();
    virtual void startAnimation(const char *name, unsigned int startTick);
    virtual SDL_Rect getSourceRect(unsigned int ticks);
    SDL_Texture *texture;

protected:
    vector2i pos;
    vector2ui size;
    char tex_path[100];
    std::map<std::string, Animation> animations;
    char currAnimation[50];
};
#endif //ENGINE_OBJECT_2D_HPP
