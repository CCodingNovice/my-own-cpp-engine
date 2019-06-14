#ifndef ENGINE_OBJECT_2D_HPP
#define ENGINE_OBJECT_2D_HPP

class Object_2d{
public:
    Object_2d();
    Object_2d(int x, int y, const char *texturePath);
    ~Object_2d();
    int Get_x();
    int Get_y();
    char* GetPath();
private:
    int x_pos;
    int y_pos;
    char tex_path[100];
};
#endif //ENGINE_OBJECT_2D_HPP
