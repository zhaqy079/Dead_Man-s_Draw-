#include <iostream>
#include "Card.h"
#include <algorithm>
#include <random>

// Place the shuffleDeck function from introduction 

void shuffleDeck(CardCollection & cards) { 
    CardCollection shuffleDeck{ cards.begin(), cards.end() }; 
    std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{std::random_device{}() });
    std::copy(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());
}