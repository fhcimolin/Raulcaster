#include <SFML/Graphics.hpp>
#include <cmath>

struct Point
{
    int x, y;
};

class TextureLoader
{
private:
public:
    static sf::Texture GetTexture(std::string name);
    
    static sf::Sprite GetTileFromTexture(sf::Sprite sprite, int position);

    static constexpr auto TILE_SIZE = 64;
};