#include "Core.hpp"

Core::Core() :
window(new sfmlWindow(50, {1080, 720}, "a.out"))
{
}

Core::~Core()
{
    delete window;
}

void Core::main()
{
    IEngine *engine = new Engine(this->window);

    // for (int i = 0; i < 100; i++) {
    //     IGameObject *cube = new Cube("./../BlenderFile/CubeBlender.obj", {(250 * cos(i * 3.6)), 0, (250 * sin(i * 3.6))});
    //     engine->addGameObject(cube);

    // }

    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         IGameObject *cube = new Cube("./../BlenderFile/CubeBlender.obj", {i * 15, 0, (j + 10) * 15});
    //         engine->addGameObject(cube);
    //     }
    // }

    // IGameObject *cube = new Cube("./../BlenderFile/CubeBlender.obj", {0, -10, -40});
    // engine->addGameObject(cube);

    // IGameObject *tree1 = new Tree("./../BlenderFile/CubeBlender.obj", {0, 0, 100});
    IGameObject *tree1 = new Tree("./../BlenderFile/Lowpoly_tree_sample.obj", {0, 0, 100});
    // IGameObject *tree2 = new Tree("./../BlenderFile/Lowpoly_tree_sample.obj", {300, 0, 0});
    // IGameObject *tree3 = new Tree("./../BlenderFile/Lowpoly_tree_sample.obj", {300, 0, 300});
    // IGameObject *tree4 = new Tree("./../BlenderFile/Lowpoly_tree_sample.obj", {0, 0, 300});

    engine->addGameObject(tree1);
    // engine->addGameObject(tree2);
    // engine->addGameObject(tree3);
    // engine->addGameObject(tree4);

    while (window->isOpen()) {

        window->pollEvent();
        window->clear();

        engine->transform();
        engine->draw();

        window->display();
    }
}