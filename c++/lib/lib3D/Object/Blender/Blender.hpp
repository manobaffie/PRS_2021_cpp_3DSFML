#ifndef Blender_HPP
#define Blender_HPP

#include <cmath>

#include"../../../Parsing/Parsing.hpp"
#include "../Object.hpp"
#include "../../../math/matrix/matrix.hpp"

class Blender : public Object
{
    private:
        vec::vector2i res;
        float scale;
        float fov;
        float Z0;

        vec::pvector3f origine;

        vec::vvector3f points;
        std::vector<std::vector<int>> links;

        std::vector<vec::vpvector2f> vertices2f;
        std::vector<vec::vvector3f> vertices3f;

        void load(const std::string &path);
        void setPoints(const std::vector<std::string> &splitLine);
        void setLinks(const std::vector<std::string> &splitLine);
        void mapping();

    public:
        Blender(const vec::vector2i &res, const float &fov, const std::string &path);
        ~Blender();

        virtual void render2d() override;
        virtual void rotation(const vec::vector3f &r) override;
        virtual std::vector<vec::vpvector2f> *getVertices2d() override;
        virtual vec::pvector3f *getOrigine() override;
};

#endif