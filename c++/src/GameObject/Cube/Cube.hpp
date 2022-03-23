#ifndef Cube_HPP
#define Cube_HPP

#include "../GameObject/GameObject.hpp"

class Cube : public GameObject
{
    public:
        Cube(const std::string &path, const vec::vector3f origine);
        ~Cube();
};

#endif