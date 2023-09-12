#include "Entity.hpp"

Game::Instance::Entity::Entity():
    Base(std::chrono::microseconds(1))
{
    this->entity = new Sfml::Entity(this->buildEntity());
}

Game::Instance::Entity::~Entity()
{
    // delete entity
}

Graph::Entity &Game::Instance::Entity::get()
{
    return static_cast<Graph::Entity &>(*this->entity);
}

void Game::Instance::Entity::main()
{
    Graph::Vector2f &test1 = (*this->entity)[0][2].getPosition();

    test1.setX(test1.getX() + 0.001f);
}

std::vector<std::vector<vec::vector2D<float>>> Game::Instance::Entity::buildEntity()
{
    return {
        {
            {.x = 10, .y = 10},
            {.x = 10, .y = 100},
            {.x = 100, .y = 100},
            {.x = 100, .y = 10}
        },
        {
            {.x = 50, .y = 50},
            {.x = 50, .y = 500},
            {.x = 500, .y = 500},
            {.x = 500, .y = 50}
        }
    };
}
