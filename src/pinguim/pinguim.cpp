#include "pinguim.h"

namespace tex
{
    sf::Image TextureLoader::getImage(std::string name)
    {
        sf::Image image;

        if (!image.loadFromFile("../../res/" + name))
        {
            image.create(TILE_SIZE, TILE_SIZE, sf::Color::Yellow);
        }

        return image;
    }

    sf::Texture TextureLoader::getTexture(std::string name)
    {
        sf::Texture texture;

        // If unable to load file
        if (!texture.loadFromFile("../../res/" + name))
        {
            // Create default clean texture
            texture.update(new sf::Uint8[TILE_SIZE * TILE_SIZE * 4]);
        }

        auto image = texture.copyToImage();

        // Eliminate transparent pixels from texture
        for(int y = 0; y < texture.getSize().y; y++)
        {
            for(int x = 0; x < texture.getSize().x; x++)
            {
                auto pixel = image.getPixel(x, y);

                //Black is the transparent color
                if(pixel == sf::Color::Black)
                {
                    pixel = sf::Color(0,0,0,0);
                    
                    image.setPixel(x, y, pixel);
                }
            }
        }

        texture.update(image);

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

    sf::Sprite TextureLoader::getTileFromTextureMatrix(sf::Sprite sprite, int row, int cell)
    {
        sprite.setTextureRect(sf::IntRect(
            TILE_SIZE * cell, 
            TILE_SIZE * row, 
            TILE_SIZE, TILE_SIZE));

        return sprite;
    }

    std::vector<unsigned int> TextureLoader::getImageAsVectorStripe(sf::Image image)
    {
        auto _vectorStripe = std::vector<unsigned int>();
        
        for(int vertical = 0; vertical < image.getSize().y; vertical++)
        {
            for(int horizontal = 0; horizontal < image.getSize().x; horizontal++)
            {
                try
                {
                    auto pixelColor = image.getPixel(horizontal,vertical);
                    
                    auto r = pixelColor.r;
                    auto g = pixelColor.g;
                    auto b = pixelColor.b;

                    _vectorStripe.push_back(
                        (r << 16) + (g << 8) + b
                        );
                }
                catch(const std::exception& e)
                {
                    _vectorStripe.push_back(16711680);
                }
            }   
        }    

        return _vectorStripe;    
    }
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
        auto text = std::make_unique<pi::Text>(inputText, sf::Color::White, 12);

        textQueue.push_back(std::move(text));
    }

    void TextPusher::update()
    {
        if(!textQueue.empty())
        {
            if(textShown.empty() or
               (textShown[readIndex-1]->isTextPrinted() and
                readIndex < textQueue.size()))
            {
                moveAllTexts();
                enforceLineLimit();

                textQueue[readIndex]->setPosition(origin.x, origin.y);
                textShown.push_back(std::move(textQueue[readIndex]));

                framesActive = 0;
                
                readIndex++;
            }

            framesActive++;
            clearAfterTimeLimit();
        }
    }

    void TextPusher::moveAllTexts()
    {
        for(auto&& text : textShown)
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

            textShown.erase(textShown.begin());
            textQueue.erase(textQueue.begin());
            readIndex--;
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
        textShown.clear();
        textQueue.clear();

        readIndex = 0;
    }

    std::vector<std::unique_ptr<pi::Text>>& TextPusher::getTexts()
    {
        return textShown;
    }

    /***
     *  Class Texture
     * 
     */
    Texture::Texture()
    {
        textureMap["terrain"] = tex::TextureLoader::getTexture("knd.png");
    }

    sf::Texture Texture::getTexture(std::string name)
    {
        return textureMap[name];
    }
}