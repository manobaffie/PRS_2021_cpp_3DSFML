#ifndef Engine_HPP
#define Engine_HPP

#include "../IEngine.hpp"

#include "../../../lib/lib3D/Object/Object.hpp"
#include "../../GameObject/Player/Player.hpp"

class Engine : public IEngine
{
    private:

        vec::vector3f worldDegres;

        vec::vector2i resolution;
        int FieldOfView;
        double Z0;

        Graph *window;

        std::vector<IGameObject *> objs;

        IGameObject *player;
        // Object *objP;
        // Entity *entityP;

        virtual void genMap();
        virtual void deplacementObj(IGameObject *obj, const EventType &a, const vec::vector3f &rotaVal, const float &speed);
        virtual void rotationObj(IGameObject *obj, const EventType &a, const vec::vector3f &rotaVal, const float &speed);

    public:
        Engine(Graph *win);
        ~Engine();

        virtual void draw() override;

        virtual void transform() override;
        virtual void deplacement(const EventType &a, const vec::vector3f &rotaVal, const float &speed) override;
        virtual void rotation(const EventType &a, const vec::vector3f &rotaVal, const float &speed) override;

        virtual void addGameObject(IGameObject *go) override;
};

#endif