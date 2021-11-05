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
        it->second->printAllObject3D();
    }
}

void loadObject::printAllPerspectiveObject3D()
{
    for(std::map<std::string, object *>::const_iterator it = this->allObject.begin() ; it != this->allObject.end() ; ++it) {
        it->second->printAllPerspectiveObject3D();
    }
}

std::vector<Line2D_s> loadObject::getObject2D(std::string id)
{
    return (this->allObject[id]->getObject2D());
}
