#include "Object.hpp"

Object::Object(std::string id, Point3D_s origine) :
Id(id), Origine(origine)
{
}

Object::~Object()
{
}

void Object::setObject()
{
    this->Z0 = (RerolutionX / 2.0) / tan((FieldOfView / 2.0) * PI / 180.0);

    // this->addOrigine();
}

std::string Object::getId()
{
    return (this->Id);
}

std::vector<Line2D_s> Object::getObject2D()
{
    std::vector<Line2D_s> output;
    for (Line3D_s i : this->getPerspective()) {
        output.push_back(Line2D_s::Create (
            i.id,
            i.size,
            Point2D_s::Create(
                i.Points1.x + 500,
                i.Points1.y + 500
            ),

            Point2D_s::Create(
                i.Points2.x + 500,
                i.Points2.y + 500
            )
        ));
    }

    return (output);
}

std::vector<Line3D_s> Object::getPerspective()
{
    std::vector<Line3D_s> output;

    for (size_t i = 0; i < this->Shape3D.size(); i++) {
        output.push_back (
            Line3D_s::Create (
                this->Shape3D[i].id,
                0,
                Point3D_s::Create (
                    this->Shape3D[i].Points1.x * this->Z0 / (this->Z0 + this->Shape3D[i].Points1.z),
                    this->Shape3D[i].Points1.y * this->Z0 / (this->Z0 + this->Shape3D[i].Points1.z),
                    this->Shape3D[i].Points1.z,
                    "Perspective_" + this->Shape3D[i].Points1.id
                ),
                Point3D_s::Create (
                    this->Shape3D[i].Points2.x * this->Z0 / (this->Z0 + this->Shape3D[i].Points2.z),
                    this->Shape3D[i].Points2.y * this->Z0 / (this->Z0 + this->Shape3D[i].Points2.z),
                    this->Shape3D[i].Points2.z,
                    "Perspective_" + this->Shape3D[i].Points2.id
                )
            )
        );
    }
    return (output);
}

void Object::addOrigine()
{
    for (size_t i = 0; i < this->Shape3D.size(); i++) {
        this->Shape3D[i].Points1 = Point3D_s::Create (
            this->Shape3D[i].Points1.x + this->Origine.x,
            this->Shape3D[i].Points1.y + this->Origine.y,
            this->Shape3D[i].Points1.z + this->Origine.z,
            this->Shape3D[i].Points1.id
        );
        this->Shape3D[i].Points2 = Point3D_s::Create (
            this->Shape3D[i].Points2.x + this->Origine.x,
            this->Shape3D[i].Points2.y + this->Origine.y,
            this->Shape3D[i].Points2.z + this->Origine.z,
            this->Shape3D[i].Points2.id
        );
    }
}

void Object::addRotationX(Point3D_s rota)
{
    for (size_t i = 0; i < this->Shape3D.size(); i++) {
        this->Shape3D[i].Points1 = calcRotation(this->Shape3D[i].Points1, rota);
        this->Shape3D[i].Points2 = calcRotation(this->Shape3D[i].Points2, rota);
    }
}

Point3D_s Object::calcRotation(Point3D_s point, Point3D_s rota)
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
    for (Line3D_s i : this->Shape3D) {
        std::cout << i << std::endl;
    }
}
