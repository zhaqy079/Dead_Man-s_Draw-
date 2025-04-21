#ifndef SWORD_CARD_H
#define SWORD_CARD_H

#include "../Card.h"
#include <string>
#include <iostream>
// SwordCard is a subclass inherits from the abstract Card class
class SwordCard : public Card {
public:
    // Constructor with initialiser list, call the base class Card with CardType::Sword
    SwordCard(int v) :
        Card(v, CardType::Sword) {
    }
    // Override all the needed pure virtual method 
    std::string str() const override {
        return "Sword(" + std::to_string(value) + ")";
    }
    void play(Game& game, Player& player) override {}
        // Implement steal the top card of any suit ability at SwordCard.cpp file)    
    

};

#endif 