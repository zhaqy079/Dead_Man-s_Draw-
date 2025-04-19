#include <iostream>
#include "Player.h"
#include <cstdlib>

// Implement selecting the name for the player
Player::Player() {
    std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
    name = names[rand() % 10];
}

// Return players' name 
std::string Player::getName() const {
    return name;
}

// Implement playCard function adds a card to the play area and remove it from the deck 
// Reference: https://en.cppreference.com/w/cpp/language/range-for
bool Player::playCard(Card* card, Game& game) {
    for (Card* c : playArea) { // Loop through each card pointer in the playArea vector
        if (c->type() == card->type()) { // Compare exist card and new get card type
            std::cout << "BUST!" << name << "loses all cards in play area." << std::endl;
            return true; // Return true when causes bust
        }
    }
    // Otherwise performed card ability, added to playArea, and return false 
    playArea.push_back(card);
    card->play(game, *this); // pass current game and player object reference to achieve related card ability
    return false;

}