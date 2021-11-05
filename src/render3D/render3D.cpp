#include "render3D.hpp"

render3D::render3D()
{
    cube *c = new cube("FirstCube", Point3D_s::Create(300, 300, 300, "O"), 300);
    cube *c1 = new cube("FirstCube1", Point3D_s::Create(600, 600, 600, "O"), 300);
    cube *c2 = new cube("FirstCube2", Point3D_s::Create(600, 300, 300, "O"), 100);
    cube *c3 = new cube("FirstCube3", Point3D_s::Create(300, 600, 300, "O"), 50);
    cube *c4 = new cube("FirstCube4", Point3D_s::Create(800, 800, 300, "O"), 300);
    cube *c5 = new cube("FirstCube5", Point3D_s::Create(100, 100, 100, "O"), 300);

    this->lo.addObject(c);
    this->lo.addObject(c1);
    this->lo.addObject(c2);
    this->lo.addObject(c3);
    this->lo.addObject(c4);
    this->lo.addObject(c5);

    this->lo.printAllObject();
    std::cout << "create perspective" << std::endl;

    this->lo.printAllPerspectiveObject3D();
}

render3D::~render3D()
{
}

std::vector<Line2D_s> render3D::getObject2D(std::string id)
{
    return (this->lo.getObject2D(id));
}