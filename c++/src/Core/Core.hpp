#ifndef Core_HPP
#define Core_HPP

#include <iostream>

#include "../../lib/libGraph/sfml/sfml.hpp"

#include "../Engine/Engine/Engine.hpp"

#include "../GameObject/Player/Player.hpp"
#include "../GameObject/Tree/Tree.hpp"
#include "../GameObject/Cube/Cube.hpp"

class Core
{
    private:
        Graph *window;

    public:
        Core();
        ~Core();

        void main();
};

#endif