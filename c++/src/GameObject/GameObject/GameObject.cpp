#include "GameObject.hpp"

GameObject::GameObject(const std::string &path, const vec::vector3f origine)
{
    this->obj = new Blender(path, origine);
    this->entity = new sfmlEntity(*this->obj->getVertices2d(), {100, 10, 10, 100});
}

GameObject::~GameObject()
{
}

void GameObject::setPosition(const vec::vector3f &pos)
{
    this->position = pos;
}

const vec::vector3f GameObject::getPosition()
{
    return (this->position);
}

void GameObject::setMoove(const vec::vector3f &Moove)
{
    this->obj->setMoove(Moove);
}

void GameObject::rotation(const vec::vector3f &angl, vec::vector3f origine)
{
    this->obj->rotation(angl, origine);
}

Entity *GameObject::getEntity() 
{
    return (this->entity);
}

Object *GameObject::getObject() 
{
    return (this->obj);
}
