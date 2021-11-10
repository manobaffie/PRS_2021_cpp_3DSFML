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
        Point3D_s Origine;

        double Z0;

    protected:
        std::vector<Line3D_s> Shape3D;

    public:
        Object(const std::string &id, const Point3D_s &origine);
        ~Object();

        void setObject();

        const std::vector<Line3D_s> getPerspective();
        const std::vector<Line2D_s> getObject2D();
        const std::string &getId();

        void addOrigine();
        void addRotationX(const double &speed);
        Point3D_s calcRotationX(const Point3D_s &point, const Point3D_s &rota);

        void printAllObject3D();
};
