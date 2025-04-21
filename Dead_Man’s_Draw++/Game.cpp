#include <iostream>
#include "Card.h"
#include "Cards/CannonCard.h"
#include "Cards/ChestCard.h"
#include "Cards/KeyCard.h"
#include "Cards/SwordCard.h"
#include "Cards/HookCard.h"
#include "Cards/OracleCard.h"
#include "Cards/MapCard.h"
#include "Cards/MermaidCard.h"
#include "Cards/KrakenCard.h"
#include "Game.h"
#include <algorithm>
#include <random>

Game::Game() {}
// Implement getter method
Player& Game::getPlayer1(){
    return player1;
}
Player& Game::getPlayer2() {
    return player2;
}
Player* Game::getCurrentPlayer() {
    return currentPlayer;
}
CardCollection& Game::getDeck() {
    return deck;
}
CardCollection& Game::getDiscardPile() {
    return discardPile;
}

// Create Deck to generate 54 cards ( 9 types * 6 cards ) 
// Reference: https://codereview.stackexchange.com/questions/254769/deck-of-cards-written-in-c
// https://stackoverflow.com/questions/26952727/i-need-help-generating-a-deck-of-cards-in-c
void Game::makeDeck() {
    // Generate 54 types of card with different value 
    for (int i = 0; i < TYPES; ++i) {
        Card::CardType type = static_cast<Card::CardType>(i);

        for (int j = 0; j < POINT_VALUE; ++j) {
            int value{};
            // Card Mermaid have higher value which is 4,5,6,7,8,9 and others are 2,3,4,5,6,7
            if (i == static_cast<int>(Card::Mermaid)) {
                value = 4 + (j % 6);
            }
            else {
                value = 2 + (j % 6);
            }
            // Let card pointer to the null for storing the new card objects 
            Card* card = nullptr;
            if (type == Card::Cannon) {
                card = new CannonCard(value);
            }
            else if (type == Card::Chest) {
                card = new ChestCard(value);
            }
            else if (type == Card::Key) {
                card = new KeyCard(value);
            }
            else if (type == Card::Sword) {
                card = new SwordCard(value);
            }
            else if (type == Card::Hook) {
                card = new HookCard(value);
            }
            else if (type == Card::Oracle) {
                card = new OracleCard(value);
            }
            else if (type == Card::Map) {
                card = new MapCard(value);
            }
            else if (type == Card::Mermaid) {
                card = new MermaidCard(value);
            }
            else if (type == Card::Kraken) {
                card = new KrakenCard(value);
            }
            if (card != nullptr) {
                deck.push_back(card); // Then add card into the deck
            }
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
        currentPlayer->bankCard();  // Move play area to bank
        
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
        std::cout << "It's a tie!" << std::endl;
    }
}


// Manually set game turn as 10, initial game 
void Game::startGame() {
    makeDeck();
    shuffleDeck(deck);
    currentPlayer = &player1;
    std::cout << "Starting Dead Man's Draw++! " << std::endl;
    while (!deck.empty() && count < TOTAL_TURNS) {
        takeTurn();
    }
    endGame();
}


