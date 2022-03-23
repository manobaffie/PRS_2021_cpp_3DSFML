#ifndef Tree_HPP
#define Tree_HPP

#include "../GameObject/GameObject.hpp"

class Tree : public GameObject
{
    public:
        Tree(const std::string &path, const vec::vector3f origine);
        ~Tree();
};

#endif