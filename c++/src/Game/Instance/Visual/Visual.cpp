#include "Visual.hpp"

Game::Instance::Visual::Visual(std::unique_ptr<Graph::Window> window):
    _window(std::move(window)),
    Base()
{
}

Game::Instance::Visual::~Visual()
{
}

void Game::Instance::Visual::main()
{
    _window->pollEvent();
    _window->clear();
    this->draw();
    _window->display();
}

bool Game::Instance::Visual::isRunning()
{
    return _window->isOpen();
}

void Game::Instance::Visual::draw()
{
    for(std::reference_wrapper<Graph::Entity> i : this->enties) {
        _window->draw(i.get());
    }
}

void Game::Instance::Visual::frequency()
{
}
