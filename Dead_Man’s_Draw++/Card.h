#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>

// Define for use as paramter
class Game;
class Player; 

class Card {
public:
    enum CardType { Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken };// Define a enum for the type of card

    Card(int v, CardType t)
        : value(v), cardType(t) {
    }; // Constructor with initialiser list.
    virtual ~Card() = default;

    virtual const CardType& type() const { return cardType; }; // Return card type 
    int getValue() const { return value; };

    virtual std::string str() const = 0; // Return card type and its value as string
    virtual void play(Game& game, Player& player) = 0; // Help player play the card ( add or remove) 
    virtual void willAddToBank(Game& game, Player& player) {}; // help when player bank the card

protected:
    int value; 
    CardType cardType;

// For easier using std::vector<Card*> 
    typedef std::vector<Card*> CardCollection;
};
#endif

// Reference: https://learn.microsoft.com/en-us/cpp/cpp/abstract-classes-cp
// https://github.com/extraPaul/CardGame/blob/master/CardGameProject/Card.h
// https://www.geeksforgeeks.org/typedef-in-cpp/