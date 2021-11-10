#include "Engine.hpp"

Engine::Engine(Igraph *graph) :
Graph(graph)
{
}

Engine::~Engine()
{
    delete this->object;
    delete this->Graph;
}

void Engine::initCreatCube()
{
    this->object = new Cube("FirstCub", Point3D_s::Create(400, 400, 0), 500);

    this->object->printAllObject3D();
    this->object1->printAllObject3D();

    this->Graph->startClock("FirstCub");
}

void Engine::dispCreatCube()
{
    if (this->Graph->getClock("FirstCub") > 0.01) {

        this->Graph->setAllLineShape(this->object->getObject2D());

        this->object->addRotationX(0.1);
        this->Graph->restartClock("FirstCub");
    }
}
