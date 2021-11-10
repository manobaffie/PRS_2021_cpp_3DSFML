#include "../Object/Cube/Cube.hpp"
#include "../../libGraph/Igraph.hpp"

#include <map>

class Engine
{
    private:
        Igraph *Graph;


        std::map<std::string, Object*> allObject;
        Object *object;

    public:
        Engine(Igraph *graph);
        ~Engine();

        void initCreatCube();
        void dispCreatCube();
};
