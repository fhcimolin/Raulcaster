#include <SFML/Graphics.hpp>
#include "pinguim.h"

class GameWindow;

class Page
{
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
public:
    GameWindow(std::unique_ptr<Page>&&);
    void dispose();
    void mainLoop();
    void loadPage(std::unique_ptr<Page>&&);
};