#ifndef PLAYER_H 
#define PLAYER_H 

#include <string>
#include "Card.h"

class Player {
public: 
    Player(); // Default constructor
    std::string getName() const; // const getter method for access private attribute name 

private:
    std::string name;
    CardCollection playArea; // using typedef at Card.h
    CardCollection bank;

};
#endif 
