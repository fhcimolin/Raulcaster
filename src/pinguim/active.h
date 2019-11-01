#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

namespace pi
{
    class Active
    {
    protected:
        int currentFrame;
        int maxFrame;
        
        bool repeat;

        std::unique_ptr<sf::Sprite> sprite;
    public:
        Active();
        
        virtual void update() = 0;

        virtual std::unique_ptr<sf::Sprite> getSprite() = 0;
    };

    //Leitura: https://stackoverflow.com/a/42734905/9555272
}