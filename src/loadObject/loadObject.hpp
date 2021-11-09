#include "../object/cube/cube.hpp"

#include <map>

class loadObject
{
    private:
        std::map<std::string, Object*> allObject;

    public:
        loadObject();
        ~loadObject();

        void addObject(Object *Obj);

        void printAllObject();
        std::vector<Line2D_s> getObject2D(std::string id);
        void addRotationXAllObject(Point3D_s rota);
        void addPerspectiveAllObject();


};
