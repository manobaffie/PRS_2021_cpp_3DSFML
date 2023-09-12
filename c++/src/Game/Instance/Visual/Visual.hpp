#ifndef GameInstanceVisual_HPP_
#define GameInstanceVisual_HPP_

#include "../../../Graph/Graph.hpp"
#include "../Base/Base.hpp"

namespace Game
{
    namespace Instance
    {
        class Visual:
            public Base
        {
            protected:
                std::unique_ptr<Graph::Window> _window;
            public:
                std::vector<std::reference_wrapper<Graph::Entity>> enties;
            public:
                Visual(std::unique_ptr<Graph::Window> window);
                ~Visual();
            public:
                void main() override;
                bool isRunning() override;
                void frequency() override;
                virtual void draw();
        };
    }
}

#endif