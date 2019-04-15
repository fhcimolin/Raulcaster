#include "pinguim.h"

sf::Texture TextureLoader::GetTexture(std::string name)
{
    sf::Texture texture;

    if (!texture.loadFromFile("../../res/" + name))
    {
        texture.update(new sf::Uint8[TILE_SIZE * TILE_SIZE * 4]);
    }

    return texture;
}

sf::Sprite TextureLoader::GetTileFromTexture(sf::Sprite sprite, int position)
{
    sprite.setTextureRect(sf::IntRect(
        TILE_SIZE * (position % 10), 
        TILE_SIZE * std::floor(position / 10), 
        TILE_SIZE, TILE_SIZE));

    return sprite;
}