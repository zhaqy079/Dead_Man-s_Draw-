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

// taketurn feature when player1 done, transit to player2 
void Game::takeTurn() {
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
    round = 1; 
    std::cout << "Starting Dead Man's Draw++! " << std::endl;
    while (!deck.empty() && count < TOTAL_TURNS) {
        takeTurn();
    }
    endGame();
}


