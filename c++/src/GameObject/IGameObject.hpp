#ifndef IGameObject_HPP
#define IGameObject_HPP

#include "../../lib/vector/vector.hpp"

#include "../../lib/libGraph/Graph.hpp"
#include "../../lib/libGraph/sfml/sfml.hpp"

#include "../../lib/lib3D/Object/Object.hpp"
#include "../../lib/lib3D/Object/Blender/Blender.hpp"

class IGameObject
{
    public:
        IGameObject() = default;
        virtual ~IGameObject() = default;

        virtual void setPosition(const vec::vector3f &pos) = 0;
        virtual const vec::vector3f getPosition() = 0;

        virtual void setMoove(const vec::vector3f &Moove) = 0;
        virtual void rotation(const vec::vector3f &angl, vec::vector3f origine) = 0;


        virtual Entity *getEntity() = 0;
        virtual Object *getObject() = 0;

};

#endif