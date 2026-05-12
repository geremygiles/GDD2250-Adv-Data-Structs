/*
* Geremy Giles
* 04/24/2026
* A console version of BlackJack. One player plays against the dealer (the computer).
*/

#include <iostream>
#include "Output.h"
#include "GameManager.h"
#include "BlackJack.h"

using namespace std;

// Global access to output to iostream
Output output;

int main()
{
    // Declaring Variables
    bool quit = false;

    output.PrintIntro();

    output.PromptRules();

    // Loop until user quits
    while (!quit)
    {
        Game();

        // Prompt the user to play again
        quit = !output.PromptPlayAgain();
    }

    output.PrintOutro();
}

void Game()
{
    // Set up Game Manager
    GameManager gameManager;

    // Deal 2 cards to player and dealer
    gameManager.DealCards();

    // Set up hand pointers
    std::list<Card*>* playerHand = gameManager.GetHand(true);
    std::list<Card*>* dealerHand = gameManager.GetHand(false);

    // Inform the player of the status
    output.PrintGameStart(
        gameManager.GetHandString(playerHand),
        gameManager.GetHandString(dealerHand));
    
    // Player gets to choose how to proceed
    while (gameManager.IsPlayersTurn())
    {
        cout << gameManager.PlayerDecision(output.PromptDecision()) << endl;
        playerHand = gameManager.GetHand(true);
        gameManager.PlayerBust = gameManager.CheckBust(playerHand);
    }

    // If the player has ace(s), ask them what value they want to use
    //output.PromptAce(gameManager.CheckAce(playerHand));

    // Tell player their final hand and value
    output.PrintPlayerSummary(
        gameManager.GetHandString(playerHand), 
        gameManager.GetHandValue(playerHand));
    
    // Dealer shows upside down card
    gameManager.FlipDealersCard();
    dealerHand = gameManager.GetHand(false);
    output.PrintFlip(gameManager.GetHandString(dealerHand));

    // Dealer hits until 16
    while (gameManager.GetShouldDealerHit())
    {
        cout << gameManager.DealerHit() << endl;
        dealerHand = gameManager.GetHand(false);
        gameManager.DealerBust = gameManager.CheckBust(dealerHand);
    }

    output.PrintDealerSummary(
        gameManager.GetHandString(dealerHand),
        gameManager.GetHandValue(dealerHand));

    output.PrintResults(gameManager.CalculateWin());
}

