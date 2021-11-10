#include "Object.hpp"

Object::Object(const std::string &id, const Point3D_s &origine) :
Id(id), Origine(origine)
{
    this->setObject();
}

Object::~Object()
{
}

void Object::setObject()
{
    this->Z0 = (RerolutionX / 2.0) / tan((FieldOfView / 2.0) * PI / 180.0);
}

const std::string &Object::getId()
{
    return (this->Id);
}

const std::vector<Line2D_s> Object::getObject2D()
{
    std::vector<Line2D_s> output;

    for (const Line3D_s &i : this->getPerspective()) {
        output.push_back(Line2D_s::Create (
            Point2D_s::Create(
                i.Points1.x + this->Origine.x,
                i.Points1.y + this->Origine.y
            ),
            Point2D_s::Create(
                i.Points2.x + this->Origine.x,
                i.Points2.y + this->Origine.y
            ),
            i.id,
            7
        ));
    }

    return (output);
}

const std::vector<Line3D_s> Object::getPerspective()
{
    std::vector<Line3D_s> output;

    for (size_t i = 0; i < this->Shape3D.size(); i++) {
        output.push_back (
            Line3D_s::Create (
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
                ),
                this->Shape3D[i].id
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

void Object::addRotationX(const double &speed)
{
    Point3D_s rota = Point3D_s::Create(0.0, speed, 0.0);

    for (size_t i = 0; i < this->Shape3D.size(); i++) {
        this->Shape3D[i].Points1 = calcRotationX(this->Shape3D[i].Points1, rota);
        this->Shape3D[i].Points2 = calcRotationX(this->Shape3D[i].Points2, rota);
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
    for (Line3D_s i : this->Shape3D) {
        std::cout << i << std::endl;
    }
}
