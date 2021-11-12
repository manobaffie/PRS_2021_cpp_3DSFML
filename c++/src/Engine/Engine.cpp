#include "Engine.hpp"

Engine::Engine(Igraph *graph) :
Graph(graph)
{
}

Engine::~Engine()
{
}

void Engine::initCreatObject()
{
    // this->object = new Blender("FirstBlender", "../BlenderFile/Lowpoly_tree_sample.obj");
    this->object = new Blender("FirstBlender", "../BlenderFile/Anime_charcter.obj");
    // this->object = new Blender("FirstBlender", "../BlenderFile/poison.OBJ");
    this->object->addOrigine(Point3D_s::Create(0, 0, 500));

    // this->object->printAllObject3D();
}

void Engine::dispCreatObject()
{
    this->moov(this->object);
    for (const Shape2D_s &i : this->object->getObject2D()) {
        // std::cout << i.id << std::endl;
        this->Graph->setConvexShape(i.id, i.Shape2D);
    }
}

void Engine::moov(Object *object)
{
    const double speed = 20;
    std::vector<std::string> keys = this->Graph->getKey();

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
        if (i == "Up") {
            object->addOrigine(Point3D_s::Create(0, speed, 0));
        }
        if (i == "Down") {
            object->addOrigine(Point3D_s::Create(0, -speed, 0));
        }
        if (i == "Left") {
            object->addRotationX(0.1);
        }
        if (i == "Right") {
            object->addRotationX(-0.1);
        }
    }
}