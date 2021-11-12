#include "Core.hpp"

Core::Core()
{
    this->setGraph();
    this->startEngine();
    this->startGraph();
}

Core::~Core()
{
    delete this->Graph;
    delete this->loadGraph;
    delete this->engine;
}

void Core::setGraph()
{
    this->loadGraph = new LoadLib<Igraph>("../c++/libGraph/sfml/sfml.so");

    this->Graph = this->loadGraph->init();
    this->Graph->setWindow(30, "", {1080, 920});
}

void Core::startEngine()
{
    this->engine = new Engine(this->Graph);
    this->engine->initCreatObject();
}

void Core::startGraph()
{
    while (this->Graph->isOpen()) {
        this->Graph->pollEvent();
        this->Graph->clear();

        this->engine->dispCreatObject();

        this->Graph->drawAllShape();

        this->Graph->display();
    }
}