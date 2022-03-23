#ifndef Blender_HPP
#define Blender_HPP

#include <cmath>

#include"../../../Parsing/Parsing.hpp"
#include "../Object.hpp"
#include "../../../math/matrix/matrix.hpp"

class Blender : public Object
{
    private:
        vec::vector2i resolution;
        float scale;
        float fov;
        float Z0;

        vec::pvector3f position;

        vec::vvector3f points;
        std::vector<std::vector<int>> links;

        std::vector<vec::vpvector2f> vertices2f;
        std::vector<vec::vvector3f> vertices3f;

        void load(const std::string &path);
        void setPoints(const std::vector<std::string> &splitLine);
        void setLinks(const std::vector<std::string> &splitLine);
        void mapping();

    public:
        Blender(
            const std::string &path,
            const vec::vector3f origine = {0, 0, 0},
            const vec::vector2i resolution = {1080, 720},
            const float fov = 45
        );
        ~Blender();

        virtual void render2d() override;
        virtual void rotation(const vec::vector3f &angl, vec::vector3f &origine) override;
        virtual std::vector<vec::vpvector2f> *getVertices2d() override;
        virtual vec::pvector3f *getPosition() override;
        virtual void setMoove(const vec::vector3f &moov) override;

};

#endif