/*
* Geremy Giles
* 04/24/2026
* A console version of BlackJack. One player plays against the dealer (the computer).
*/

#include "Output.h"
#include "GameManager.h"

using namespace std;

int main()
{
    // Declaring Variables
    bool quit = false;
    
    // Setting up output
    Output output;

    output.PrintIntro();

    output.PromptRules();

    // Loop until user quits
    while (!quit)
    {
        GameManager gameManager;

        gameManager.StartGame();


        // Prompt the user to play again
        quit = !output.PromptPlayAgain();
    }

    output.PrintOutro();
}

