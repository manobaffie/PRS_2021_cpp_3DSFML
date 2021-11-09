#include <vector>
#include <iostream>

#include "Point.hpp"
#include "../../libGraph/Igraph.hpp"

#define RerolutionX 1080
#define RerolutionY 920

#define FieldOfView 45

class object
{
    private:
        std::vector<Line3D_s> Shape3D;
        std::vector<Line3D_s> Shape3DPerspective;
        std::vector<Line2D_s> Shape2D;
        std::string objectId;

        Point3D_s Origine;

        double Z0;

    public:
        object();
        ~object();

        void setObject(std::string id, std::vector<Line3D_s> Points, Point3D_s origine);

        std::vector<Line2D_s> getObject2D();
        std::string getId();

        void addObject2D();
        void addPerspective();
        void addOrigine();

        void printObject2D();

        void printAllObject3D();
        void printAllPerspectiveObject3D();
};
