#include "active.h"

namespace pi
{
    Active::Active() :
        sprite{std::make_unique<sf::Sprite>()}
    {
    }

    // std::unique_ptr<sf::Sprite> Active::getSprite()
    // {
    //     return sprite;
    // }
}