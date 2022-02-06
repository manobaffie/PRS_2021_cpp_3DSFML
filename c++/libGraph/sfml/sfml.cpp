#include "sfml.hpp"

// Entity Class

Entity::~Entity()
{
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= this->getTransform();
    states.texture = &this->Texture;

    for (sf::VertexArray i : this->Vertices) {
        target.draw(i, states);
    }
}

bool Entity::load(const std::vector<std::vector<coord_s>> &mapCoords, const std::string &pathTexture, const std::vector<std::vector<coord_s>> &textureCoords)
{
    bool noTexture = false;
    if (pathTexture == "")
        noTexture = true;

    sf::Vector2u sizeTexture;

    if (!noTexture) {
        if (!this->Texture.loadFromFile(pathTexture)) {
            std::cerr << "[ERROR SFML] -> can't load path of the texture" << std::endl;
            return (false);
        }
        sizeTexture = this->Texture.getSize();
        std::cout << "texture load" << std::endl;
    }

    this->Vertices.resize(mapCoords.size());

    for (size_t i = 0; i < mapCoords.size(); i++) {

        this->Vertices[i].setPrimitiveType(sf::TriangleFan);
        this->Vertices[i].resize(mapCoords[i].size());

        for (size_t j = 0; j < mapCoords[i].size(); j++) {

            if (!noTexture) {
                this->Vertices[i][j].texCoords.x = textureCoords[i][j].x * sizeTexture.x;
                this->Vertices[i][j].texCoords.y = textureCoords[i][j].y * sizeTexture.y;
            } else {
                this->Vertices[i][j].color = sf::Color(255, 255, 255, 30);
                this->Vertices[i][j].color = sf::Color(255, 255, 255, 30);
            }
            this->Vertices[i][j].position.x = mapCoords[i][j].x;
            this->Vertices[i][j].position.y = mapCoords[i][j].y;
        }
    }

    return (true);
}

void Entity::setPosition(const std::vector<std::vector<coord_s>> &mapCoords)
{
    for (size_t i = 0; i < mapCoords.size(); i++) {
        for (size_t j = 0; j < mapCoords[i].size(); j++) {
            this->Vertices[i][j].position.x = mapCoords[i][j].x;
            this->Vertices[i][j].position.y = mapCoords[i][j].y;
        }
    }
}

// sfml Class

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
        case (sf::Keyboard::Q):
            return ("Q");
        case (sf::Keyboard::S):
            return ("S");
        case (sf::Keyboard::D):
            return ("D");
        case (sf::Keyboard::Up):
            return ("Up");
        case (sf::Keyboard::Down):
            return ("Down");
        case (sf::Keyboard::Left):
            return ("Left");
        case (sf::Keyboard::Right):
            return ("Right");
        default:
            break;
    }
    return ("error");
}

const std::vector<std::string> sfml::getKey()
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

// gestion of Entity by the sfml

void sfml::addEntity(const std::string &id, const std::vector<std::vector<coord_s>> &mapCoords, const std::string &pathTexture, const std::vector<std::vector<coord_s>> &textureCoords)
{
    Entity entity;

    entity.load(mapCoords, pathTexture, textureCoords);

    this->Entities.insert(std::make_pair(id, entity));
}

void sfml::setCoordEntity(const std::string &id, const std::vector<std::vector<coord_s>> &mapCoords)
{
    this->Entities[id].setPosition(mapCoords);
}

void sfml::drawEntity(const std::string &id)
{
    this->window.draw(this->Entities[id]);
}

extern "C" {
    Igraph* create() {
        return new sfml(1080, 920, "3Dtest");
    }

    void destroy(Igraph* obj) {
        delete obj;
    }
}