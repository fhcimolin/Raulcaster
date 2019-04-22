#include <SFML/Graphics.hpp>
#include "engine.h"

#include "map.h"

class Game: public Page
{
private:
    sf::Texture tileset;

    pi::Text textSlow;
    // pi::Text textNormal;
    // pi::Text textFast;

    pi::TextPusher textPusher;
public:
    Game();

    void onKeyPressed(sf::Keyboard::Key) override;
    void onKeyReleased(sf::Keyboard::Key) override;
    void update(GameWindow&) override;
    void draw(sf::RenderWindow&) override;
};