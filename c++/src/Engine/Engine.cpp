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
    // this->object = new Blender("FirstBlender", "../BlenderFile/CubeBlender.obj");
    // this->object = new Blender("FirstBlender", "../BlenderFile/Lowpoly_tree_sample.obj");
    this->object = new Blender("FirstBlender", "../BlenderFile/anime_character/Anime_charcter.obj");
    // this->object = new Blender("FirstBlender", "../BlenderFile/poison.OBJ");

    this->object->addOrigine(Point<float>(0, 0, 500));

    // this->Graph->addEntity("test", this->object->getObject2D(), "../BlenderFile/anime_character/textures.png", this->object->getTextures());
    this->Graph->addEntity("test", this->object->getObject2D());
}

void Engine::dispCreatObject()
{
    this->moov(this->object);

    this->Graph->setCoordEntity("test", this->object->getObject2D());
}

void Engine::moov(Object *object)
{
    const double speed = 20;
    std::vector<std::string> keys = this->Graph->getKey();

    for (std::string &i : keys) {
        if (i == "Z") {
            object->addOrigine(Point<float>(0, 0, -speed));
        }
        if (i == "S") {
            object->addOrigine(Point<float>(0, 0, speed));
        }
        if (i == "Q") {
            object->addOrigine(Point<float>(speed, 0, 0));
        }
        if (i == "D") {
            object->addOrigine(Point<float>(-speed, 0, 0));
        }
        if (i == "Up") {
            object->addOrigine(Point<float>(0, speed, 0));
        }
        if (i == "Down") {
            object->addOrigine(Point<float>(0, -speed, 0));
        }
        if (i == "Left") {
            object->addRotationX(0.1);
        }
        if (i == "Right") {
            object->addRotationX(-0.1);
        }
    }
}