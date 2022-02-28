#include "../Graph3D.hpp"

#include "../../Object/Blender/Blender.hpp"
#include "../../../libGraph/sfml/sfml.hpp"

class Engine : public Graph3D
{
    private:
        Graph *window;
        Entity *entity;

    public:
        Engine(Graph *win);
        ~Engine();

        virtual void draw() override;
};
