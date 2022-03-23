#ifndef Player_HPP
#define Player_HPP

#include "../GameObject/GameObject.hpp"

class Player : public GameObject
{
    public:
        Player(const std::string &path);
        ~Player();
};

#endif