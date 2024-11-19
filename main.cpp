#include <iostream>
#include "Game.hpp"
#include "Player.hpp"


int main()
{
    srand(time(0));
    Game game;
    game.run();
    return 0;
}