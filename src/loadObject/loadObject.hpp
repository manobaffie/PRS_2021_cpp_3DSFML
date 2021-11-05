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
};
