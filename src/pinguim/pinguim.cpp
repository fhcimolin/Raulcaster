#include "pinguim.h"

sf::Texture TextureLoader::GetTexture(std::string name)
{
    sf::Texture texture;

    if (!texture.loadFromFile(name))
    {
        // error...
    }

    return texture;
}