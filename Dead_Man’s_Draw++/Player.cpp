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