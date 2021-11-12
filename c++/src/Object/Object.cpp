#include "Object.hpp"

Object::Object(const std::string &id) :
Id(id)
{
}

Object::~Object()
{
}

void Object::setObject()
{
    this->Z0 = (RerolutionX / 2.0) / tan((FieldOfView / 2.0) * PI / 180.0);
    this->Center = Point2D_s::Create(0, 0);

}

void Object::setCenter(const Point2D_s &center)
{
    this->Center = center;
}

const std::string &Object::getId()
{
    return (this->Id);
}

const std::vector<Shape2D_s> Object::getObject2D()
{
    std::vector<Shape2D_s> Object2D(this->Oshape3D.size());
    size_t nbShape = 0;

    for (size_t i = 0; i < this->Oshape3D.size(); i++) {

        std::vector<Point2D_s> Shape2D = this->calcObject2D(i);

        Object2D[i].Shape2D = Shape2D;
        Object2D[i].id = this->Oshape3D[i].id;
        nbShape++;
    }
    Object2D.resize(nbShape);
    Object2D.shrink_to_fit();
    return (Object2D);
}

const std::vector<Point2D_s> Object::calcObject2D(const size_t &i)
{
    std::vector<Point2D_s> Shape2D(this->Oshape3D[i].Shape3D.size());
    size_t nbShape = 0;

    for (size_t j = 0; j < this->Oshape3D[i].Shape3D.size(); j++) {
        double x = this->Oshape3D[i].Shape3D[j].x * this->Z0 / (this->Z0 + this->Oshape3D[i].Shape3D[j].z) + this->Center.x + RerolutionX / 2.0;
        if (x < 0 || x > RerolutionX) {
            break;
        }
        double y = this->Oshape3D[i].Shape3D[j].y * this->Z0 / (this->Z0 + this->Oshape3D[i].Shape3D[j].z) + this->Center.y + RerolutionY / 2.0;
        if (y < 0 || y > RerolutionY) {
            break;
        }
        Shape2D[j] = Point2D_s::Create(
            x,
            y
        );
        nbShape++;
    }
    Shape2D.resize(nbShape);
    Shape2D.shrink_to_fit();
    return (Shape2D);
}

void Object::addOrigine(const Point3D_s &origine)
{
    for (size_t i = 0; i < this->Oshape3D.size(); i++) {
        for (size_t j = 0; j < this->Oshape3D[i].Shape3D.size(); j++) {
            this->Oshape3D[i].Shape3D[j].x += origine.x;
            this->Oshape3D[i].Shape3D[j].y += origine.y;
            this->Oshape3D[i].Shape3D[j].z += origine.z;

            this->Oshape3D[i].Shape3D[j].x += origine.x;
            this->Oshape3D[i].Shape3D[j].y += origine.y;
            this->Oshape3D[i].Shape3D[j].z += origine.z;
        }
    }
}

void Object::addRotationX(const double &speed)
{
    Point3D_s rota = Point3D_s::Create(0.0, speed, 0.0);

    for (size_t i = 0; i < this->Oshape3D.size(); i++) {
        for (size_t j = 0; j < this->Oshape3D[i].Shape3D.size(); j++) {
            this->Oshape3D[i].Shape3D[j] = calcRotationX(this->Oshape3D[i].Shape3D[j], rota);
            this->Oshape3D[i].Shape3D[j] = calcRotationX(this->Oshape3D[i].Shape3D[j], rota);
        }
    }
}

Point3D_s Object::calcRotationX(const Point3D_s &point, const Point3D_s &rota)
{
    Point3D_s output;

    output.x = (
        point.x * (std::cos(rota.z) * std::cos(rota.y)) +
        point.y * (std::cos(rota.z) * std::cos(rota.y) *
        std::sin(rota.x) - std::sin(rota.z) * std::cos(rota.x)) +
        point.z * (std::cos(rota.z) * std::sin(rota.y) *
        std::cos(rota.x) + std::sin(rota.z) * std::sin(rota.x))
    );

    output.y = (
        point.x * (std::sin(rota.z) * std::cos(rota.y)) +
        point.y * (std::sin(rota.z) * std::sin(rota.y) *
        std::sin(rota.x) + std::cos(rota.z) * std::cos(rota.x)) +
        point.z * (std::sin(rota.z) * std::sin(rota.y) *
        std::cos(rota.x) - std::cos(rota.z) * std::sin(rota.x))
    );

    output.z = (
        point.x * (-1 *std::sin(rota.y)) +
        point.y * (std::cos(rota.y) * std::sin(rota.x)) +
        point.z * (std::cos(rota.y) * std::cos(rota.x))
    );

    return (output);
}

void Object::printAllObject3D()
{
    std::cout << "[" << this->Id << "]" << std::endl;
    for (const Shape3D_s &i : this->Oshape3D) {
        std::cout << "[" << i.id << "] ";
        for (const Point3D_s &j : i.Shape3D) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}
