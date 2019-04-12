#include "game.h"

int main(int argc, char *argv[])
{
    GameWindow game(std::make_unique<Game>());
}