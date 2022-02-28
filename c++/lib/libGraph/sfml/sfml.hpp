#ifndef sfml_HPP
#define sfml_HPP

#include "../Graph.hpp"
#include <SFML/Graphics.hpp>

class sfmlEntity : public Entity, public sf::Drawable, public sf::Transformable
{
    private:
        sf::VertexArray vertices;
        sf::Texture texture;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        sfmlEntity(const vec::vvector2f &vvertices, const vec::vector4i &color);
        ~sfmlEntity();

        virtual void loadVertices(vec::vpvector2f &vertices) override;
};

class sfmlWindow : public Graph
{
    private:
        sf::RenderWindow window;
        sf::Event event;

    public:
        sfmlWindow(const vec::vector2i &sizeWin, const std::string &name);
        ~sfmlWindow();

        virtual void draw(Entity *entity) override;
        virtual void clear() override;
        virtual void display() override;
        virtual bool isOpen() override;
        virtual void pollEvent() override;

};

#endif