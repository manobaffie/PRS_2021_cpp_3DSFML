#include "cube.hpp"

cube::cube(std::string id, Point3D_s origine, size_t size) :
cubeId(id), Size(size)
{
    // this->Origine = new Point3D_s(Point3D_s::Create(origine.x, origine.y, origine.z, origine.id));
    this->Origine = Point3D_s::Create(origine.x, origine.y, origine.z, origine.id);

    this->setPresetLine3D();
    this->setLine3D();

    this->setObject(id, this->getCubePoints(), this->Origine);
}

cube::~cube()
{
}

std::vector<Line3D_s> cube::getCubePoints()
{
    return (this->cubePoints);
}

void cube::setLine3D()
{
    this->setLine3DFace(0, 4, 1, 0, 3);
    this->setLine3DFace(4, 8, 1, 4, 7);
    this->setLine3DFace(0, 4, 4, 7, 7);
}

void cube::setLine3DFace(int range0, int range1, int add, int init, int limit)
{
    for (size_t i = range0; i < range1; i++) {
        size_t j = (i + add > limit) ? init : i + add;

        this->cubePoints.push_back(
            Line3D_s::Create (
                this->cubeId + "_" + this->cubePreset[i].id + this->cubePreset[j].id,
                this->Size,
                Point3D_s::Create (
                    this->cubePreset[i].x * this->Size,
                    this->cubePreset[i].y * this->Size, 
                    this->cubePreset[i].z * this->Size,
                    this->cubePreset[i].id
                ),
                Point3D_s::Create (
                    this->cubePreset[j].x * this->Size,
                    this->cubePreset[j].y * this->Size,
                    this->cubePreset[j].z * this->Size,
                    this->cubePreset[j].id
                )
            )
        );
    }
}

void cube::setPresetLine3D()
{
    this->cubePreset = {
        Point3D_s::Create(0, 0, 0, "A"),
        Point3D_s::Create(1, 0, 0, "B"),
        Point3D_s::Create(1, 0, 1, "C"),
        Point3D_s::Create(0, 0, 1, "D"),

        Point3D_s::Create(0, 1, 0, "E"),
        Point3D_s::Create(1, 1, 0, "F"),
        Point3D_s::Create(1, 1, 1, "G"),
        Point3D_s::Create(0, 1, 1, "H"),
    };
}

void cube::printCube()
{
}