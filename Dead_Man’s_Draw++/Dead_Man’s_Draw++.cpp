// Dead_Man’s_Draw++.cpp : Defines the entry point for the application.
//

#include "Dead_Man’s_Draw++.h"
#include "Game.h"
#include <iostream>
#include "game_title.h"

int main()
{
    std::cout << GAME_TITLE << std::endl;
    Game game;
    game.startGame();
    return 0;
}
