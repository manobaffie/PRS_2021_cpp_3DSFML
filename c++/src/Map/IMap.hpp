#include "../../lib/vector/vector.hpp"

enum MapType {
    Floor,
    Tree,
    Base
};

struct MapData
{
    float x;
    float y;
    float z;
    MapType type;
};

class IMap
{
    public:
        IMap() = default;
        virtual ~IMap() = default;

        virtual std::vector<MapData> getMap() = 0;
        virtual void print() = 0;
        virtual void addInMap(MapData &mdt) = 0;
};
