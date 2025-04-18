#ifndef CANNON_CARD_H
#define CANNON_CARD_H

#include "../Card.h"
#include <string>
#include <iostream>
// CannonCard is a subclass inherits from the abstract Card class
class CannonCard : public Card {
public: 
// Constructor with initialiser list, call the base class Card with CardType::Cannon
    CannonCard(int v) :
        Card(v, CardType::Cannon) {
    }
// Override all the needed pure virtual method 
    std::string str() const override {
        return "Cannon(" + std::to_string(value) + ")";
    }
    void play(Game& game, Player& player) override {
        // Implement discard the top card of any suit ability at CannonCard.cpp file)    
    }

};

#endif 
