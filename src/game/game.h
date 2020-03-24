#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "engine.h"
#include "map.h"

class Game: public Page
{
private:
    std::vector<sf::Texture> textures;

    pi::TextPusher textPusher;

    Player active;
public:
    Game();

    void onKeyPressed(sf::Keyboard::Key) override;
    void onKeyReleased(sf::Keyboard::Key) override;
    void update(GameWindow&) override;
    void draw(sf::RenderWindow&) override;
};