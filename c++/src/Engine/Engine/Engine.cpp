#include "Engine.hpp"

Engine::Engine(Graph *win) :
window(win)
{
    this->FieldOfView = 45;
    this->resolution = this->window->getSize();

    // this->obj = new Blender(this->resolution, this->FieldOfView, "./../BlenderFile/CubeBlender.obj");

    this->obj = new Blender(this->resolution, this->FieldOfView, "./../BlenderFile/Lowpoly_tree_sample.obj");
    this->entity = new sfmlEntity(*this->vvpvertices, {100, 10, 10, 100});

    // this->obj = new Blender(this->resolution, this->FieldOfView, "./../BlenderFile/poison.OBJ");

    this->vvpvertices = this->obj->getVertices2d();

}

Engine::~Engine()
{
}

void Engine::draw()
{
    this->obj->rotation({.x = 0.0f, .y = 0.0f, .z = 0.05f});
    this->obj->render2d();
    window->draw(entity);
}
