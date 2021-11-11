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
        std::vector<Line3D_s> Shape3D;
        std::vector<Line3D_s> Oshape3D;

    public:
        Object(const std::string &id);
        ~Object();

        void setObject();
        void setCenter(const Point2D_s &center);

        void getPerspective();
        const std::vector<Line2D_s> getObject2D();
        const std::string &getId();

        void addOrigine(const Point3D_s &origine);
        void addRotationX(const double &speed);
        Point3D_s calcRotationX(const Point3D_s &point, const Point3D_s &rota);

        void printAllObject3D();
};
