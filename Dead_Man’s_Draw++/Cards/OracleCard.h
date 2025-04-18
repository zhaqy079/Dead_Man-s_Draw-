#ifndef ORACLE_CARD_H
#define ORACLE_CARD_H

#include "../Card.h"
#include <string>
#include <iostream>
// OracleCard is a subclass inherits from the abstract Card class
class OracleCard : public Card {
public:
    // Constructor with initialiser list, call the base class Card with CardType::Oracle
    OracleCard(int v) :
        Card(v, CardType::Oracle) {
    }
    // Override all the needed pure virtual method 
    std::string str() const override {
        return "Oracle(" + std::to_string(value) + ")";
    }
    void play(Game& game, Player& player) override {
        // Implement peek the top card of any suit ability at OracleCard.cpp file)    
    }

};

#endif 