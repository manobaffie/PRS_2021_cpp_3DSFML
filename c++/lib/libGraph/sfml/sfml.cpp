#include "sfml.hpp"

/* ----- Entity ----- */

sfmlEntity::sfmlEntity(std::vector<vec::vpvector2f> &vertices, const vec::vector4i &color)
{
    for (size_t i = 0; i < vertices.size(); i++) {
        sf::VertexArray Shape;

        Shape.setPrimitiveType(sf::TriangleFan);
        Shape.resize(vertices[i].size());

        for (size_t j = 0; j < vertices[i].size(); j++) {
            Shape[j].position.x = *vertices[i][j].x;
            Shape[j].position.y = *vertices[i][j].y;

            Shape[j].color.r = color.w;
            Shape[j].color.g = color.x;
            Shape[j].color.b = color.y;
            Shape[j].color.a = color.z;
        }

        this->vertices.push_back(Shape);
    }
    this->linkVertices(vertices);
}

sfmlEntity::~sfmlEntity()
{
    
}

void sfmlEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &this->texture;
    for (sf::VertexArray i : this->vertices)
        target.draw(i, states);
}

void sfmlEntity::linkVertices(std::vector<vec::vpvector2f> &vpvertices)
{
    for (size_t i = 0; i < this->vertices.size(); i++) {
        for (size_t j = 0; j < this->vertices[i].getVertexCount(); j++) {
            *(&vpvertices[i][j].x) = &this->vertices[i][j].position.x;
            *(&vpvertices[i][j].y) = &this->vertices[i][j].position.y;
        }
    }
}

/* ----- sfml ----- */

sfmlWindow::sfmlWindow(const int fps, const vec::vector2i &sizeWin, const std::string &name) :
window(sf::VideoMode(sizeWin.x, sizeWin.y), name)
{
    this->window.setFramerateLimit(fps);
}

sfmlWindow::~sfmlWindow()
{
}

void sfmlWindow::draw(Entity *entity)
{
    this->window.draw(*dynamic_cast<sfmlEntity *>(entity));
}

void sfmlWindow::clear()
{
    this->window.clear();
}

void sfmlWindow::display()
{
    this->window.display();
}

bool sfmlWindow::isOpen()
{
    return (this->window.isOpen());
}

vec::vector2i sfmlWindow::getSize()
{
    sf::Vector2u size = this->window.getSize();
    return (vec::vector2i({.x = int(size.x), .y = int(size.y)}));
}

void sfmlWindow::pollEvent()
{
    while (this->window.pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window.close();
                break;
            default:
                break;
        }
    }
}
