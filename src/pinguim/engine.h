#include <SFML/Graphics.hpp>

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
    GameWindow();
    void dispose();
    void mainLoop();
    void loadPage(std::unique_ptr<Page>&& page);
};