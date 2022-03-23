#ifndef Object_HPP
#define Object_HPP

#include "../../vector/vector.hpp"

class Object
{
    public:
        Object() = default;
        virtual ~Object() = default;

        virtual void render2d() = 0;
        virtual std::vector<vec::vpvector2f> *getVertices2d() = 0;
        virtual void rotation(const vec::vector3f &angl, vec::vector3f &origine) = 0;
        virtual vec::pvector3f *getPosition() = 0;
        virtual void setMoove(const vec::vector3f &moov) = 0;
};

#endif