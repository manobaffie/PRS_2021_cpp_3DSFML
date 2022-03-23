#include "../../lib/libGraph/Graph.hpp"

#include "../GameObject/IGameObject.hpp"

class IEngine
{
    public:
        IEngine() = default;
        virtual ~IEngine() = default;

        virtual void draw() = 0;
        virtual void transform() = 0;
        virtual void deplacement(const EventType &a, const vec::vector3f &rotaVal, const float &speed) = 0;
        virtual void rotation(const EventType &a, const vec::vector3f &rotaVal, const float &speed) = 0;
        virtual void addGameObject(IGameObject *go) = 0;

        // virtual void setMap();
};
