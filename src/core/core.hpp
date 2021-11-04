#include "../../libGraph/Igraph.hpp"
#include "../../lib/LoadLib/LoadLib.hpp"

class core
{
    private:
        Igraph *graph;

    public:
        core();
        ~core();

        void start();
};
