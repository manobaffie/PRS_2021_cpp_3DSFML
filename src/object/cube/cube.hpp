#include "../object.hpp"

class cube : public object
{
    private:
    public:
        cube(std::string id, Point3D_s Origine, size_t size);
        ~cube();
};
