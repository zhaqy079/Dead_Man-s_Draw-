#ifndef MERMAID_CARD_H
#define MERMAID_CARD_H

#include "../Card.h"
#include <string>
#include <iostream>
// MermaidCard is a subclass inherits from the abstract Card class
class MermaidCard : public Card {
public:
    // Constructor with initialiser list, call the base class Card with CardType::Mermaid
    MermaidCard(int v) :
        Card(v, CardType::Mermaid) {
    }
    // Override all the needed pure virtual method 
    std::string str() const override {
        return "Mermaid(" + std::to_string(value) + ")";
    }
    void play(Game& game, Player& player) override {
        // Mermaid card no ability bute have higher point value
        std::cout << " No effect but Mermaids are worth more." << std::endl;
    }

};

#endif 
