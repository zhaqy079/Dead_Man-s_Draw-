#include <iostream>
#include "Card.h"
#include "Game.h"
#include <algorithm>
#include <random>

// Create Deck to generate 54 types of card ( 9 * 6 ) 
// Reference: https://codereview.stackexchange.com/questions/254769/deck-of-cards-written-in-c
// https://stackoverflow.com/questions/26952727/i-need-help-generating-a-deck-of-cards-in-c
void Game::makeDeck() {
    // Generate 54 types of card with different value 
    for (int i = 0; i < TYPES; ++i) {
        for (int j = 0; j < POINT_VALUE; ++j) {
            int value{};
            if (i == static_cast<int>(Card::Mermaid)) {
                value = 4 + (POINT_VALUE % 6);
            }
            else {
                value = 2 + (POINT_VALUE % 6);
            }
            // Let card pointer to the null 
        }
    }

}
// Place the shuffleDeck function from introduction 
void Game::shuffleDeck(CardCollection& cards) {
    CardCollection shuffleDeck{ cards.begin(), cards.end() }; 
    std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{std::random_device{}() });
    std::copy(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());
}

// Display the turns, current bank and score info
void Game::takeTurn() {
    std::cout << "--- Round " << (count / 2) + 1 << ", Turn " << (count + 1) << " ---" << std::endl;
    std::cout << currentPlayer->getName() << "'s turn." << std::endl;

    std::cout << currentPlayer->getName() << "'s Bank: " << std::endl;
    currentPlayer->printBank();
    std::cout << "| Score: " << currentPlayer->getScore() << std::endl;

    // Create a pointer for drawn Card, which point to the last card in the CardCollocetion
    // Reference: https://stackoverflow.com/questions/36748657/using-pop-back-within-a-public-method-but-once-i-exit-that-method-the-vector
    Card* drawnACard = deck.back();
    deck.pop_back();

    std::cout << currentPlayer->getName() << " draws a " << drawnACard->str() << std::endl;

    bool checkBusted = currentPlayer->playCard(drawnACard, *this);

    if (!checkBusted) {
        std::cout << currentPlayer->getName() << " 's Play Area: " << std::endl;
        currentPlayer->printPlayArea();

        // Game continus 
        std::string choice;
        std::cout << "Draw again? (y/n): ";
        std::cin >> choice;

        if (choice == "y") {
            return;
        }
        else {
            currentPlayer->bankCard();  // Move play area to bank
        }

        // Switch player after turn ends
        // Reference: https://stackoverflow.com/questions/12737637/swap-a-pointer-between-two-objects
        currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
        count++;

    }
}
// end game show final score 
void Game::endGame() {
    std::cout << "--- Game Over --- " << std::endl;
    std::cout << player1.getName() << "'s Bank: " << std::endl;
    player1.printBank();
    std::cout <<  "\n| Score: " << player1.getScore() << std::endl;
    std::cout << player2.getName() << "'s Bank: " << std::endl;
    player2.printBank();
    std::cout << "\n| Score: " << player2.getScore() << std::endl;

    // Display the winner 
    if (player1.getScore() > player2.getScore()) {
        std::cout << player1.getName() << " wins!" << std::endl;
    }
    else if (player1.getScore() < player2.getScore()) {
        std::cout << player2.getName() << " wins!" << std::endl;
    }
    else {
        std::cout << "There's a tie!" << std::endl;
    }
}




// Manually set game turn as 10, initial game 
void Game::startGame() {
    shuffleDeck(deck);
    currentPlayer = &player1;
    std::cout << "Starting Dead Man's Draw++! " << std::endl;
    while (!deck.empty() && count < TOTAL_TURNS) {
        takeTurn();
    }
    endGame();
}


