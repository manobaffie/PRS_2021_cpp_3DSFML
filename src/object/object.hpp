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
        std::vector<Line3D_s> Shape;
        std::string Id;

        double Z0;

    public:
        object() = default;
        object(std::string id, std::vector<Line3D_s> Points);
        ~object();

        std::vector<Line2D_s> getObject2D();
        std::string getId();

        void makePerspective();

        void printObject2D();
        void printObject3D();
};
