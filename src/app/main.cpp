#include "game.h"
#include "map.h"

int main(int argc, char *argv[])
{
    GameWindow game(std::make_unique<Map>());
}