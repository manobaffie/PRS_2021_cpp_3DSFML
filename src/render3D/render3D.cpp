#include "render3D.hpp"

render3D::render3D()
{

    loadObject lo;

    cube *c = new cube("FirstCube", Point3D_s::Create(100, 100, 100, "O"), 50);


    lo.addObject(c);

    lo.printAllObject();
}

render3D::~render3D()
{
}
