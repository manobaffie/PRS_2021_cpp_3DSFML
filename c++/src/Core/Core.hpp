#include "../../lib/LoadLib/LoadLib.hpp"
#include "../Engine/Engine.hpp"

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
