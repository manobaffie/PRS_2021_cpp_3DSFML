#include "../../lib/LoadLib/LoadLib.hpp"
#include "../Engine/Engine.hpp"

#include <thread>

class Core
{
    private:
        Igraph *Graph;
        Engine *engine;
        LoadLib<Igraph> *loadGraph;

    public:
        Core();
        ~Core();

        void setGraph();

        void startEngine();
        void startGraph();
};
