#include "Game.hpp"
#include <iostream>

Game *game = nullptr;

int main(int argc, char const *argv[])
{
    game = new Game();

    while(game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    return 0;
}
