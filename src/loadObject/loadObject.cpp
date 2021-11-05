#include "loadObject.hpp"

loadObject::loadObject()
{
}

loadObject::~loadObject()
{
}

void loadObject::addObject(std::string id, object *Obj)
{
    this->allObject.insert(std::make_pair(id, Obj));
}