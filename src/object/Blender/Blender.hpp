#include "../../../lib/Parsing/Parsing.hpp"
#include "../Object.hpp"

class Blender : public Object
{
    private:
        std::string Path;
        std::vector<Point3D_s> Points3D;
        std::vector<std::vector<size_t>> Links;

    public:
        Blender(const std::string &id, const std::string &Path);
        ~Blender();

        void parsing();
        void LinkPoints();
};
