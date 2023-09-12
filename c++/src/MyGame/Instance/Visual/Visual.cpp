#include "Visual.hpp"

MyGame::Instance::Visual::Visual():
    Game::Instance::Visual(std::make_unique<Sfml::Window>())
{
    Game::Instance::Entity entity = Game::Instance::Entity();

    this->enties.push_back(entity.get());

    std::this_thread::sleep_for(std::chrono::seconds(1));

    entity.start();

    this->start();

    this->thread.join();

    entity.stop();
    entity.thread.join();
}

MyGame::Instance::Visual::~Visual()
{
}

