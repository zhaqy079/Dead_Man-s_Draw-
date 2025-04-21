#include "CannonCard.h"
#include "../Game.h"
#include "../Player.h"
#include <iostream>

// Access opponent's bank 
// Reference: https://stackoverflow.com/questions/12737637/swap-a-pointer-between-two-objects
void CannonCard::play(Game& game, Player& player) {
    Player* opponent = (&player == &game.getPlayer1()) ? &game.getPlayer2() : &game.getPlayer1();
    CardCollection& opponentBank = opponent->getBank();

    // Find the top card 
    Card* topCard = opponentBank[0];
    int index = 0;
    // Iterate opponent bank 
    for (int i = 1; i < opponentBank.size(); ++i) {
        if (opponentBank[i]->getValue() > topCard->getValue()) {
            topCard = opponentBank[i];
            index = i;
        }
    }
}