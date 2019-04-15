#include "game.h"

Game::Game()
{
    TextureLoader textureLoader;
    
    tileset = textureLoader.GetTexture("knd.png");
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

    //Here we go.....

    int maluco = GameWindow::SCREEN_WIDTH;
    // SCREEN_HEIGHT

    //

    window.draw(sprite);
}