#include "../object/cube/cube.hpp"

#include <map>

class loadObject
{
    private:
        std::map<std::string, object*> allObject;

    public:
        loadObject();
        ~loadObject();

        void addObject(object *Obj);

        void printAllObject();
        void printAllPerspectiveObject3D();
        std::vector<Line2D_s> getObject2D(std::string id);
};
