#include "Graph/Sfml/Sfml.hpp"

class BVertex
{
public:
    virtual ~BVertex() {}
    virtual int get() const = 0;
    virtual void set(int value) = 0;

};

class SfmlVertex : public sf::Vertex, public BVertex
{
public:
    SfmlVertex() : sf::Vertex() {}
    SfmlVertex(sf::Vertex v) : sf::Vertex(v) {}
    int get() const override { return this->position.x; }
    void set(int value) override { this->position.x = value; }
};

template <std::size_t Size>
class VertexArray
{
public:
    VertexArray() : primitiveType(sf::TriangleFan), size(0) {}

    void append(const BVertex &vertex)
    {
        if (size < Size)
        {
            vertices[size] = &vertex;
            sfVertices[size] = dynamic_cast<const SfmlVertex *>(&vertex); // Assurez-vous que la conversion est possible.
            size++;
        }
    }

    const BVertex &operator[](std::size_t index) const { return *vertices[index]; }

    std::size_t getSize() const { return size; }

private:
    const BVertex *vertices[Size];
    const SfmlVertex *sfVertices[Size];
    sf::PrimitiveType primitiveType;
    std::size_t size;
};

int main()
{
    VertexArray<10> va;
    SfmlVertex sfVertex1(sf::Vertex(sf::Vector2f(1, 2)));
    SfmlVertex sfVertex2(sf::Vertex(sf::Vector2f(3, 4)));

    va.append(sfVertex1);
    va.append(sfVertex2);

    for (std::size_t i = 0; i < va.getSize(); ++i)
    {
        const BVertex &bv = va[i];
        std::cout << bv.get() << std::endl;
    }

    return 0;
}

