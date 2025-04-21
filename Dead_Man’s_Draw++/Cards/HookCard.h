#ifndef HOOK_CARD_H
#define HOOK_CARD_H

#include "../Card.h"
#include <string>
#include <iostream>
// HookCard is a subclass inherits from the abstract Card class
class HookCard : public Card {
public:
    // Constructor with initialiser list, call the base class Card with CardType::Hook
    HookCard(int v) :
        Card(v, CardType::Hook) {
    }
    // Override all the needed pure virtual method 
    std::string str() const override {
        return "Hook(" + std::to_string(value) + ")";
    }
    void play(Game& game, Player& player) override;
    
};

#endif 
