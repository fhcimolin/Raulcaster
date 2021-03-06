#include <SFML/Graphics.hpp>
#include "mapReader.h"
#include "engine.h"

class Map: public Page
{
private:
    float scale;
    
    Point currentPosition;

    sf::Texture tileset;
    
    std::unique_ptr<MapReader> mapReader;
public:
    Map();

    void drawMap(sf::RenderWindow&);

    void onKeyPressed(sf::Keyboard::Key key) override {
        keys[key] = true;
    }
    void onKeyReleased(sf::Keyboard::Key key) override {
        keys[key] = false;
    }
    void update(GameWindow&) override;
    void draw(sf::RenderWindow&) override;
};