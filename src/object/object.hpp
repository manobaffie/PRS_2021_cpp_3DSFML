#include <vector>
#include <iostream>

#include "Point.hpp"
#include "../libGraph/Igraph.hpp"

class object
{
    private:
        std::vector<Line3D_s> Shape;

    public:
        object() = default;
        object(std::string id, std::vector<Line3D_s> Points);
        ~object();

        std::vector<Line2D_s> getObjet();
};
