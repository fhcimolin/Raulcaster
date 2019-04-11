#include "game.h"

int main(int argc, char *argv[])
{
    GameWindow game;

    game.loadPage(std::make_unique<Game>());
}