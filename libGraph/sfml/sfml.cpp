#include "sfml.hpp"

sfml::sfml(int x, int y, std::string name) : window(sf::VideoMode(x, y), name)
{
}

sfml::~sfml()
{
}

void sfml::setWindow(int fps, std::string title, std::vector<int> size)
{
    this->window.setFramerateLimit(fps);
    this->window.setTitle(title);
    size = size;
    // this->window.setSize((sf::Vector2u){size[0], size[1]});
}

void sfml::pollEvent()
{
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed)
            this->window.close();
    }
}

void sfml::display()
{
    this->window.display();
}

bool sfml::isOpen()
{
    return (this->window.isOpen());
}

void sfml::clear()
{
    this->window.clear();
}

void sfml::setConvexShape(std::string id, std::vector<Points_s> Points)
{
    sf::ConvexShape convex;

    convex.setPointCount(Points.size());
    for (size_t i = 0; i < Points.size(); i++) {
        convex.setPoint(i, sf::Vector2f(Points[i].x, Points[i].y));
    }
    this->allShape.insert(std::make_pair(id, convex));
}

void sfml::setLineShape(std::string id, size_t size, Points_s Points1, Points_s Points2)
{
    this->setConvexShape(id, 
        {
            {Points1.x, Points1.y},
            {int(Points1.x + (size / 2)), Points1.y},
            {int(Points2.x + (size / 2)), int(Points2.y + (size / 2))},
            {Points2.x, int(Points2.y + (size / 2))}
        }
    );
}


void sfml::drawShape(std::string id)
{
    this->window.draw(this->allShape[id]);
}

void sfml::delShape(std::string id)
{
    this->allShape.erase(id);
}

extern "C" {
    Igraph* create() {
        return new sfml(1080, 920, "3Dtest");
    }

    void destroy(Igraph* obj) {
        delete obj;
    }
}