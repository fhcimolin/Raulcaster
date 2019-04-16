#include <SFML/Graphics.hpp>
#include "engine.h"

#include "map.h"

class Game: public Page
{
private:
    sf::Texture tileset;

    pi::Text textSlow;
    pi::Text textNormal;
    pi::Text textFast;
public:
    Game();
    void update(GameWindow&) override;
    void draw(sf::RenderWindow&) override;
};