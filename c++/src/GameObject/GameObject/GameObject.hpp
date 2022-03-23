#ifndef GameObject_HPP
#define GameObject_HPP

#include "../IGameObject.hpp"

class GameObject : public IGameObject
{
    protected:
        Entity *entity;
        Object *obj;

        vec::vector3f position;

    public:
        GameObject(const std::string &path, const vec::vector3f origine);
        ~GameObject();

        virtual void setPosition(const vec::vector3f &pos) override;
        virtual const vec::vector3f getPosition() override;
        virtual void setMoove(const vec::vector3f &Moove) override;
        virtual void rotation(const vec::vector3f &angl, vec::vector3f origine) override;

        virtual Entity *getEntity() override;
        virtual Object *getObject() override;
};

#endif