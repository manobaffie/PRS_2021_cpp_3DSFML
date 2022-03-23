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

EventType sfmlWindow::pollEvent()
{
    while (this->window.pollEvent(this->event)) {
        switch (this->event.type) {
            case (sf::Event::Closed):
                this->window.close();
                break;
            case(sf::Event::KeyPressed):
                this->keyToChar(true, this->event.text.unicode);
                break;
            case(sf::Event::KeyReleased):
                this->keyToChar(false, this->event.text.unicode);
                break;
            default:
                break;
        }
    }
    return (this->eventType);
}

void sfmlWindow::keyToChar(const bool &r, const sf::Uint32 &key)
{
    switch (key) {
        case (sf::Keyboard::Z):
            this->eventType.Z = this->eventType.Z ? (r ? true : false) : true;
            break;
        case (sf::Keyboard::Q):
            this->eventType.Q = this->eventType.Q ? (r ? true : false) : true;
            break;
        case (sf::Keyboard::S):
            this->eventType.S = this->eventType.S ? (r ? true : false) : true;
            break;
        case (sf::Keyboard::D):
            this->eventType.D = this->eventType.D ? (r ? true : false) : true;
            break;
        case (sf::Keyboard::Up):
            this->eventType.Up = this->eventType.Up ? (r ? true : false) : true;
            break;
        case (sf::Keyboard::Down):
            this->eventType.Down = this->eventType.Down ? (r ? true : false) : true;
            break;
        case (sf::Keyboard::Left):
            this->eventType.Left = this->eventType.Left ? (r ? true : false) : true;
            break;
        case (sf::Keyboard::Right):
            this->eventType.Right = this->eventType.Right ? (r ? true : false) : true;
            break;
        case (sf::Keyboard::Space):
            this->eventType.Space = this->eventType.Space ? (r ? true : false) : true;
            break;
        case (sf::Keyboard::LShift):
            this->eventType.LShift = this->eventType.LShift ? (r ? true : false) : true;
            break;
        default:
            break;
    }
}
