#ifndef CARD_H
#define CARD_H

# include <string>

// Define for use as paramter
class Game;
class Player; 

class Card {
public:
    Card(); // Default Constructor.
    enum CardType {Cannon, Chest, Key, Anchor, Sword, Hook,Oracle, Map, Mermaid, Kraken};// Define a enum for the type of card
    const CardType& type() const; // Return card type 
    virtual std::string str() const = 0; // Return card type and its value as string
    virtual void play(Game& game, Player& player) = 0; // Help player play the card ( add or remove) 
    virtual void willAddToBank(Game& game, Player& player) {}; // help when player bank the card

protected:
    int value; 
    CardType cardType;


};
#endif

// Reference: https://learn.microsoft.com/en-us/cpp/cpp/abstract-classes-cp
// https://github.com/extraPaul/CardGame/blob/master/CardGameProject/Card.h