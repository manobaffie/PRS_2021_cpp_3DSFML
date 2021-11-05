#include "cube.hpp"

cube::cube(std::string id, Point3D_s Origine, size_t size)
{
    std::vector<Line3D_s> cubePoints;
    std::vector<Line3D_s> cubePreset = {
        Line3D_s::Create("_f0", size, Point3D_s::Create(0, 0, 0), Point3D_s::Create(1, 0, 0)),
        Line3D_s::Create("_f1", size, Point3D_s::Create(1, 0, 0), Point3D_s::Create(1, 0, -1)),
        Line3D_s::Create("_f1", size, Point3D_s::Create(1, 0, -1), Point3D_s::Create(0, 0, -1)),
        Line3D_s::Create("_f1", size, Point3D_s::Create(0, 0, -1), Point3D_s::Create(0, 0, 0)),

        Line3D_s::Create("_f0", size, Point3D_s::Create(0, -1, 0), Point3D_s::Create(1, -1, 0)),
        Line3D_s::Create("_f1", size, Point3D_s::Create(1, -1, 0), Point3D_s::Create(1, -1, -1)),
        Line3D_s::Create("_f1", size, Point3D_s::Create(1, -1, -1), Point3D_s::Create(0, -1, -1)),
        Line3D_s::Create("_f1", size, Point3D_s::Create(0, -1, -1), Point3D_s::Create(0, -1, 0)),
    };

    for (size_t i = 0; i < 4; i++) {
        cubePoints.push_back(
            Line3D_s::Create(
                id + cubePreset[i].id,
                size = cubePreset[i].size,
                Point3D_s::Create(Origine.x, Origine.y, Origine.z),
                Point3D_s::Create(Origine.x + size, Origine.y, Origine.z)
            )
        );
    }

/*
    cubePoints.push_back(Point3D_s::Create(Origine.x, Origine.y, Origine.z));
    cubePoints.push_back(Point3D_s::Create(Origine.x + size, Origine.y, Origine.z));
    cubePoints.push_back(Point3D_s::Create(Origine.x + size, Origine.y, Origine.z - size));
    cubePoints.push_back(Point3D_s::Create(Origine.x, Origine.y, Origine.z - size));

    cubePoints.push_back(Point3D_s::Create(Origine.x, Origine.y - size, Origine.z));
    cubePoints.push_back(Point3D_s::Create(Origine.x + size, Origine.y - size, Origine.z));
    cubePoints.push_back(Point3D_s::Create(Origine.x + size, Origine.y - size, Origine.z - size));
    cubePoints.push_back(Point3D_s::Create(Origine.x, Origine.y - size, Origine.z - size));
*/
    object(id, cubePoints);
}

cube::~cube()
{
}
