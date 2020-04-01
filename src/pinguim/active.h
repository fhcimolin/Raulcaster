#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

namespace pi
{
    struct animation
    {
        int reelLenght;
        int speed;
    };

    class Active
    {
    private:
        void updateTextureCell();
        
        virtual void initializeAnimationReel() = 0;
        
        int currentFrameDelay;
        int currentFrame;
        int maxFrame;
    protected:
        int currentReel;
        
        int x;
        int y;

        sf::Sprite sprite;

        std::vector<animation> animationReel;
    public:
        Active();

        void changeAnimationReel(int);
        void setPosition(int, int);
        void setTexture(sf::Texture*);
        void update();

        sf::Sprite getSprite();
    };
}