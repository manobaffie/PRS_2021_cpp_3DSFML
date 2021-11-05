#include "loadObject.hpp"

loadObject::loadObject()
{
}

loadObject::~loadObject()
{
}

void loadObject::addObject(object *Obj)
{
    this->allObject.insert(std::make_pair(Obj->getId(), Obj));
}

void loadObject::printAllObject()
{
    for(std::map<std::string, object *>::const_iterator it = this->allObject.begin() ; it != this->allObject.end() ; ++it) {
        it->second->printObject3D();
    }
}
