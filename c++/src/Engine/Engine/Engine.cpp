#include "Engine.hpp"

Engine::Engine(Graph *win) :
window(win)
{
    this->worldDegres = {0.f, 0.f, 0.f};
    this->player = new Player("./../BlenderFile/CubeBlender.obj");

    this->FieldOfView = 45;
    this->resolution = this->window->getSize();

}

Engine::~Engine()
{
}

void Engine::draw()
{
    for (IGameObject *i : this->objs) {
        i->getObject()->render2d();
        window->draw(i->getEntity());
    }

    this->player->getObject()->render2d();
    window->draw(this->player->getEntity());
}

void Engine::transform()
{
    EventType a = this->window->pollEvent();

    const float speedDeplacement = 5.f;
    const float speedRotaiton = 0.5f;

    vec::vector3f rotaVal = {0, 0, 1};

    if (a.Left) {
        // speedRotation.z = (speedRotaiton * PI / 180);

        this->worldDegres.z += speedRotaiton;
    } else if (a.Right) {
        // speedRotation.z = -(speedRotaiton * PI / 180);

        this->worldDegres.z -= speedRotaiton;
    }
    if (a.Up) {
        // speedRotation.y = (speedRotaiton * PI / 180);

        this->worldDegres.y += speedRotaiton;
    } else if (a.Down) {
        // speedRotation.y = -(speedRotaiton * PI / 180);

        this->worldDegres.y -= speedRotaiton;
    }
    std::cout << this->worldDegres << std::endl;

    this->deplacement(a, rotaVal, speedDeplacement);
    this->rotation(a, rotaVal, (speedRotaiton * PI / 180));
}


void Engine::deplacement(const EventType &a, const vec::vector3f &rotaVal, const float &speed)
{
    for (IGameObject *i : this->objs) {
        this->deplacementObj(i, a, rotaVal, speed);
    }
}

void Engine::rotation(const EventType &a, const vec::vector3f &rotaVal, const float &speed)
{
    for (IGameObject *i : this->objs) {
        this->rotationObj(i, a, rotaVal, speed);
    }
    this->rotationObj(this->player, a, rotaVal, speed);
}



void Engine::deplacementObj(IGameObject *obj, const EventType &a, const vec::vector3f &rotaVal, const float &speed)
{
    if (a.Z) {
        // obj->setMoove({.x = speed * rotaVal.x, .y = speed * rotaVal.y, .z = -speed * rotaVal.z});
        obj->setMoove({.x = 0, .y = 0, .z = -speed});
    } else if (a.S) {
        obj->setMoove({.x = 0, .y = 0, .z = speed});
    }
    if (a.Q) {
        obj->setMoove({.x = speed, .y = 0, .z = 0});
    } else if (a.D) {
        obj->setMoove({.x = -speed, .y = 0, .z = 0});
    }
    if (a.Space && a.LShift) {
        obj->setMoove({.x = 0, .y = -speed, .z = 0});
    } else if(a.Space) {
        obj->setMoove({.x = 0, .y = speed, .z = 0});
    }
}

void Engine::rotationObj(IGameObject *obj, const EventType &a, const vec::vector3f &rotaVal, const float &speed)
{
    obj->rotation (
        {.x = speed * rotaVal.x, .y = speed * rotaVal.y, .z = speed * rotaVal.z},
        {.x = 0.f, .y = 0.f, .z = 0.f}
    );
}

void Engine::genMap()
{
}

void Engine::addGameObject(IGameObject *go)
{
    this->objs.push_back(go);
}

