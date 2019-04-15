#include <array>
#include <iostream>

constexpr int MAP_HEIGHT = 24;
constexpr int MAP_WIDTH = 24;

class MapReader
{
public:
    MapReader();

    int GetMapHeight();
    int GetMapWidth();

    std::array<std::array<int, MAP_WIDTH>, MAP_HEIGHT> worldMap;
};