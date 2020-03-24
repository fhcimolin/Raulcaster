#include "game.h"

Game::Game() :
    textures{},
    textPusher{},
    active{Player()}
{
    textPusher.sendText("lorem ipsum dolor sit amet");
    textPusher.sendText("adipiscing elit consectetur");
    textPusher.sendText("socorram me subi no");
    textPusher.sendText("onibus em marrocos");
    textPusher.sendText("quem com ferro fere com ferro etc");

    textPusher.setOrigin(100, 100);

    std::unique_ptr<Player> player = std::make_unique<Player>();

    textures.push_back(tex::TextureLoader::getTexture("char.png"));

    active.setTexture(&textures[0]);
}

void Game::onKeyPressed(sf::Keyboard::Key key) 
{
    if(key == sf::Keyboard::P)
    {
        textPusher.sendText("cachorros em bando de 4 cachorros");
    }

    keys[key] = true;
}

void Game::onKeyReleased(sf::Keyboard::Key key) 
{
    keys[key] = false;
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

    textPusher.update();
    
    if(keys[sf::Keyboard::Z])
    {
        active.run();
    }
    else
    {
        active.stop();
    }

    active.update();
}

void Game::draw(sf::RenderWindow& window)
{
    // sf::Sprite sprite;

    // sprite.setTexture(tileset);

    //textSlow.setPosition(0.0f, 0.0f);
    // textNormal.setPosition(0.0f, 14.0f);
    // textFast.setPosition(0.0f, 28.0f);

    //window.draw(textSlow.getTextSpelled(3));
    // window.draw(textNormal.getTextSpelled(2));
    // window.draw(textFast.getTextSpelled(1));

    for(auto text : textPusher.getTexts())
    {
        window.draw(text->getTextSpelled(1));
    }

    window.draw(active.getSprite());
}