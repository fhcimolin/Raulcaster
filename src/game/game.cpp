#include "game.h"

Game::Game()
{
    TextureLoader textureLoader;
    
    tileset = textureLoader.GetTexture("../../res/knd.bmp");
}

void Game::update(GameWindow& game)
{
    if(keys[sf::Keyboard::K])
    {
        game.dispose();
    }
}

void Game::draw(sf::RenderWindow& window)
{
    sf::Sprite sprite;

    sprite.setTexture(tileset);

    window.draw(sprite);
}