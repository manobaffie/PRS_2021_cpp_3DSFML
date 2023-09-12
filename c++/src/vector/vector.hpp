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

        friend std::ostream& operator<<(std::ostream& os, const vector2D& v) {
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

        friend std::ostream& operator<<(std::ostream& os, const vector3D& v) {
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

        friend std::ostream& operator<<(std::ostream& os, const vector4D& v) {
            os << v.w << "\t" << v.x << "\t"<< v.y << "\t" << v.z;
            return (os);
        }
    };

}

#endif