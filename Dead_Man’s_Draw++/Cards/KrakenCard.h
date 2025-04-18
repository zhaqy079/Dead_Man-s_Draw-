#ifndef KRAKEN_CARD_H
#define KRAKEN_CARD_H

#include "../Card.h"
#include <string>
#include <iostream>
// KrakenCard is a subclass inherits from the abstract Card class
class KrakenCard : public Card {
public:
    // Constructor with initialiser list, call the base class Card with CardType::Kraken
    KrakenCard(int v) :
        Card(v, CardType::Kraken) {
    }
    // Override all the needed pure virtual method 
    std::string str() const override {
        return "Kraken(" + std::to_string(value) + ")";
    }
    void play(Game& game, Player& player) override {
        // Implement draw and play three cards consecutively in KrakenCard.cpp file 
    }

};

#endif 
