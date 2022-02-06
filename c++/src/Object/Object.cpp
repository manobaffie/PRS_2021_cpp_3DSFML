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
    this->Z0 = (RerolutionX / 2.0) / std::tan((FieldOfView / 2.0) * PI / 180.0);
    this->Center = Point<float>(0.0, 0.0);
}

void Object::setCenter(const Point<float> &center)
{
    this->Center = center;
}

const std::string &Object::getId()
{
    return (this->Id);
}

const std::vector<std::vector<coord_s>> Object::getTextures()
{
    std::vector<std::vector<coord_s>> output(this->Textures.size());

    for (size_t i = 0; i < this->Textures.size(); i++) {
        std::vector<coord_s> tmp(this->Textures[i].size());
        for (size_t j = 0; j < this->Textures[i].size(); j++) {
            tmp[j].x = this->Textures[i][j].x;
            tmp[j].y = this->Textures[i][j].y;
        }
        output[i] = tmp;
    }
    return (output);
}

const std::vector<std::vector<coord_s>> Object::getObject2D()
{
    std::vector<std::vector<coord_s>> Object2D(this->Oshape3D.size());
    size_t nbShape = 0;

    for (size_t i = 0; i < this->Oshape3D.size(); i++) {
        Object2D[i] = this->calcObject2D(i);
        nbShape++;
    }
    Object2D.resize(nbShape);
    Object2D.shrink_to_fit();
    return (Object2D);
}

const std::vector<coord_s> Object::calcObject2D(const size_t &i)
{
    std::vector<coord_s> Shape2D(this->Oshape3D[i].size());
    size_t nbShape = 0;

    for (size_t j = 0; j < this->Oshape3D[i].size(); j++) {

        double x = this->Oshape3D[i][j].x * this->Z0 / (this->Z0 + this->Oshape3D[i][j].z) + this->Center.x + RerolutionX / 2.0;
        if (x < 0 || x > RerolutionX) {
            // break;
        }

        double y = this->Oshape3D[i][j].y * this->Z0 / (this->Z0 + this->Oshape3D[i][j].z) + this->Center.y + RerolutionY / 2.0;
        if (y < 0 || y > RerolutionY) {
            // break;
        }

        Shape2D[j].x = x;
        Shape2D[j].y = y;
        nbShape++;
    }
    Shape2D.resize(nbShape);
    Shape2D.shrink_to_fit();
    return (Shape2D);
}

void Object::addOrigine(const Point<float> &origine)
{
    for (size_t i = 0; i < this->Oshape3D.size(); i++) {
        for (size_t j = 0; j < this->Oshape3D[i].size(); j++) {
            this->Oshape3D[i][j].x += origine.x;
            this->Oshape3D[i][j].y += origine.y;
            this->Oshape3D[i][j].z += origine.z;
        }
    }
}

void Object::addRotationX(const double &speed)
{
    Point<float> rota = Point<float>(0.0, speed);

    for (size_t i = 0; i < this->Oshape3D.size(); i++) {
        for (size_t j = 0; j < this->Oshape3D[i].size(); j++) {
            this->Oshape3D[i][j] = calcRotationX(this->Oshape3D[i][j], rota);
        }
    }
}

Point<float> Object::calcRotationX(const Point<float> &point, const Point<float> &rota)
{
    float x = (
        point.x * (std::cos(rota.z) * std::cos(rota.y)) +
        point.y * (std::cos(rota.z) * std::cos(rota.y) *
        std::sin(rota.x) - std::sin(rota.z) * std::cos(rota.x)) +
        point.z * (std::cos(rota.z) * std::sin(rota.y) *
        std::cos(rota.x) + std::sin(rota.z) * std::sin(rota.x))
    );

    float y = (
        point.x * (std::sin(rota.z) * std::cos(rota.y)) +
        point.y * (std::sin(rota.z) * std::sin(rota.y) *
        std::sin(rota.x) + std::cos(rota.z) * std::cos(rota.x)) +
        point.z * (std::sin(rota.z) * std::sin(rota.y) *
        std::cos(rota.x) - std::cos(rota.z) * std::sin(rota.x))
    );

    float z = (
        point.x * (-1 *std::sin(rota.y)) +
        point.y * (std::cos(rota.y) * std::sin(rota.x)) +
        point.z * (std::cos(rota.y) * std::cos(rota.x))
    );

    return (Point<float>(x, y, z));
}

void Object::printAllObject3D()
{
    std::cout << "[" << this->Id << "]" << std::endl;
    for (const std::vector<Point<float>> &i : this->Oshape3D) {
        for (const Point<float> &j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}
