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

namespace pi
{
    Text::Text(std::string inputText, sf::Color color, int size) :
        font{}, 
        text{},
        clock{},
        currentChar{0},
        textContent{inputText}
    {
        if (!font.loadFromFile("../../res/font/arial.ttf"))
        {
        }

        text.setFont(font);
        text.setFillColor(color);
        text.setCharacterSize(size);
    }

    void Text::setPosition(float x, float y)
    {
        text.setPosition(x, y);
    }

    /**
     * Gets all characters from text immediately
     */
    sf::Text Text::getText()
    {
        currentChar = textContent.length() - 1;

        text.setString(textContent);
        
        return text;
    }

    /**
     * Gets text gradually, character by character. Be careful not to create a pi::Text on the draw method.
     * 
     * @param[in] speed the speed in which each letter will appear. It's a second divided by the speed for each.
     */
    sf::Text Text::getTextSpelled(size_t speed)
    {
        sf::Time timeElapsedSinceTrigger = clock.getElapsedTime();

        if(timeElapsedSinceTrigger.asSeconds() > 1.0f / speed)
        {
            clock.restart();
            
            if(currentChar < textContent.length())
            {
                currentChar++;

                text.setString(textContent.substr(0, currentChar));

                return text;
            }
        }

        return text;
    }
}