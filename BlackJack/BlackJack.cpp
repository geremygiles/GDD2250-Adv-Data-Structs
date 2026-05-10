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

    // Inform the player of the status
    output.PrintGameStart(
        gameManager.GetHandString(gameManager.),
        gameManager.GetHandString(gameManager.));
    
    // Player gets to choose how to proceed
    while (gameManager.IsPlayersTurn())
    {
        cout << gameManager.PlayerDecision(output.PromptDecision()) << endl;
    }

    // Tell player their final hand and value
    output.PrintPlayerSummary(gameManager.GetPlayersHandString(), gameManager.Get);
    
    // Dealer shows upside down card
    gameManager.FlipDealersCard();
    output.PrintFlip(gameManager.GetDealersHandString());

    // Dealer hits until 16(
    while (gameManager.GetShouldDealerHit())
    {
        cout << gameManager.DealerHit() << endl;
    }
}

