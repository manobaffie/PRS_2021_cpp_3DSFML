#include "Cube.hpp"

Cube::Cube(const std::string &id, const size_t &size) :
Object(id), Size(size)
{
    this->setPoint3D();

    this->setLine3D("A", "B");
    this->setLine3D("B", "C");
    this->setLine3D("C", "D");
    this->setLine3D("D", "A");

    this->setLine3D("E", "F");
    this->setLine3D("F", "G");
    this->setLine3D("G", "H");
    this->setLine3D("H", "E");

    this->setLine3D("A", "E");
    this->setLine3D("B", "F");
    this->setLine3D("C", "G");
    this->setLine3D("D", "H");

    this->setObject();
}

Cube::~Cube()
{
    
}

void Cube::setPoint3D()
{
    this->cubePoint.push_back(Point3D_s::Create(-1 * double(this->Size / 2), -1 * double(this->Size / 2), -1 * (double(this->Size / 2)), "A"));
    this->cubePoint.push_back(Point3D_s::Create(double(this->Size / 2), -1 * double(this->Size / 2), -1 * double(this->Size / 2), "B"));
    this->cubePoint.push_back(Point3D_s::Create(double(this->Size / 2), -1 * double(this->Size / 2), double(this->Size / 2), "C"));
    this->cubePoint.push_back(Point3D_s::Create(-1 * double(this->Size / 2), -1 * double(this->Size / 2), double(this->Size / 2), "D"));

    this->cubePoint.push_back(Point3D_s::Create(-1 * double(this->Size / 2), double(this->Size / 2), -1 * (double(this->Size / 2)), "E"));
    this->cubePoint.push_back(Point3D_s::Create(double(this->Size / 2), double(this->Size / 2), -1 * double(this->Size / 2), "F"));
    this->cubePoint.push_back(Point3D_s::Create(double(this->Size / 2), double(this->Size / 2), double(this->Size / 2), "G"));
    this->cubePoint.push_back(Point3D_s::Create(-1 * double(this->Size / 2), double(this->Size / 2), double(this->Size / 2), "H"));
}

void Cube::setLine3D(std::string Point1, std::string Point2)
{
    Line3D_s LineTmp;

    for (const Point3D_s &i : this->cubePoint) {
        if (i.id == Point1) {
            LineTmp.Points1 = Point3D_s::Create(i.x, i.y, i.z, i.id);
        }
        if (i.id == Point2) {
            LineTmp.Points2 = Point3D_s::Create(i.x, i.y, i.z, i.id);
        }
    }

    this->Oshape3D.push_back (
        Line3D_s::Create (
            Point3D_s::Create(LineTmp.Points1.x, LineTmp.Points1.y, LineTmp.Points1.z, LineTmp.Points1.id),
            Point3D_s::Create(LineTmp.Points2.x, LineTmp.Points2.y, LineTmp.Points2.z, LineTmp.Points2.id),
            Point1 + Point2
        )
    );

    this->Shape3D.push_back (
        Line3D_s::Create (
            Point3D_s::Create(LineTmp.Points1.x, LineTmp.Points1.y, LineTmp.Points1.z, LineTmp.Points1.id),
            Point3D_s::Create(LineTmp.Points2.x, LineTmp.Points2.y, LineTmp.Points2.z, LineTmp.Points2.id),
            Point1 + Point2
        )
    );
}
