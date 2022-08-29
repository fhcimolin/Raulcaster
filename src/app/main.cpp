#include "game.h"
#include "map.h"

int main(int argc, char *argv[])
{
    try{
        GameWindow game(std::make_unique<Game>());
    }
    catch(...){
        std::cout << "Erro";
    }
}