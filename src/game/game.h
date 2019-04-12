#include <SFML/Graphics.hpp>
#include "engine.h"

class Game: public Page
{
private:
    std::map<sf::Keyboard::Key, bool> keys;
    sf::Texture tileset;
public:
    Game();
    void onKeyPressed(sf::Keyboard::Key key) override {
        keys[key] = true;
    }
    void onKeyReleased(sf::Keyboard::Key key) override {
        keys[key] = false;
    }
    void update(GameWindow&) override;
    void draw(sf::RenderWindow&) override;
};