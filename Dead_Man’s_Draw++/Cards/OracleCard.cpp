#include "OracleCard.h"
#include "../Game.h"
#include <iostream>

void OracleCard::play(Game& game, Player& player) {
    // Access current deck
    CardCollection& deck = game.getDeck(); 

    // Peek the top card of the deck and process
    
    Card* nextCard = deck.back();
    std::cout << "The Oracle sees a " << nextCard->str() << std::endl;
    
}