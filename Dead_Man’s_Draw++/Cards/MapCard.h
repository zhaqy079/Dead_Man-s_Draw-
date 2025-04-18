#ifndef MAP_CARD_H
#define MAP_CARD_H

#include "../Card.h"
#include <string>
#include <iostream>
// MapCard is a subclass inherits from the abstract Card class
class MapCard : public Card {
public:
    // Constructor with initialiser list, call the base class Card with CardType::Map
    MapCard(int v) :
        Card(v, CardType::Map) {
    }
    // Override all the needed pure virtual method 
    std::string str() const override {
        return "Map(" + std::to_string(value) + ")";
    }
    void play(Game& game, Player& player) override {
        // Implement draw 3 cards from discard pile at MapCard.cpp file)    
    }

};

#endif 
