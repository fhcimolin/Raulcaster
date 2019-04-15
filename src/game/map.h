#include <SFML/Graphics.hpp>
#include "engine.h"

class Map: public Page
{
private:
    sf::Texture tileset;

    float scale;
public:
    Map();

    void setScale(float factor);

    void update(GameWindow&) override;
    void draw(sf::RenderWindow&) override;
};