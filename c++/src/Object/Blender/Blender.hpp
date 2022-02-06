#include "../../../lib/Parsing/Parsing.hpp"
#include "../Object.hpp"

class Blender : public Object
{
    private:
        std::string Path;
        std::vector<Point<float>> Points3D;
        std::vector<Point<float>> Texture;
        std::vector<std::vector<std::vector<size_t>>> Links;

    public:
        Blender(const std::string &id, const std::string &Path);
        ~Blender();

        void parsing();
        void LinkPoints();
};
