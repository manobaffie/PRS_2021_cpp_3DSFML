#ifndef MyGameInstanceVisual_HPP_
#define MyGameInstanceVisual_HPP_

#include "../../../Game/Instance/Visual/Visual.hpp"
#include "../../../Game/Instance/Entity/Entity.hpp"
#include "../../../Graph/Sfml/Sfml.hpp"

namespace MyGame
{
    namespace Instance
    {
        class Visual:
            public Game::Instance::Visual
        {
            private:
            public:
                Visual();
                ~Visual();
        };
    }
}

#endif
