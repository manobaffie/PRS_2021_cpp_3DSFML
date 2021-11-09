#include "../object.hpp"

class cube : public object
{
    private:
        std::vector<Point3D_s> cubePreset;
        std::vector<Line3D_s> cubePoints;

        std::string cubeId;
        Point3D_s Origine;
        size_t Size;

    public:
        cube(std::string id, Point3D_s origine, size_t size);
        ~cube();

        std::vector<Line3D_s> getCubePoints();

        void setLine3D();
        void setLine3DFace(int range0, int range1, int add, int init, int limit);
        void setPresetLine3D();

        void printCube();
};
