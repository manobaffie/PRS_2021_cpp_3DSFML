#include "Map.hpp"

Map::Map()
{
    this->floor();

    MapData tree = {
        .x = 0,
        .y = 0,
        .z = 5,
        .type = MapType::Tree
    };


    this->addInMap(tree);
}

Map::~Map()
{
}

void Map::floor()
{
    MapData floorData = {.type = MapType::Floor};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            floorData.z = i;
            floorData.x = j;
            floorData.y = 0;
            this->map.push_back(floorData);
        }
    }
}

std::vector<MapData> Map::getMap()
{
    return (this->map);
}

void Map::addInMap(MapData &mdt)
{
    this->map.push_back(mdt);
}

void Map::print()
{
    // for (std::vector<MapType> i : this->map) {
    //     for (MapType j : i) {
    //         std::cout << j << " - ";
    //     }
    //     std::cout << std::endl;
    // }
}