#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Igraph.hpp"

class Entity : public sf::Drawable, public sf::Transformable
{
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        std::vector<sf::VertexArray> Vertices;
        sf::Texture Texture;

    public:
        Entity() = default;
        ~Entity();

        bool load(const std::vector<std::vector<coord_s>> &mapCoords, const std::string &pathTexture, const std::vector<std::vector<coord_s>> &textureCoords);
        void setPosition(const std::vector<std::vector<coord_s>> &mapCoords);
};

class sfml : public Igraph
{
    private:
        sf::RenderWindow window;
        sf::Event event;
        std::map<std::string, sf::ConvexShape> allShape;
        std::map<std::string, sf::Clock> clock;
        std::vector<std::string> isPressedKey;

        std::map<std::string, Entity> Entities;

    public:
        sfml(const int x, const int y, const std::string name);
        sfml() = default;
        ~sfml();

        void setWindow(const int &fps, const std::string &title, const std::vector<int> &size);

        void pollEvent();

        void keyGest(const bool &isPressed, const std::string &key); /*not virtual*/
        const std::string keyToChar(const sf::Uint32 &key); /*not virtual*/
        const std::vector<std::string> getKey();

        void display();
        bool isOpen();
        void clear();

        void startClock(const std::string &id);
        void restartClock(const std::string &id);
        float getClock(const std::string &id);

        void addEntity(const std::string &id, const std::vector<std::vector<coord_s>> &mapCoords, const std::string &pathTexture = "", const std::vector<std::vector<coord_s>> &textureCoords = {});
        void setCoordEntity(const std::string &id, const std::vector<std::vector<coord_s>> &mapCoords);
        void drawEntity(const std::string &id);
};
