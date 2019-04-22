#include "pinguim.h"

sf::Texture TextureLoader::getTexture(std::string name)
{
    sf::Texture texture;

    if (!texture.loadFromFile("../../res/" + name))
    {
        texture.update(new sf::Uint8[TILE_SIZE * TILE_SIZE * 4]);
    }

    return texture;
}

sf::Sprite TextureLoader::getTileFromTexture(sf::Sprite sprite, int position)
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
        currentChar{0},
        textContent{inputText},
        framesSinceTrigger{0}
    {
        if (!font.loadFromFile("../../res/font/arial.ttf"))
        {
            std::cout << "Unable to load font arial.ttf." << std::endl;
        }
        
        text.setFont(font);
        text.setFillColor(color);
        text.setCharacterSize(size);
    }

    bool Text::isTextPrinted()
    {
        return currentChar >= textContent.length() - 1;
    }

    void Text::move(float x, float y)
    {
        text.move(x, y);
    }

    void Text::setPosition(float x, float y)
    {
        text.setPosition(x, y);
    }

    void Text::setText(std::string inputText)
    {
        textContent = inputText;
        restartText();
    }
        
    void Text::restartText()
    {
        currentChar = 0;
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
     * @param[in] frameDelay the speed in which each letter will appear. It's a letter a frame, should speed == 1.
     */
    sf::Text Text::getTextSpelled(size_t frameDelay)
    {
        if(++framesSinceTrigger >= frameDelay)
        {
            framesSinceTrigger = 0;
            
            if(currentChar < textContent.length())
            {
                currentChar++;

                text.setString(textContent.substr(0, currentChar));
            }
        }

        return text;
    }

    /***
     *  Class TextPusher 
     * 
     */

    TextPusher::TextPusher() :
        textQueue{},
        textShown{},
        origin{0,0},
        readIndex{0},
        framesActive{0}
    {
    }

    TextPusher::~TextPusher()
    {
        clear();
    }

    void TextPusher::setOrigin(float x, float y)
    {
        origin = Point{x, y};
    }

    void TextPusher::sendText(std::string inputText)
    {
        pi::Text* text = new pi::Text(inputText, sf::Color::White, 12);

        textQueue.push_back(text);
    }

    void TextPusher::update()
    {
        if(!textQueue.empty())
        {
            if(textShown.empty() or
               (textShown[readIndex-1]->isTextPrinted() and
                readIndex < textQueue.size()))
            {
                pushAllTexts();
                enforceLineLimit();

                textQueue[readIndex]->setPosition(origin.x, origin.y);
                textShown.push_back(textQueue[readIndex]);

                framesActive = 0;
                readIndex++;
            }

            framesActive++;
            clearAfterTimeLimit();
        }
    }

    void TextPusher::pushAllTexts()
    {
        for(auto text : textShown)
        {
            text->move(0, -14);
        }
    }

    void TextPusher::enforceLineLimit()
    {
        auto lineLimit = 3;

        if(textShown.size() > lineLimit - 1)
        {
            textShown[textShown.size() - lineLimit]->setText(" ");
        }
    }

    void TextPusher::clearAfterTimeLimit()
    {
        if(framesActive > 150)
        {
            clear();

            framesActive = 0;
        }
    }

    void TextPusher::clear()
    {
        for (std::vector<pi::Text*>::iterator it = textShown.begin() ; it != textShown.end(); ++it)
        {
            delete(*it);
        } 

        textShown.clear();
        textQueue.clear();

        readIndex = 0;
    }

    std::vector<pi::Text*> TextPusher::getTexts()
    {
        return textShown;
    }
}