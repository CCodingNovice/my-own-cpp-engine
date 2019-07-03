#ifndef ENGINE_VECTOR_HPP
#define ENGINE_VECTOR_HPP

namespace my_engine {
    template<int L, class T>
    class vector;

    typedef vector<2, int> vector2i;
    typedef vector<3, int> vector3i;
    typedef vector<4, int> vector4i;
    typedef vector<2, unsigned int> vector2ui;
    typedef vector<3, unsigned int> vector3ui;
    typedef vector<4, unsigned int> vector4ui;

    template<class T>
    class vector<2, T> {
    public:
        T x, y;

        vector();

        vector(T x, T y);
    };
}
#endif //ENGINE_VECTOR_HPP
