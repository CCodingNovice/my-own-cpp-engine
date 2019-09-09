#include "vector.hpp"
#include <cmath>

namespace my_engine {

    template<class T>
    vector<2, T>::vector() : x(0), y(0) {}

    template<class T>
    vector<2, T>::vector(T x, T y) : x(x), y(y) {}

    template<>
    vector<2, int> vector<2, int>::absolute() {
        return {abs(x), abs(y)};
    }

    template<>
    vector<2, float> vector<2, float>::absolute() {
        return {(float)fabs(x), (float)fabs(y)};
    }

    template<class T>
    double vector<2, T>::lenght(vector<2, T> &v) {
        return sqrt(pow((v.x - x), 2) + pow((v.y - y), 2));
    }

    template<>
    vector<2, int> &vector<2, int>::operator=(vector<2, float> &v) {
        this->x = (int)v.x;
        this->y = (int)v.y;
        return *this;
    }

    template<class T>
    vector<2, T> &vector<2, T>::operator-(vector<2, T> &v) {
        this->x -= v.x;
        this->y -= v.y;
        return *this;
    }

    template<class T>
    vector<2, T> &vector<2, T>::operator+(vector<2, T> &v) {
        this->x += v.x;
        this->y += v.y;
        return *this;
    }

    template<class T>
    vector<2, T> &vector<2, T>::operator*(vector<2, T> &v) {
        this->x *= v.x;
        this->y *= v.y;
        return *this;
    }

    template<class T>
    vector<2, T> &vector<2, T>::operator/(vector<2, T> &v) {
        this->x /= v.x;
        this->y /= v.y;
        return *this;
    }

    template<>
    vector<2, unsigned int> &vector<2, unsigned int>::operator=(vector<2, float> &v) {
        this->x = static_cast<unsigned int>((int)v.x);
        this->y = static_cast<unsigned int>((int)v.y);
        return *this;
    }

    template<class T>
    bool vector<2, T>::operator==(vector<2, T> &v1) const {
        return (x == v1.x && y == v1.y);
    }

    template
    class vector<2, int>;

    template
    class vector<2, unsigned int>;

    template
    class vector<2, float>;
}