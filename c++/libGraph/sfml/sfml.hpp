#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Igraph.hpp"

class sfml : public Igraph
{
    private:
        sf::RenderWindow window;
        sf::Event event;
        std::map<std::string, sf::ConvexShape> allShape;
        std::map<std::string, sf::Clock> clock;
        std::vector<std::string> isPressedKey;

    public:
        sfml(const int x, const int y, const std::string name);
        sfml() = default;
        ~sfml();

        void setWindow(const int &fps, const std::string &title, const std::vector<int> &size);

        void pollEvent();

        void keyGest(const bool &isPressed, const std::string &key); /*not virtual*/
        const std::string keyToChar(const sf::Uint32 &key); /*not virtual*/
        const std::vector<std::string> &getKey();

        void display();
        bool isOpen();
        void clear();

        void setConvexShape(const std::string &id, const std::vector<Point2D_s> &Points);
        void setLineShape(const std::string &id, const size_t &size, const Point2D_s &Points1, const Point2D_s &Points2);
        void setAllLineShape(const std::vector<Line2D_s> &Lines);

        void drawShape(const std::string &id);
        void delShape(const std::string &id);

        void drawAllShape();

        void startClock(const std::string &id);
        void restartClock(const std::string &id);
        float getClock(const std::string &id);
};

