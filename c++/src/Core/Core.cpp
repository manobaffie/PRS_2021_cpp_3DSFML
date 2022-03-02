#include "Core.hpp"

Core::Core() :
window(new sfmlWindow(30, {1080, 720}, "a.out"))
{
}

Core::~Core()
{
    delete window;
}

void Core::main()
{
    IEngine *engine = new Engine(this->window);

    while (window->isOpen()) {

        window->pollEvent();
        window->clear();

        engine->draw();

        window->display();

    }
}