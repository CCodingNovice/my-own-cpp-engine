#ifndef ENGINE_OBJECT_2D_HPP
#define ENGINE_OBJECT_2D_HPP

class Object_2d{
public:
    Object_2d();
    Object_2d(int x, int y, int width, int height, const char *texturePath);
    virtual int Get_x();
    virtual int Get_y();
    virtual int Get_width();
    virtual int Get_height();
    virtual char* GetPath();

protected:
    int x_pos;
    int y_pos;
    int width;
    int height;
    char tex_path[100];
};
#endif //ENGINE_OBJECT_2D_HPP
