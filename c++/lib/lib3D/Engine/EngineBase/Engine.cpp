#include "Engine.hpp"

Engine::Engine(Graph *win) :
window(win)
{
    Object *obj = new Blender("./../BlenderFile/CubeBlender.obj");

    this->entity = new sfmlEntity({
        {100, 100}, 
        {200, 100}, 
        {200, 200}, 
        {100, 250}
    }, {100, 100, 100, 100});

    vec::vpvector2f vpvertices = {
        {new float(0), new float(0)},
        {new float(0), new float(0)},
        {new float(0), new float(0)},
        {new float(0), new float(0)}
    };

    entity->loadVertices(vpvertices);

    (*vpvertices[2].x)++;

}

Engine::~Engine()
{
}

void Engine::draw()
{
    window->draw(entity);
}
