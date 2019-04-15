#include "game.h"

Game::Game() :
    tileset{TextureLoader::GetTexture("knd.png")}
{
}

void Game::update(GameWindow& game)
{
    if(keys[sf::Keyboard::Escape])
    {
        game.dispose();
    }

    if(keys[sf::Keyboard::M])
    {
        game.loadPage(std::make_unique<Map>());
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