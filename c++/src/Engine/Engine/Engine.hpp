
#include "../IEngine.hpp"

#include "../../../lib/lib3D/Object/Blender/Blender.hpp"
#include "../../../lib/libGraph/sfml/sfml.hpp"


class Engine : public IEngine
{
    private:
        vec::vector2i resolution;
        int FieldOfView;

        Graph *window;

        Entity *entity;
        Object *obj;

        std::vector<vec::vpvector2f> *vvpvertices;
        std::vector<int *> event;

        double Z0;
    public:
        Engine(Graph *win);
        ~Engine();

        virtual void draw() override;
};
