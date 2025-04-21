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
            std::cout << "BUST! " << name << "loses all cards in play area." << std::endl;
            return true; // Return true when causes bust
        }
    }
    // Otherwise performed card ability, added to playArea, and return false 
    playArea.push_back(card);
    card->play(game, *this); // pass current game and player object reference to achieve related card ability
    return false;

}
//  Implement print bank card feature, print all cards in the player's bank
void Player::printBank() const {
   // std::cout << name << "'s Bank: " << std::endl;
    for (Card* c : bank) {
        std::cout << c->str() << std::endl;
    }
}


// Implement bankCard feature move all cards from playArea to bank 
// Reference: https://www.geeksforgeeks.org/vector-insert-function-in-cpp-stl/
void Player::bankCard() {
    bank.insert(bank.end(), playArea.begin(), playArea.end());
    // Clear playArea before next turn
    playArea.clear();
}

// Implement calculateScore feature, return the sum of the value of the highest card in each suit
// Reference: https://cplusplus.com/forum/general/101832/
int Player::calculateScore() const {
    int groupMax[10] = {0}; // Total 10 types of card, all initialise to 0 element array, and only one max for each card type
    // For each card in the bank, check if its the highest of the card type
    for (Card* card : bank) {
        int index = static_cast<int>(card->type());
        int value = card->getValue();

        if (value > groupMax[index]) {
            groupMax[index] = value;
        }
    }

    // Add all highest values together  
        int total = 0;
        for (int i = 0; i < 10; ++i) {
            total += groupMax[i];
        }

        return total;
}

// Get the Score
int Player::getScore() const {
    return calculateScore();
}

//  Implement print play area feature
void Player::printPlayArea() const {
   // std::cout << name << "'s PlayArea: " << std::endl;
    for (Card* c : playArea) {
        std::cout << c->str() << std::endl;
    }
}