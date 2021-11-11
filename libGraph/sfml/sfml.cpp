#include "sfml.hpp"

sfml::sfml(const int x, const int y, const std::string name) : window(sf::VideoMode(x, y), name)
{
}

sfml::~sfml()
{
    this->window.close();
}

void sfml::setWindow(const int &fps, const std::string &title, const std::vector<int> &size)
{
    this->window.setFramerateLimit(fps);
    this->window.setTitle(title);
    // size = size;
    // this->window.setSize((sf::Vector2u){size[0], size[1]});
}

void sfml::pollEvent()
{
    while (this->window.pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window.close();
                break;
            case sf::Event::KeyPressed:
                this->keyGest(true, this->keyToChar(this->event.text.unicode));
                break;
            case sf::Event::KeyReleased:
                this->keyGest(false, this->keyToChar(this->event.text.unicode));
                break;
            default:
                break;
        }
    }
}

void sfml::keyGest(const bool &isPressed, const std::string &key)
{
    if (key == "Error")
        return;

    if (!isPressed) {
        this->isPressedKey.erase(std::find(this->isPressedKey.begin(), this->isPressedKey.end(), key));
    } else if (std::count(this->isPressedKey.cbegin(), this->isPressedKey.cend(), key) == 0) {
        this->isPressedKey.push_back(key);
    }
}

const std::string sfml::keyToChar(const sf::Uint32 &key)
{
    switch (key) {
        case (sf::Keyboard::Z):
            return ("Z");
            break;
        case (sf::Keyboard::Q):
            return ("Q");
            break;
        case (sf::Keyboard::S):
            return ("S");
            break;
        case (sf::Keyboard::D):
            return ("D");
            break;
        case (sf::Keyboard::Space):
            return ("Space");
        case (sf::Keyboard::Left):
            return ("Left");
        case (sf::Keyboard::Right):
            return ("Right");
        default:
            break;
    }
    return ("error");
}

const std::vector<std::string> &sfml::getKey()
{
    return (this->isPressedKey);
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

void sfml::setConvexShape(const std::string &id, const std::vector<Point2D_s> &Points)
{
    sf::ConvexShape convex;

    convex.setPointCount(Points.size());
    for (size_t i = 0; i < Points.size(); i++) {
        convex.setPoint(i, sf::Vector2f(Points[i].x, Points[i].y));
    }

    if (this->allShape.count(id) == 0) {
        this->allShape.insert(std::make_pair(id, convex));
    } else {
        this->allShape[id] = convex;
    }
}

void sfml::setLineShape(const std::string &id, const size_t &BC, const Point2D_s &A, const Point2D_s &B)
{
    double k = (BC / 2) / std::sqrt(std::pow(B.x - A.x, 2) + std::pow(B.y - A.y, 2));

    Point2D_s c1 = Point2D_s::Create(
        -1 * k * A.y + k * B.y + B.x,
        k * A.x - k * B.x + B.y
    );

    Point2D_s c2 = Point2D_s::Create(
        2 * B.x - c1.x,
        2 * B.y - c1.y
    );

    Point2D_s c4 = Point2D_s::Create(
        A.x + B.x - c2.x,
        A.y + B.y - c2.y
    );

    Point2D_s c3 = Point2D_s::Create(
        A.x + B.x - c1.x,
        A.y + B.y - c1.y
    );
    this->setConvexShape(
        id,
        {
            c1,
            c2,
            c3,
            c4
        }
    );
}

void sfml::setAllLineShape(const std::vector<Line2D_s> &lines)
{
    for (const Line2D_s &line : lines) {
        this->setLineShape (
            line.id,
            line.size,
            line.Points1,
            line.Points2
        );
    }
}

void sfml::drawShape(const std::string &id)
{
    this->window.draw(this->allShape[id]);
}

void sfml::delShape(const std::string &id)
{
    this->allShape.erase(id);
}

void sfml::drawAllShape()
{
    for(std::map<std::string, sf::ConvexShape>::const_iterator it = this->allShape.begin() ; it != this->allShape.end() ; ++it) {
        this->drawShape(it->first);
    }
}

void sfml::startClock(const std::string &id)
{
    sf::Clock c;
    this->clock[id] = c;
}

void sfml::restartClock(const std::string &id)
{
    this->clock[id].restart();
}

float sfml::getClock(const std::string &id)
{
    if (this->clock.find(id) != this->clock.end()) {
        return (sf::Time(this->clock[id].getElapsedTime()).asSeconds());
    } else {
        return (-1);
    }
}

extern "C" {
    Igraph* create() {
        return new sfml(1080, 920, "3Dtest");
    }

    void destroy(Igraph* obj) {
        delete obj;
    }
}