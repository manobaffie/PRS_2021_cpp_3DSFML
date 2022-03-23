#ifndef Graph_HPP
#define Graph_HPP

#include <iostream>

#include "../vector/vector.hpp"

struct EventType
{
    bool Z = false;
    bool Q = false;
    bool S = false;
    bool D = false;
    bool Up = false;
    bool Down = false;
    bool Left = false;
    bool Right = false;
    bool Space = false;
    bool LShift = false;

    vec::vector2i mouse = {0, 0};
};

class Entity
{
    public:

        Entity() = default;
        virtual ~Entity() = default;
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
        virtual vec::vector2i getSize() = 0;
        virtual EventType pollEvent() = 0;
};

#endif