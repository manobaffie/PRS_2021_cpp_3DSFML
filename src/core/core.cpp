#include "core.hpp"

core::core()
{
    LoadLib<Igraph> test("../libGraph/sfml/sfml.so");
    this->graph = test.init();
    this->graph->setWindow(25, "", {1080, 920});

    this->addtOBJ("FirstCube");
    this->start();
}

void core::addtOBJ(std::string id)
{
    std::vector<Line2D_s> a = this->rd.getObject2D(id);
    for (Line2D_s i : a) {
        this->graph->setLineShape (
            i.id,
            7,
            i.Points1,
            i.Points2
        );
    }
}

core::~core()
{
}

void core::start()
{
    this->graph->startClock("FirstCubeRotation");

    while (this->graph->isOpen()) {
        this->graph->pollEvent();
        this->graph->clear();

        if (this->graph->getClock("FirstCubeRotation") > 0.01) {
            this->rd.addRotationXAllObject(Point3D_s::Create(0, 0.1, 0, ""));
            this->addtOBJ("FirstCube");
            this->graph->restartClock("FirstCubeRotation");
        }


        this->graph->drawAllShape();
        this->graph->display();
    }
}