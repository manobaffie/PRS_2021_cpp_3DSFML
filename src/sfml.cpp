#include "sfml.hpp"

sfml::sfml(int x, int y, std::string name) : window(sf::VideoMode(x, y), name)
{
}

sfml::~sfml()
{
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

void sfml::convex(std::string name, std::vector<int> color, int pointCount)
{
    this->convexs[name].setPointCount(pointCount);
    this->convexs[name].setFillColor(sf::Color(color[0], color[1], color[2], color[3]));
}

void sfml::setConvex(std::string name, std::vector<std::vector<int>> points)
{
    for (int i = 0; i < (int)points.size(); i++) {
        this->convexs[name].setPoint(i, sf::Vector2f(points[i][0], points[i][1]));
    }
}

void sfml::drawConvex(std::string name)
{
    this->window.draw(this->convexs[name]);
}

void sfml::startClock(std::string id)
{
    sf::Clock c;
    this->clock[id] = c;
}

void sfml::restartClock(std::string id)
{
    this->clock[id].restart();
}

float sfml::getClock(std::string id)
{
    if (this->clock.find(id) != this->clock.end()) {
        return (sf::Time(this->clock[id].getElapsedTime()).asSeconds());
    } else {
        return (-1);
    }
}

void sfml::event()
{
    sf::Event event;
    while (this->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            this->window.close();
    }
}
