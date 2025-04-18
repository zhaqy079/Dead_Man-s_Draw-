#ifndef CHEST_CARD_H
#define CHEST_CARD_H

#include "../Card.h"
#include <string>
#include <iostream>
// ChestCard is a subclass inherits from the abstract Card class
class ChestCard : public Card {
public:
    // Constructor with initialiser list, call the base class Card with CardType::Chest
    ChestCard(int v) :
        Card(v, CardType::Chest) {
    }
    // Override all the needed pure virtual method 
    std::string str() const override {
        return "Chest(" + std::to_string(value) + ")";
    }
    void play(Game& game, Player& player) override {
        // Chest card no immediate effect
    }
    void willAddToBank(Game & game, Player & player) override {
        std::cout << "Chest and Key activated" << std::endl;
        
        }

};

#endif 

