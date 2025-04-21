#include "SwordCard.h"
#include "../Game.h"
#include "../Player.h"
#include <iostream>

// Access opponent's bank 
void SwordCard::play(Game& game, Player& player) {
    Player* opponent = (&player == &game.getPlayer1()) ? &game.getPlayer2() : &game.getPlayer1();
    CardCollection& opponentBank = opponent->getBank();

// Add empty detection: 
if (opponentBank.empty()) {
    std::cout << "No cards in other player's Bank. Play continues." << std::endl;
    return;
}

// Using for-loop find highest value 
int groupMax[10] = { 0 }; // Total 10 types of card, all initialise to 0 element array, and only one max for each card type
Card* topCards[10] = { nullptr };
// For each card in the bank, check if its the highest of the card type
for (Card* card : opponentBank) {
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
std::cout << "Steal a highest-value card from any of the suits in your Bank: " << std::endl;
for (int i = 0; i < 10; ++i) {
    if (topCards[i] != nullptr) {
        std::cout << "(" << (options + 1) << ") " << topCards[i]->str() << std::endl;
        suitMax[options] = i;
        ++options;
    }
}
// Let player make choice 
int choice;
std::cout << "Which card do you pick? ";
std::cin >> choice;

// Keep play the selected card 
int selectedIndex = suitMax[choice - 1];
Card* selectedCard = topCards[selectedIndex];

// Remove the selected card from the bank before replaying
auto it = std::find(opponentBank.begin(), opponentBank.end(), selectedCard);
if (it != opponentBank.end()) {
    opponentBank.erase(it);
}

std::cout << "\n" << player.getName() << " draws a " << selectedCard->str() << std::endl;

// Replay the selected Card
player.playCard(selectedCard, game);
}
