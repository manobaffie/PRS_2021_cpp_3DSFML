#include <vector>
#include <iostream>

#include "Point.hpp"
#include "../../libGraph/Igraph.hpp"

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
        Object(std::string id, Point3D_s origine);
        ~Object();

        void setObject();

        std::vector<Line3D_s> getPerspective();
        std::vector<Line2D_s> getObject2D();
        std::string getId();

        void addOrigine();
        void addRotationX(Point3D_s Rotation);
        Point3D_s calcRotation(Point3D_s point, Point3D_s rota);

        void printAllObject3D();
};
