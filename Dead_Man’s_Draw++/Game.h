#ifndef GAME_H
#define GAME_H 

#include <string>
#include "Player.h"
#include "Card.h"

class Game {
public:
    Game();// Constructor

    void startGame();
    void makeDeck();
    void shuffleDeck(CardCollection& cards);
    void takeTurn();
    //bool isBust();
    void endGame();
    //int finalScore();
    // getter method for achieving card ability 
    Player& getPlayer1();
    Player& getPlayer2();
    Player* getCurrentPlayer();
    CardCollection& getDeck();
    CardCollection& getDiscardPile();

private:
    int count = 0;
    const int TOTAL_TURNS = 10;
    const int TYPES = 9;
    const int POINT_VALUE = 6;
    Player player1;
    Player player2;
    Player* currentPlayer;
    CardCollection deck;
    CardCollection discardPile;


};
#endif

