#ifndef Blender_HPP
#define Blender_HPP

#include"../../../Parsing/Parsing.hpp"
#include "../Object.hpp"

class Blender : public Object
{
    private:
        vec::vvector3d points;
        std::vector<std::vector<int>> links;

        void load(const std::string &path);
        void setPoints(const std::vector<std::string> &splitLine);
        void setLinks(const std::vector<std::string> &splitLine);
        void mapping();

    public:
        Blender(const std::string &path);
        ~Blender();

        
};

#endif