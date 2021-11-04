#include "../../lib/LoadLib/LoadLib.hpp"
#include "../render3D/render3D.hpp"

class core
{
    private:
        Igraph *graph;

    public:
        core();
        ~core();

        void start();
};
