#ifndef Object_HPP
#define Object_HPP

#include <vector>
#include <iostream>

#include "../../libGraph/Igraph.hpp"
#include "Point.hpp"
#include <iostream>


#define RerolutionX 1080
#define RerolutionY 920

#define FieldOfView 45

class Object
{
    private:
        std::string Id;
        double Z0;
        Point<float> Center;

    protected:
        std::vector<std::vector<Point<float>>> Oshape3D;
        std::vector<std::vector<Point<float>>> Textures;
        double scale;

    public:
        Object(const std::string &id);
        ~Object();

        void setObject();
        void setCenter(const Point<float> &center);

        const std::vector<std::vector<coord_s>> getTextures();

        const std::vector<std::vector<coord_s>> getObject2D();
        const std::vector<coord_s> calcObject2D(const size_t &i);

        const std::string &getId();

        void addOrigine(const Point<float> &origine);
        void addRotationX(const double &speed);
        Point<float> calcRotationX(const Point<float> &point, const Point<float> &rota);

        void printAllObject3D();
};

#endif