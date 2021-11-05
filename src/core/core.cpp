#include "core.hpp"

core::core()
{
    LoadLib<Igraph> test("../libGraph/sfml/sfml.so");
    this->graph = test.init();
    this->graph->setWindow(5, "", {1080, 920});

    this->addtOBJ("FirstCube");
    // this->addtOBJ("FirstCube1");
    // this->addtOBJ("FirstCube2");
    // this->addtOBJ("FirstCube3");
    // this->addtOBJ("FirstCube4");
    // this->addtOBJ("FirstCube5");

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
    while (this->graph->isOpen()) {
        this->graph->pollEvent();
        this->graph->clear();
        this->graph->drawAllShape();
        this->graph->display();
    }
}