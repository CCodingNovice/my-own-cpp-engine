#include "vector.hpp"

namespace my_engine {

    template<class T>
    vector<2, T>::vector() : x(0), y(0) {}

    template<class T>
    vector<2, T>::vector(T x, T y) : x(x), y(y) {}

    template
    class vector<2, int>;

    template
    class vector<2, unsigned int>;

    template
    class vector<2, float>;
}