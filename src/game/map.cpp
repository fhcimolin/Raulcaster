#include "map.h"

Map::Map() :
    mapReader{ std::make_unique<MapReader>() },
    tileset{ TextureLoader::GetTexture("knd.png") },
    currentPosition{ -64, -144 },
    scale{ 0.5f }
{
}

void Map::update(GameWindow& game)
{
    if(keys[sf::Keyboard::Escape])
    {
        game.dispose();
    }

    if(keys[sf::Keyboard::Q])
    {
        scale -= 0.001f;
    }

    if(keys[sf::Keyboard::W])
    {
        scale += 0.001f;
    }

    if(keys[sf::Keyboard::Up])
    {
        currentPosition.y--;
    }

    if(keys[sf::Keyboard::Down])
    {
        currentPosition.y++;
    }

    if(keys[sf::Keyboard::Left])
    {
        currentPosition.x--;
    }

    if(keys[sf::Keyboard::Right])
    {
        currentPosition.x++;
    }
}

void Map::draw(sf::RenderWindow& window)
{
    drawMap(window);
}

void Map::drawMap(sf::RenderWindow& window)
{
    sf::Sprite sprite;

    for(auto mapY = 0; mapY < mapReader->GetMapHeight(); mapY++)
    {
        for(auto mapX = 0; mapX < mapReader->GetMapWidth(); mapX++)
        {
            sprite.setTexture(tileset);
            sprite = TextureLoader::GetTileFromTexture(sprite, mapReader->worldMap[mapX][mapY]);

            // Apply zoom
            sprite.setScale(scale, scale);

            // Adjust space inbetween blocks
            sprite.setPosition(
                mapX * TextureLoader::TILE_SIZE * scale, 
                mapY * TextureLoader::TILE_SIZE * scale
            );

            // Place zoom on current position
            sprite.move(
                (window.getSize().x / 2) - (TextureLoader::TILE_SIZE * mapReader->GetMapWidth() * scale / 2) + currentPosition.x,
                (window.getSize().y / 2) - (TextureLoader::TILE_SIZE * mapReader->GetMapHeight() * scale / 2) + currentPosition.y
            );
            
            window.draw(sprite);
        }   
    }
}