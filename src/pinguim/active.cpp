#include "active.h"
#include "engine.h"

namespace pi
{
    Active::Active() :
        sprite{sf::Sprite()},
        currentFrame{0},
        currentFrameDelay{0},
        currentReel{0},
        maxFrame{0}
    {
        setPosition(300,300);
    }

    void Active::changeAnimationReel(int reel)
    {
        if(currentReel != reel)
        {
            currentReel = reel;
            currentFrame = 0;
            currentFrameDelay = 0;

            updateTextureCell();
        }
        
        maxFrame = animationReel[currentReel].reelLenght;
    }

    void Active::setPosition(int _x, int _y)
    {
        x = _x;
        y = _y;

        sprite.setPosition(_x, _y);
    }

    void Active::setImage(sf::Image _image)
    {
        image = _image;
    }

    std::vector<unsigned int> Active::getActiveImage()
    {
        auto pixelsPtr = image.getPixelsPtr();

        auto readOffset = (((currentReel * TILE_SIZE) * image.getSize().x) + (currentFrame * TILE_SIZE)) * 4;

        activeImage.clear();

        for(int vertical = 0; vertical < TILE_SIZE; vertical++)
        {
            for(int horizontal = 0; horizontal < TILE_SIZE; horizontal++)
            {
                auto r = pixelsPtr[readOffset + ((((vertical * image.getSize().x) + horizontal) * 4))];
                auto g = pixelsPtr[readOffset + ((((vertical * image.getSize().x) + horizontal) * 4)) + 1];
                auto b = pixelsPtr[readOffset + ((((vertical * image.getSize().x) + horizontal) * 4)) + 2];

                activeImage.push_back
                (
                    (r << 16) + (g << 8) + b
                );
            }
        }

        return activeImage;
    }

     void Active::setTexture(sf::Texture* texture)
    {
        sprite.setTexture(*texture);

        updateTextureCell();
    }

    void Active::updateTextureCell()
    {
        try {
            sprite = tex::TextureLoader::getTileFromTextureMatrix(sprite, currentReel, currentFrame);
        }
        catch (int n) {
            std::cout << "Could not load tile from texture for active. Code: " << n;
        }
    }

    void Active::update()
    {
        currentFrameDelay++;

        if(currentFrameDelay <= animationReel[currentReel].speed ||
           animationReel[currentReel].speed == 0)
        {
            return;
        }
        
        currentFrameDelay = 0;
        currentFrame++;

        if(currentFrame == maxFrame)
        {
            currentFrame = 0;
        }
        
        updateTextureCell();
    }

    sf::Sprite Active::getSprite()
    {
        return sprite;
    }

    const sf::Texture* Active::getTexture()
    {
        return sprite.getTexture();
    }
}