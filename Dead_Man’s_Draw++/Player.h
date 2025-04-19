#ifndef PLAYER_H 
#define PLAYER_H 

#include <string>
#include "Card.h"

// Define for use as parameter
class Game;


class Player {
public: 
    Player(); // Default constructor

    std::string getName() const; // const getter method for access private attribute name 
    bool playCard(Card* card, Game& game); // Player's play area for adding or removing cards
    void bankCard();
    int getScore() const;
    int calculateScore() const;
    void printPlayArea() const;
    void printBank() const;
    
private:
    std::string name;
    CardCollection playArea; // using typedef at Card.h
    CardCollection bank;

};
#endif 
