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

    public:
        sfml(int x, int y, std::string name);
        sfml() = default;
        ~sfml();

        void setWindow(int fps, std::string title, std::vector<int> size);

        void pollEvent();

        void display();
        bool isOpen();
        void clear();

        void setConvexShape(std::string id, std::vector<Point2D_s> Points);
        void setLineShape(std::string id, size_t size, Point2D_s Points1, Point2D_s Points2);

        void drawShape(std::string id);
        void delShape(std::string id);

        void drawAllShape();

        void startClock(std::string id);
        void restartClock(std::string id);
        float getClock(std::string id);
};

