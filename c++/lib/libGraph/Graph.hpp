#ifndef Graph_HPP
#define Graph_HPP

#include <iostream>

#include "../vector/vector.hpp"

class Entity
{
    public:

        Entity() = default;
        virtual ~Entity() = default;

        virtual void loadVertices(vec::vpvector2f &vvertices) = 0;
};

class Graph
{
    public:
        Graph() = default;
        virtual ~Graph() = default;

        virtual void draw(Entity *entity) = 0;
        virtual void clear() = 0;
        virtual void display() = 0;
        virtual bool isOpen() = 0;
        virtual void pollEvent() = 0;
};

#endif