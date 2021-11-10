#ifndef Igraph_HPP
#define Igraph_HPP

#include <vector>
#include <iostream>

#include "../src/object/Point.hpp"

class Igraph
{
    public:
        Igraph(const int x, const int y, const std::string name);
        Igraph() = default;
        virtual ~Igraph() = default;

        virtual void setWindow(const int &fps, const std::string &title, const std::vector<int> &size) = 0;

        virtual void pollEvent() = 0;

        virtual void display() = 0;
        virtual bool isOpen() = 0;
        virtual void clear() = 0;

        virtual void setConvexShape(const std::string &id, const std::vector<Point2D_s> &Points) = 0;
        virtual void setLineShape(const std::string &id, const size_t &size, const Point2D_s &Points1, const Point2D_s &Points2) = 0;
        virtual void setAllLineShape(const std::vector<Line2D_s> &Lines) = 0;

        virtual void drawShape(const std::string &id) = 0;
        virtual void delShape(const std::string &id) = 0;

        virtual void drawAllShape() = 0;

        virtual void startClock(const std::string &id) = 0;
        virtual void restartClock(const std::string &id) = 0;
        virtual float getClock(const std::string &id) = 0;
};

#endif