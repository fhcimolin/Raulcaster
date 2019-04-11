#include "game.h"

void Game::update(GameWindow& game)
{
    if(keys[sf::Keyboard::K])
    {
        game.dispose();
    }
}

void Game::draw(sf::RenderWindow& window)
{
    
}