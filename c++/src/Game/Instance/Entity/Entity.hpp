#ifndef GameInstanceEntities_HPP_
#define GameInstanceEntities_HPP_

#include "../../../Graph/Sfml/Sfml.hpp"
#include "../../../Graph/Graph.hpp"
#include "../Base/Base.hpp"

namespace Game
{
    namespace Instance
    {
        class Entity:
            public Base
        {
            private:
                Graph::Entity *entity;
            public:
                Entity();
                ~Entity();
            public:
                Graph::Entity &get();
                std::vector<std::vector<vec::vector2D<float>>> buildEntity();

                void main() override;
        };
    }
}

#endif