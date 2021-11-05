#include "core.hpp"

core::core()
{
    // LoadLib<Igraph> test("../libGraph/sfml/sfml.so");
    // this->graph = test.init();
    // this->graph->setWindow(5, "", {1080, 920});

    render3D rd;

}

core::~core()
{
}

void core::start()
{
    while (this->graph->isOpen()) {
        this->graph->pollEvent();
        this->graph->clear();
        this->graph->drawShape("test");
        this->graph->display();
    }
}