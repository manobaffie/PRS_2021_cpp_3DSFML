#include "../object.hpp"

// pass all the variable in the object class

class Cube : public Object
{
    private:
        std::vector<Point3D_s> cubePoint;

        size_t Size;

    public:
        Cube(std::string id, Point3D_s origine, size_t size);
        ~Cube();

        void setPoint3D();
        void setLine3D(std::string Point1, std::string Point2);
};
