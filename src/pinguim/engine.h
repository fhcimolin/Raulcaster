#pragma once

#include <SFML/Graphics.hpp>
#include "pinguim.h"
#include <memory>

class GameWindow;

class Page
{
private:
protected:
    std::map<sf::Keyboard::Key, bool> keys;
public:
    virtual void onKeyPressed(sf::Keyboard::Key) = 0;
    virtual void onKeyReleased(sf::Keyboard::Key) = 0;
    virtual void update(GameWindow&) = 0;
    virtual void draw(sf::RenderWindow&) = 0;
};

class GameWindow
{
private:
    sf::RenderWindow window;
    std::unique_ptr<Page> currentPage = nullptr;
    
    void mainLoop();
public:
    GameWindow(std::unique_ptr<Page>&&);
    void dispose();
    void loadPage(std::unique_ptr<Page>&&);
};