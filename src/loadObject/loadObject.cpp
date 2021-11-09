#include "loadObject.hpp"

loadObject::loadObject()
{
}

loadObject::~loadObject()
{
}

void loadObject::addObject(Object *Obj)
{
    this->allObject.insert(std::make_pair(Obj->getId(), Obj));
}

void loadObject::printAllObject()
{
    for(std::map<std::string, Object *>::const_iterator it = this->allObject.begin() ; it != this->allObject.end() ; ++it) {
        it->second->printAllObject3D();
    }
}

std::vector<Line2D_s> loadObject::getObject2D(std::string id)
{
    return (this->allObject[id]->getObject2D());
}

void loadObject::addRotationXAllObject(Point3D_s rota)
{
    for(std::map<std::string, Object *>::const_iterator it = this->allObject.begin() ; it != this->allObject.end() ; ++it) {
        it->second->addRotationX(rota);
    }
}

void loadObject::addPerspectiveAllObject()
{
    for(std::map<std::string, Object *>::const_iterator it = this->allObject.begin() ; it != this->allObject.end() ; ++it) {
        it->second->getPerspective();
    }
}