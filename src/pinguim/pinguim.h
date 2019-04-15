#include <SFML/Graphics.hpp>
#include <cmath>

constexpr auto TILE_SIZE = 64;

class TextureLoader
{
private:
public:
    static sf::Texture GetTexture(std::string name);
    
    static sf::Sprite GetTileFromTexture(sf::Sprite sprite, int position);
};