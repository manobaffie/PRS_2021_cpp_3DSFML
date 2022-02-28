#ifndef Vector_HPP
#define Vector_HPP

#include <vector>
#include <iostream>

namespace vec
{

    template<class T>
    struct vector2D
    {
        T x;
        T y;

        friend std::ostream& operator<<(std::ostream& os, vector2D& v) {
            os << v.x << "\t"<< v.y;
            return (os);
        }
    };

    template<class T>
    struct vector3D
    {
        T x;
        T y;
        T z;
        friend std::ostream& operator<<(std::ostream& os, vector3D& v) {
            os << v.x << "\t"<< v.y << "\t" << v.z;
            return (os);
        }
    };

    template<class T>
    struct vector4D
    {
        T w;
        T x;
        T y;
        T z;
        friend std::ostream& operator<<(std::ostream& os, vector4D& v) {
            os << v.w << "\t" << v.x << "\t"<< v.y << "\t" << v.z;
            return (os);
        }
    };

    typedef vector2D<float> vector2f;
    typedef vector2D<float *> pvector2f;
    typedef vector3D<float> vector3f;
    typedef vector4D<float> vector4f;
    typedef std::vector<pvector2f> vpvector2f;
    typedef std::vector<vector2f> vvector2f;
    typedef std::vector<vector3f> vvector3f;
    typedef std::vector<vector4f> vvector4f;

    typedef vector2D<int> vector2i;
    typedef vector3D<int> vector3i;
    typedef vector4D<int> vector4i;
    typedef vector4D<int *> pvector4i;
    typedef std::vector<vector2i> vvector2i;
    typedef std::vector<vector3i> vvector3i;
    typedef std::vector<vector4i> vvector4i;
    typedef std::vector<pvector4i> vpvector4i;

    typedef vector2D<double> vector2d;
    typedef vector3D<double> vector3d;
    typedef vector4D<double> vector4d;
    typedef std::vector<vector2d> vvector2d;
    typedef std::vector<vector3d> vvector3d;
    typedef std::vector<vector4d> vvector4d;
}

#endif