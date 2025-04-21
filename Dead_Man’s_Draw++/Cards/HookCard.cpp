#include "HookCard.h"
#include "../Game.h"
#include "../Player.h"
#include <iostream>

void HookCard::play(Game& game, Player& player) {
    // Access current bank
    CardCollection& bank = player.getBank();

    // Add empty detection: 
    if (bank.empty()) {
        std::cout << "No cards in your Bank. Play continues" << std::endl;
        return;
    }

    // Using for-loop find highest value 
  
}