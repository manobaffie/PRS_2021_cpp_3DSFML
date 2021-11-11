#include "Object.hpp"

// replace all push_back by hard coded size

Object::Object(const std::string &id) :
Id(id)
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

void Object::setCenter(const Point2D_s &center)
{
    this->Center = center;
}

const std::string &Object::getId()
{
    return (this->Id);
}

const std::vector<Line2D_s> Object::getObject2D()
{
    std::vector<Line2D_s> output;

    this->getPerspective();

    for (const Line3D_s &i : this->Shape3D) {
        output.push_back(Line2D_s::Create (
            Point2D_s::Create(
                i.Points1.x + this->Center.x + RerolutionX / 2.0,
                i.Points1.y + this->Center.y + RerolutionY / 2.0
            ),
            Point2D_s::Create(
                i.Points2.x + this->Center.x + RerolutionX / 2.0,
                i.Points2.y + this->Center.y + RerolutionY / 2.0
            ),
            i.id,
            6
        ));
    }

    return (output);
}

void Object::getPerspective()
{
    for (size_t i = 0; i < this->Oshape3D.size(); i++) {
        this->Shape3D[i] = Line3D_s::Create (
            Point3D_s::Create (
                this->Oshape3D[i].Points1.x * this->Z0 / (this->Z0 + this->Oshape3D[i].Points1.z),
                this->Oshape3D[i].Points1.y * this->Z0 / (this->Z0 + this->Oshape3D[i].Points1.z),
                this->Oshape3D[i].Points1.z,
                this->Oshape3D[i].Points1.id
            ),
            Point3D_s::Create (
                this->Oshape3D[i].Points2.x * this->Z0 / (this->Z0 + this->Oshape3D[i].Points2.z),
                this->Oshape3D[i].Points2.y * this->Z0 / (this->Z0 + this->Oshape3D[i].Points2.z),
                this->Oshape3D[i].Points2.z,
                this->Oshape3D[i].Points2.id
            ),
            this->Id + this->Oshape3D[i].id
        );
    }
}

void Object::addOrigine(const Point3D_s &origine)
{
    for (size_t i = 0; i < this->Oshape3D.size(); i++) {
        this->Oshape3D[i].Points1.x += origine.x;
        this->Oshape3D[i].Points1.y += origine.y;
        this->Oshape3D[i].Points1.z += origine.z;

        this->Oshape3D[i].Points2.x += origine.x;
        this->Oshape3D[i].Points2.y += origine.y;
        this->Oshape3D[i].Points2.z += origine.z;
    }
}

void Object::addRotationX(const double &speed)
{
    Point3D_s rota = Point3D_s::Create(0.0, speed, 0.0);

    for (size_t i = 0; i < this->Oshape3D.size(); i++) {
        this->Oshape3D[i].Points1 = calcRotationX(this->Oshape3D[i].Points1, rota);
        this->Oshape3D[i].Points2 = calcRotationX(this->Oshape3D[i].Points2, rota);
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
