#ifndef Object_HPP
#define Object_HPP

#include <vector>
#include <iostream>

#include "Point.hpp"

#define RerolutionX 1080
#define RerolutionY 920

#define FieldOfView 45

class Object
{
    private:
        std::string Id;
        double Z0;
        Point2D_s Center;

    protected:
        std::vector<Shape3D_s> Oshape3D;

    public:
        Object(const std::string &id);
        ~Object();

        void setObject();
        void setCenter(const Point2D_s &center);

        const std::vector<Shape2D_s> getObject2D();
        const std::string &getId();

        void addOrigine(const Point3D_s &origine);
        void addRotationX(const double &speed);
        Point3D_s calcRotationX(const Point3D_s &point, const Point3D_s &rota);

        void printAllObject3D();
};

#endif