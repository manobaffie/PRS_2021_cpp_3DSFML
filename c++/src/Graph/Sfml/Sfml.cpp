#include "Sfml.hpp"

/* ----- SfmlVector2f ----- */

// Sfml::Vector2f::Vector2f(vec::vector2D<float> vertex):
//     sf::Vector2f(vertex.x, vertex.y)
// {
//     std::cout << "Sfml::Vector2f::Vector2f" << std::endl;
// }

// Sfml::Vector2f::Vector2f(sf::Vector2f &vertex):
//     sf::Vector2f(vertex)
// {
//     std::cout << "Sfml::Vector2f::Vector2f" << std::endl;    
// }

// float Sfml::Vector2f::getX()
// {
//     return this->x;
// }

// void Sfml::Vector2f::setX(float x)
// {
//     this->x = x;
// }

// float Sfml::Vector2f::getY()
// {
//     return this->y;
// }

// void Sfml::Vector2f::setY(float y)
// {
//     this->y = y;
// }

/* ----- SfmlVertex ----- */

// Sfml::Vertex::Vertex(vec::vector2D<float> vertex):
//     Vector2f(vertex)
// {
//     std::cout << "Sfml::Vertex::Vertex" << std::endl;
// }

Sfml::Vertex::Vertex(sf::Vertex &vertex):
    _vertex(vertex)
{
    this->_vertex.color = sf::Color(192, 0, 0, 200);
}

Graph::Vector2f &Sfml::Vertex::getPosition()
{
    return (*this);
}

float Sfml::Vertex::getX()
{
    return this->_vertex.position.x;
}

void Sfml::Vertex::setX(float x)
{
    this->_vertex.position.x = x;
}

float Sfml::Vertex::getY()
{
    return this->_vertex.position.y;
}

void Sfml::Vertex::setY(float y)
{
    this->_vertex.position.y = y;
}

/* ----- SfmlVertices ----- */

Sfml::Vertices::Vertices(std::vector<vec::vector2D<float>> vertices):
    _vertexArray(sf::TriangleFan, vertices.size())
{
    for (size_t j = 0; j < vertices.size(); ++j) {
        this->_vertexArray[j].position.x = vertices[j].x;
        this->_vertexArray[j].position.y = vertices[j].y;
        (*this).push_back(Vertex(this->_vertexArray[j]));
    }
}

Graph::Vertex &Sfml::Vertices::getVertex(int index)
{
    return static_cast<Sfml::Vertex &>((*this)[index]);
}

/* ----- SfmlEntity ----- */

Sfml::Entity::Entity(std::vector<std::vector<vec::vector2D<float>>> entity):
    std::vector<Vertices>(entity.size())
{
    for (size_t i = 0; i < entity.size(); ++i) {
        (*this)[i] = Vertices(entity[i]);
    }
}

Sfml::Entity::~Entity()
{
}

void Sfml::Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (Vertices &vertices: static_cast<std::vector<Vertices>>(*this)) {
        target.draw(vertices._vertexArray, states);
    }
}

Graph::Vertices &Sfml::Entity::getVertices(int index)
{
    return static_cast<Graph::Vertices &>((*this)[index]);
};

/* ----- SfmlWindow ----- */

Sfml::Window::Window(Sfml::Settings settings):
    _settings(settings),
    _window(sf::VideoMode(settings.sizeWin.x, settings.sizeWin.y), settings.name)
{
    this->_window.setFramerateLimit(settings.fps);
}

Sfml::Window::~Window()
{
    this->_window.close();
}

void Sfml::Window::draw(Graph::Entity &entity)
{
    Sfml::Entity *sfmlEntity = dynamic_cast<Sfml::Entity *>(&entity);

    if (sfmlEntity) {
        this->_window.draw(*sfmlEntity, sf::RenderStates::Default);
    } else {
        throw std::bad_cast();
    }
}

void Sfml::Window::pollEvent()
{
    while (this->_window.pollEvent(this->_event)) {
        switch (this->_event.type) {
            case (sf::Event::Closed):
                this->_window.close();
                break;
            default:
                break;
        }
    }
}

bool Sfml::Window::isOpen()
{
    return (this->_window.isOpen());
}

void Sfml::Window::clear()
{
    this->_window.clear();
}

void Sfml::Window::display()
{
    this->_window.display();
}
