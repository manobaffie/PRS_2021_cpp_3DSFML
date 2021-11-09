#include "render3D.hpp"

render3D::render3D()
{
    Cube *c = new Cube("FirstCube", Point3D_s::Create(300, 300, 300, "O"), 300);

    this->lo.addObject(c);

    this->lo.printAllObject();
    std::cout << "create perspective" << std::endl;
}

render3D::~render3D()
{
}

std::vector<Line2D_s> render3D::getObject2D(std::string id)
{
    return (this->lo.getObject2D(id));
}

void render3D::addRotationXAllObject(Point3D_s rota)
{
    this->lo.addRotationXAllObject(rota);
}

void render3D::addPerspectiveAllObject()
{
    this->lo.addPerspectiveAllObject();
}
