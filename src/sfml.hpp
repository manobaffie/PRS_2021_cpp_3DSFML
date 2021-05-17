#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>

class sfml
{
    private:
        sf::RenderWindow window;

        std::map<std::string, sf::ConvexShape> convexs;
        std::map<std::string, sf::Clock> clock;

    public:
        sfml(int x, int y, std::string name);
        ~sfml();

        void display();
        bool isOpen();
        void clear();
        void event();

        void convex(std::string &name, std::vector<int> color, int pointCountm);
        void setConvex(std::string &name, std::vector<std::vector<int>> &points);
        void drawConvex(std::string &name);

        void startClock(std::string id);
        void restartClock(std::string id);
        float getClock(std::string id);

        template <typename T>
        void draw(T &Obj) {
            this->window.draw(Obj);
        }
};

