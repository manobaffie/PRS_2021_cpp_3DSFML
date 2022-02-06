#ifndef Igraph_HPP
#define Igraph_HPP

#include <vector>
#include <iostream>
#include <algorithm>

struct coord_s
{
    float x;
    float y;
    float z;
};

class Igraph
{
    public:
        Igraph(const int x, const int y, const std::string name);
        Igraph() = default;
        virtual ~Igraph() = default;

        virtual void setWindow(const int &fps, const std::string &title, const std::vector<int> &size) = 0;

        virtual void pollEvent() = 0;

        virtual const std::vector<std::string> getKey() = 0;

        virtual void display() = 0;
        virtual bool isOpen() = 0;
        virtual void clear() = 0;

        virtual void startClock(const std::string &id) = 0;
        virtual void restartClock(const std::string &id) = 0;
        virtual float getClock(const std::string &id) = 0;

        virtual void addEntity(const std::string &id, const std::vector<std::vector<coord_s>> &mapCoords, const std::string &pathTexture = "", const std::vector<std::vector<coord_s>> &textureCoords = {}) = 0;
        virtual void setCoordEntity(const std::string &id, const std::vector<std::vector<coord_s>> &mapCoords) = 0;
        virtual void drawEntity(const std::string &id) = 0;
};

#endif