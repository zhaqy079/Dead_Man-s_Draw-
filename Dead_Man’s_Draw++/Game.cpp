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
// isBust() detect two card is same or not, if busted, discard all card 
bool Game::isBust() {
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


