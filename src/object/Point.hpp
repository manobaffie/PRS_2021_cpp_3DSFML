#ifndef Point3D_HPP
#define Point3D_HPP

#include <iostream>

#include "../../lib/math/matrix/matrix.hpp"

struct Point2D_s
{
    static Point2D_s Create(int x, int y)
    {
        return (Point2D_s({x, y}));
    }

    int x;
    int y;
};

struct Point3D_s
{
    static Point3D_s Create(double x, double y, double z)
    {
        return (Point3D_s({x, y, z}));
    }
    
    double x;
    double y;
    double z;
};

struct Line2D_s
{
    static Line2D_s Create(std::string id, size_t size, Point2D_s p1, Point2D_s p2)
    {
        Line2D_s l;
        l.id = id;
        l.size = size;
        l.Points1 = p1;
        l.Points2 = p2;
        return (l);
    }

    std::string id;
    size_t size;

    Point2D_s Points1;
    Point2D_s Points2;
};

struct Line3D_s
{
    static Line3D_s Create(std::string id, size_t size, Point3D_s p1, Point3D_s p2)
    {
        Line3D_s l;
        l.id = id;
        l.size = size;
        l.Points1 = p1;
        l.Points2 = p2;
        return (l);
    }

    std::string id;
    size_t size;

    Point3D_s Points1;
    Point3D_s Points2;
};

#endif