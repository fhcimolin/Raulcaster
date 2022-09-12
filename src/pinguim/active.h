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

        static constexpr auto TILE_SIZE = 64;

        sf::Sprite sprite;
        sf::Image image;
        std::vector<unsigned int> activeImage;

        std::vector<animation> animationReel;
    public:
        Active();

        void changeAnimationReel(int);
        void setPosition(int, int);
        void setTexture(sf::Texture*);
        void update();
        
        
        
        
        void setImage(sf::Image);

        std::vector<unsigned int> getActiveImage();

        const sf::Texture* setTexture();

        sf::Sprite getSprite();

        const sf::Texture* getTexture();
    };
}