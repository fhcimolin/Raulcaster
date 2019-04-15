#include "mapReader.h"

int MapReader::GetMapHeight()
{
    return MAP_HEIGHT;
}

int MapReader::GetMapWidth()
{
    return MAP_WIDTH;
}

MapReader::MapReader()
{
    worldMap = std::array<std::array<int, MAP_WIDTH>, MAP_HEIGHT>(
    {
        std::array<int, MAP_WIDTH>
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,5,0,0,0,0,5,5,0,0,0,0,0,0,5,5,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,5,0,5,0,0,5,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,5,0,0,0,0,0,0,5,0,5,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,5,0,0,0,0,0,0,0,0,5,5,5,5,5,0,0,0,0,0,3},
        {3,0,0,0,0,5,5,0,5,5,0,0,0,0,0,0,5,0,0,0,0,0,0,3},
        {3,0,0,0,0,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,5,5,5,5,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,5,5,5,5,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,5,5,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,5,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,5,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,5,5,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    });    
}