#include "Engine.hpp"

Engine::Engine(Igraph *graph) :
Graph(graph)
{
}

Engine::~Engine()
{
    delete this->object;
    delete this->object1;
}

void Engine::initCreatCube()
{
    this->object = new Cube("FirstCub", 200);
    this->object1 = new Cube("FirstCub1", 30);

    this->object->setCenter(Point2D_s::Create(0, 0));
    this->object1->setCenter(Point2D_s::Create(0, 0));

    // this->object->addOrigine(Point3D_s::Create(200, 0, 0));
    // this->object1->addOrigine(Point3D_s::Create(0, 0, 0));
}

void Engine::dispCreatCube()
{


    // this->object->addRotationX(0.01);

    this->moov(this->object);
    this->moov(this->object1);
    // this->rotation(this->object);

    // this->object1->addRotationX(0.05);
    // this->object->addRotationX(0.05);

    this->Graph->setAllLineShape(this->object->getObject2D());
    this->Graph->setAllLineShape(this->object1->getObject2D());
}

void Engine::moov(Object *object)
{
    const double speed = 8;
    std::vector<std::string> keys = this->Graph->getKey();

    if (keys.size() != 0) {
        for (std::string &i : keys) {
            if (i == "Z") {
                object->addOrigine(Point3D_s::Create(0, 0, -speed));
            }
            if (i == "S") {
                object->addOrigine(Point3D_s::Create(0, 0, speed));
            }
            if (i == "Q") {
                object->addOrigine(Point3D_s::Create(speed, 0, 0));
            }
            if (i == "D") {
                object->addOrigine(Point3D_s::Create(-speed, 0, 0));
            }

            if (i == "Space") {
                object->addOrigine(Point3D_s::Create(0, speed, 0));
            }

            if (i == "ShiftSpace") {
                object->addOrigine(Point3D_s::Create(0, -8, 0));
            }
        }
    }
}

void Engine::rotation(Object *object)
{
    std::vector<std::string> keys = this->Graph->getKey();

    if (keys.size() != 0) {
        for (std::string &i : keys) {
            if (i == "Left") {
                object->addRotationX(0.1);
            }
            if (i == "Right") {
                object->addRotationX(-0.1);
            }
        }
    }
}
