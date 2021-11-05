#include "../../lib/LoadLib/LoadLib.hpp"
#include "../render3D/render3D.hpp"

class core
{
    private:
        Igraph *graph;
        render3D rd;

    public:
        core();
        ~core();

        void start();

        void addtOBJ(std::string id);
};
