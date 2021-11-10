#ifndef Point3D_HPP
#define Point3D_HPP

#include <iostream>

#include "../../lib/math/matrix/matrix.hpp"

struct Point2D_s
{
    static Point2D_s Create(int x, int y, std::string id = "")
    {
        Point2D_s Point;
        Point.x = x;
        Point.y = y;
        Point.id = id;
        return (Point);
    }

    int x;
    int y;
    std::string id;

    friend std::ostream& operator<<(std::ostream& os, const Point2D_s &p)
    {
        os << "[" << p.x << ";" << p.y << "]";
        return (os);
    }
};

struct Point3D_s
{
    static Point3D_s Create(double x, double y, double z, std::string id = "")
    {
        Point3D_s Point;

        Point.x = x;
        Point.y = y;
        Point.z = z;
        Point.id = id;

        return (Point);
    }
    
    double x;
    double y;
    double z;
    std::string id;

    Point3D_s operator*(const Point3D_s &p)
    {
        return(Point3D_s::Create(this->x * p.x, this->y * p.y, this->z * p.z, this->id));
    }

    friend std::ostream& operator<<(std::ostream& os, const Point3D_s &p)
    {
        os << p.id << " : [" << p.x << ";" << p.y << ";" << p.z << "]";
        return (os);
    }
};

struct Line2D_s
{
    static Line2D_s Create(Point2D_s p1, Point2D_s p2, std::string id = "", size_t size = 0)
    {
        Line2D_s Line;
        Line.id = id;
        Line.size = size;
        Line.Points1 = p1;
        Line.Points2 = p2;
        return (Line);
    }

    std::string id;
    size_t size;
    Point2D_s Points1;
    Point2D_s Points2;

    friend std::ostream& operator<<(std::ostream& os, const Line2D_s &l)
    {
        os << l.id << " : [" << l.size << "]" << l.Points1 << " <-> " << l.Points2;
        return (os);
    }
};

struct Line3D_s
{
    static Line3D_s Create(Point3D_s p1, Point3D_s p2, std::string id = "", size_t size = 0)
    {
        Line3D_s Line;
        Line.id = id;
        Line.size = size;
        Line.Points1 = p1;
        Line.Points2 = p2;
        return (Line);
    }

    std::string id;
    size_t size;
    Point3D_s Points1;
    Point3D_s Points2;

    friend std::ostream& operator<<(std::ostream& os, const Line3D_s &l)
    {
        os << l.id << " : [" << l.size << "]" << l.Points1 << " <-> " << l.Points2;
        return (os);
    }
};

#endif