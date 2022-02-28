#include "sfml.hpp"

/* ----- Entity ----- */

sfmlEntity::sfmlEntity(const vec::vvector2f &vertices, const vec::vector4i &color)
{
    this->vertices.setPrimitiveType(sf::TriangleFan);

    this->vertices.resize(vertices.size());

    for (size_t i = 0; i < vertices.size(); i++) {
        this->vertices[i].position.x = vertices[i].x;
        this->vertices[i].position.y = vertices[i].y;

        this->vertices[i].color.r = color.w;
        this->vertices[i].color.g = color.x;
        this->vertices[i].color.b = color.y;
        this->vertices[i].color.a = color.z;
    }
}

sfmlEntity::~sfmlEntity()
{
    
}

void sfmlEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &this->texture;
    target.draw(this->vertices, states);
}

void sfmlEntity::loadVertices(vec::vpvector2f &vpvertices)
{
    for (size_t i = 0; i < this->vertices.getVertexCount(); i++) {
        *(&vpvertices[i].x) = &this->vertices[i].position.x;
        *(&vpvertices[i].y) = &this->vertices[i].position.y;
    }
}

/* ----- sfml ----- */

sfmlWindow::sfmlWindow(const vec::vector2i &sizeWin, const std::string &name) :
window(sf::VideoMode(sizeWin.x, sizeWin.y), name)
{
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
