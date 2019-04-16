#include "game.h"

Game::Game() :
    tileset{TextureLoader::GetTexture("knd.png")},
    textSlow{"Let's give this one a shot, shall we? Also. press 'M' to go to the map!", sf::Color::White, 12},
    textNormal{"Let's give this one a shot, shall we?", sf::Color::White, 12},
    textFast{"Let's give this one a shot, shall we?", sf::Color::White, 12}
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

    textSlow.setPosition(0.0f, 0.0f);
    textNormal.setPosition(0.0f, 14.0f);
    textFast.setPosition(0.0f, 28.0f);

    window.draw(textSlow.getTextSpelled(6));
    window.draw(textNormal.getTextSpelled(12));
    window.draw(textFast.getTextSpelled(30));    
}