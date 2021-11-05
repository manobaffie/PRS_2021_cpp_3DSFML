#include "object.hpp"

object::object(std::string id, std::vector<Line3D_s> Points)
{
    this->Shape = Points;
}

object::~object()
{
}

std::vector<Line2D_s> object::getObjet()
{
    return (this->Shape);
}