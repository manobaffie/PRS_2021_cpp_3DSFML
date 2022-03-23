#ifndef Map_HPP
#define Map_HPP

#include "../IMap.hpp"

class Map : public IMap
{
    private:
        std::vector<MapData *> *map;

        void floor();
    public:
        Map();
        ~Map();

        std::vector<MapData *> *getMap();
        void print();
        void addInMap(MapData &mdt);
};

#endif