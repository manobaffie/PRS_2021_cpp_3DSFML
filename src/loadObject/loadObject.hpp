#include "../object/object.hpp"

#include <map>

class loadObject
{
    private:
        std::map<std::string, object*> allObject;

    public:
        loadObject();
        ~loadObject();

        void addObject(std::string id, object *Obj);
};
