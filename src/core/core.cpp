#include "Core.hpp"

Core::Core()
{
    this->setGraph();
    this->startEngine();
    this->startGraph();
}

Core::~Core()
{
    delete this->engine;
}

void Core::setGraph()
{
    LoadLib<Igraph> init("../libGraph/sfml/sfml.so");
    this->Graph = init.init();
    this->Graph->setWindow(30, "", {1080, 920});
}

void Core::startEngine()
{
    this->engine = new Engine(this->Graph);
    this->engine->initCreatCube();
}

void Core::startGraph()
{
    while (this->Graph->isOpen()) {
        this->Graph->pollEvent();
        this->Graph->clear();

        this->engine->dispCreatCube();

        this->Graph->drawAllShape();

        this->Graph->display();
    }
}