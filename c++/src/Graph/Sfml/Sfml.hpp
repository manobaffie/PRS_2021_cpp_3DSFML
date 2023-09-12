#ifndef Sfml_HPP
#define Sfml_HPP

#include "../Graph.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

namespace Sfml
{
    struct Settings
    {
        int fps = 10;
        vec::vector2D<int> sizeWin = {1080, 720};
        std::string name = "sfml a.out";
    };

    // class Vector2f:
    //     public sf::Vector2f,
    //     virtual public Graph::Vector2f
    // {
    //     public:
    //         Vector2f() = default;
    //         Vector2f(vec::vector2D<float> vertex);
    //         Vector2f(sf::Vector2f &vertex);
    //     public:
    //         float getX() override;
    //         void setX(float x) override;
    //         float getY() override;
    //         void setY(float y) override;
    // };

    class Vertex:
        virtual public Graph::Vertex,
        virtual public Graph::Vector2f
    {
        public:
            sf::Vertex &_vertex;
        public:
            Vertex() = default;
            Vertex(sf::Vertex &vertex);
        public:
            Graph::Vector2f &getPosition() override;
            float getX() override;
            float getY() override;
            void setX(float x) override;
            void setY(float y) override;
    };

    class Vertices:
        public std::vector<Vertex>,
        virtual public Graph::Vertices
    {
        public:
            sf::VertexArray _vertexArray;
        protected:
            Graph::Vertex &getVertex(int index) override;
        public:
            Vertices() = default;
            Vertices(std::vector<vec::vector2D<float>> vertices);
        public:
            using std::vector<Vertex>::operator[];
    };

    class Entity:
        public sf::Drawable,
        public sf::Transformable,
        public std::vector<Vertices>,
        virtual public Graph::Entity
    {
        private:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        protected:
            Graph::Vertices &getVertices(int index) override;
        public:
            Entity(std::vector<std::vector<vec::vector2D<float>>> entity);
            ~Entity() override;
        public:
            using std::vector<Vertices>::operator[];
    };

    class Window:
        virtual public Graph::Window
    {
        private:
            Sfml::Settings _settings;
            sf::RenderWindow _window;
            sf::Event _event;
        public:
            Window(Sfml::Settings settings = Sfml::Settings());
            ~Window();
        public:
            void draw(Graph::Entity &entity) override;
            void pollEvent() override;
            bool isOpen() override;
            void clear() override;
            void display() override;
    };
}

#endif
