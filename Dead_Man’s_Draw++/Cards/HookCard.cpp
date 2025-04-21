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
    int groupMax[10] = { 0 }; // Total 10 types of card, all initialise to 0 element array, and only one max for each card type
    Card* topCards[10] = { nullptr };
    // For each card in the bank, check if its the highest of the card type
    for (Card* card : bank) {
        int index = static_cast<int>(card->type());
        int value = card->getValue();

        if (value > groupMax[index]) {
            groupMax[index] = value;
            topCards[index] = card;
        }
    }
    // Loop each suit of highest value card
    int suitMax[10] = { 0 };
    int options = 0;
    std::cout << "Select a highest-value card from any of the suits in your Bank: "<< std::endl;
    for (int i = 0; i < 10; ++i) {
        if (topCards[i] != nullptr) {
            std::cout << "(" << (options + 1) << ") " << topCards[i]->str() << std::endl;
            suitMax[options] = i;
            ++options;
        }
    }
}