#include <iostream>
#include "Card.h"
#include "Game.h"
#include <algorithm>
#include <random>

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
        std::cout << currentPlayer->getName() << "'s Play Area: " << std::endl;
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
}
int Game::finalScore() {}


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


