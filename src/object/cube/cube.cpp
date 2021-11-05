#include "cube.hpp"

cube::cube(std::string id, Point3D_s origine, size_t size) :
object(id, this->getCubePoints(id, origine, size))
{
}

cube::~cube()
{
}

std::vector<Line3D_s> cube::getCubePoints(std::string id, Point3D_s origine, size_t size)
{
    this->Id = id;
    this->Origine = new Point3D_s(Point3D_s::Create(origine.x, origine.y, origine.z, origine.id));
    this->Size = size;

    this->setPresetLine3D();
    this->setLine3D();

    return (this->cubePoints);
}

void cube::setLine3D()
{
    this->setLine3DFace(0, 4, 1, 0);
    this->setLine3DFace(4, 8, 1, 3);
    this->setLine3DFace(0, 4, 4, 7);
}

void cube::setLine3DFace(int range0, int range1, int add, int init)
{
    for (size_t i = range0; i < range1; i++) {
        size_t j = i + 1;

        if (j > range1 - 1) j = init;

        this->cubePoints.push_back(
            Line3D_s::Create (
                this->Id + "_" + cubePreset[i].id + cubePreset[j].id,
                this->Size,
                Point3D_s::Create (
                    Origine->x + cubePreset[i].x * this->Size,
                    Origine->y  + cubePreset[i].y * this->Size, 
                    Origine->z  + cubePreset[i].z * this->Size,
                    cubePreset[i].id
                ),
                Point3D_s::Create (
                    Origine->x + cubePreset[j].x * this->Size,
                    Origine->y  + cubePreset[j].y * this->Size,
                    Origine->z  + cubePreset[j].z * this->Size,
                    cubePreset[j].id
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