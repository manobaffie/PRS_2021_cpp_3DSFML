#include "../../libGraph/Igraph.hpp"
#include "../loadObject/loadObject.hpp"

class render3D
{
    private:
        loadObject lo;
    public:
        render3D();
        ~render3D();

        std::vector<Line2D_s> getObject2D(std::string id);
        void addRotationXAllObject(Point3D_s rota);
        void addPerspectiveAllObject();


};

