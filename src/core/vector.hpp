#ifndef ENGINE_VECTOR_HPP
#define ENGINE_VECTOR_HPP

namespace my_engine {
    template<int L, typename T>
    class vector;
    typedef vector<2, int> vector2i;
    typedef vector<2, unsigned int> vector2ui;
    typedef vector<2, float> vector2f;

    template<class T>
    class vector<2, T> {
    public:
        T x, y;

        vector();
        vector(T x, T y);
        // template class functions
        vector<2, T> absolute(); // only for signed types
        double lenght(vector &v);
        vector<2, T>& operator= (vector<2, float> &v);
        vector<2, T>& operator- (vector<2, T> &v);
        vector<2, T>& operator+ (vector<2, T> &v);
        vector<2, T>& operator* (vector<2, T> &v);
        vector<2, T>& operator/ (vector<2, T> &v);
        bool operator==(vector<2, T> &v1) const;


    };

}
#endif //ENGINE_VECTOR_HPP
