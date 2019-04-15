#include "mapReader.h"
#include "map.h"

Map::Map()
{
    tileset = TextureLoader::GetTexture("knd.png");
    
    scale = 0.5f;
}

void Map::update(GameWindow& game)
{
    if(keys[sf::Keyboard::K])
    {
        game.dispose();
    }

    if(keys[sf::Keyboard::Left])
    {
        scale = scale - 0.001f;
    }

    if(keys[sf::Keyboard::Right])
    {
        scale = scale + 0.001f;
    }
}

void Map::draw(sf::RenderWindow& window)
{
    MapReader mapReader;

    for(auto mapY = 0; mapY < mapReader.GetMapHeight(); mapY++)
    {
        sf::Sprite sprite;

        for(auto mapX = 0; mapX < mapReader.GetMapWidth(); mapX++)
        {
            sprite.setTexture(tileset);
            
            sprite = TextureLoader::GetTileFromTexture(sprite, mapReader.worldMap[mapX][mapY]);

            sprite.setScale(scale, scale);

            sprite.setPosition(mapX * 64 * scale, mapY * 64 * scale);
            
            window.draw(sprite);
        }   
    }
}

void Map::setScale(float factor)
{

}