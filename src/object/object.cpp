#include "object.hpp"

object::object()
{
}

object::~object()
{
}

void object::setObject(std::string id, std::vector<Line3D_s> Points)
{
    this->objectId = id;
    this->Shape3D = Points;

    this->Z0 = (RerolutionX / 2.0) / tan((FieldOfView / 2.0) * PI / 180.0);
    this->makePerspective();
    this->makeObject2D();
}

std::string object::getId()
{
    return (this->objectId);
}

std::vector<Line2D_s> object::getObject2D()
{
    return (this->Shape2D);
}

void object::makeObject2D()
{
    for (Line3D_s i : this->Shape3DPerspective) {
        this->Shape2D.push_back(Line2D_s::Create (
            i.id,

            i.size,

            Point2D_s::Create(
                i.Points1.x,
                i.Points1.y
            ),

            Point2D_s::Create(
                i.Points2.x,
                i.Points2.y
            )
        ));
    }
}

void object::makePerspective()
{
    for (Line3D_s i : this->Shape3D) {
        this->Shape3DPerspective.push_back(Line3D_s::Create (
            "Perspective_" + i.id,

            i.size,

            Point3D_s::Create(
                i.Points1.x * this->Z0 / (this->Z0 + i.Points1.z),
                i.Points1.y * this->Z0 / (this->Z0 + i.Points1.z),
                i.Points1.z,
                "Perspective_" + i.Points1.id
            ),

            Point3D_s::Create(
                i.Points2.x * this->Z0 / (this->Z0 + i.Points2.z),
                i.Points2.y * this->Z0 / (this->Z0 + i.Points2.z),
                i.Points2.z,
                "Perspective_" + i.Points2.id
            )
        ));
    }
}

void object::printObject2D()
{

}

void object::printAllObject3D()
{
    std::cout << "[" << this->objectId << "]" << std::endl;
    for (Line3D_s i : this->Shape3D) {
        std::cout << i << std::endl;
    }
}

void object::printAllPerspectiveObject3D()
{
    std::cout << "[" << this->objectId << "]" << std::endl;
    for (Line3D_s i : this->Shape3DPerspective) {
        std::cout << i << std::endl;
    }
}
