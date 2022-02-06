#include "../Object/Blender/Blender.hpp"

#include <map>

class Engine
{
    private:
        Igraph *Graph;


        std::vector<Object *> allObject;

        Object *object;

    public:
        Engine(Igraph *graph);
        ~Engine();

        void initCreatObject();
        void dispCreatObject();

        void moov(Object *object);
};
