#ifndef Graph_HPP
#define Graph_HPP

#include "../vector/vector.hpp"

namespace Graph
{
    class Vector2f
    {
        public:
            virtual float getX() = 0;
            virtual void setX(float x) = 0;
            virtual float getY() = 0;
            virtual void setY(float y) = 0;
    };

    class Vertex
    {
        public:
            virtual Vector2f &getPosition() = 0;
    };

    class Vertices
    {
        protected:
            virtual Vertex &getVertex(int index) = 0;

        public:
            Vertex &operator[](int index) {
                return this->getVertex(index);
            }
    };

    class Entity
    {
        protected:
            virtual Vertices &getVertices(int index) = 0;

        public:
            Vertices &operator[](int index) {
                return this->getVertices(index);
            }
    };

    class Window {
        public:
            virtual void draw(Entity &entity) = 0;
            virtual void pollEvent() = 0;
            virtual bool isOpen() = 0;
            virtual void clear() = 0;
            virtual void display() = 0;
    };
}

#endif