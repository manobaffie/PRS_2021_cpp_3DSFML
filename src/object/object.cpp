#include "object.hpp"

object::object(std::string id, std::vector<Line3D_s> Points) :
Id(id), Shape(Points)
{
    Z0 = (RerolutionX / 2.0)
}

object::~object()
{
}

std::string object::getId()
{
    return (this->Id);
}

std::vector<Line2D_s> object::getObject2D()
{
    // return ();
}

void object::makePerspective()
{

}

void object::printObject2D()
{

}

void object::printObject3D()
{
    std::cout << "[" << this->Id << "]" << std::endl;
    for (Line3D_s i : this->Shape) {
        std::cout << i << std::endl;
    }    
}
