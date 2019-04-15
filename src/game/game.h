#include <SFML/Graphics.hpp>
#include "engine.h"

class Game: public Page
{
private:
    sf::Texture tileset;
public:
    Game();
    void update(GameWindow&) override;
    void draw(sf::RenderWindow&) override;
};