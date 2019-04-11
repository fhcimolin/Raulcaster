#include "engine.h"

GameWindow::GameWindow()
{
    window.create(sf::VideoMode(640, 480), "Raulcastre");

    mainLoop();
}

void GameWindow::loadPage(std::unique_ptr<Page>&& page)
{
    currentPage = std::move(page);
}

void GameWindow::mainLoop()
{
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(event.type == sf::Event::KeyPressed)
            {
                currentPage->onKeyPressed(event.key.code);
            }
        }

        currentPage->update(*this);

        currentPage->draw(window);

        window.display();
    }
}

void GameWindow::dispose()
{
    window.close();
}