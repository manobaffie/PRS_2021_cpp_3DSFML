#ifndef Point_HPP
#define Point_HPP

#include <iostream>
#include <cmath>

#define PI 3.14159265

template <class T>
class Point
{
    private:

    public:
        T x;
        T y;
        T z;

        Point() = default;
        Point(T x, T y, T z = 0.0) :
        x(x), y(y), z(z) {
        };

        ~Point() {
        };

        Point operator*(const Point<T> &p)
        {
            return(Point<T>(this->x * p.x, this->y * p.y, this->z * p.z));
        }

        friend std::ostream& operator<<(std::ostream& os, const Point<T> &p)
        {
            os << " : [" << p.x << ";" << p.y << ";" << p.z << "]";
            return (os);
        }
};

#endif