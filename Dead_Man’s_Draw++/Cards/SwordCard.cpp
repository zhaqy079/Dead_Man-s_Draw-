#include "SwordCard.h"
#include "../Game.h"
#include "../Player.h"
#include <iostream>

// Access opponent's bank 
void SwordCard::play(Game& game, Player& player) {
    Player* opponent = (&player == &game.getPlayer1()) ? &game.getPlayer2() : &game.getPlayer1();
    CardCollection& opponentBank = opponent->getBank();
}