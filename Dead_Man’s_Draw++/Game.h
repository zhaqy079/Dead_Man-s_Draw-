#ifndef GAME_H
#define GAME_H 

#include <string>
#include "Player.h"
#include "Card.h"

class Game {
public:
    Game();// Constructor

    void startGame();
    void shuffleDeck(CardCollection& cards);
    void takeTurn();
    bool isBust();
    void endGame();
    int finalScore();

private:
    int round();
    Player player1;
    Player player2;
    Player* currentPlayer;
    CardCollection deck;
    CardCollection discardPile;


};
#endif

