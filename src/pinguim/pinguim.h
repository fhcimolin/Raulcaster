#include <SFML/Graphics.hpp>
#include <cmath>

struct Point
{
    int x, y;
};

class TextureLoader
{
public:
    static constexpr auto TILE_SIZE = 64;

    static sf::Texture GetTexture(std::string name);
    
    static sf::Sprite GetTileFromTexture(sf::Sprite sprite, int position);
};

namespace pi
{
    class Text
    {
    private:
        int currentChar;
        int framesSinceTrigger;

        std::string textContent;

        sf::Text text;

        sf::Font font;
    public:
        Text(std::string inputText, sf::Color color, int size);

        void setPosition(float x, float y);

        sf::Text getText();
        sf::Text getTextSpelled(size_t frameDelay);
    };
}