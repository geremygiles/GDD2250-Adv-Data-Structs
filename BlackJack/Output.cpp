#include "Output.h"
#include <iostream>

using namespace std;

// Public Methods

void Output::PrintIntro()
{
    cout << "Welcome to BlackJack!\n";
}

void Output::PromptRules()
{
    if (PromptYN("Would you like to hear the rules? y/n"))
    {
        cout << "Rules: " << endl;
    }
}

bool Output::PromptPlayAgain()
{
    return PromptYN("Would you like to play again? y/n");
}

void Output::PrintGameStart()
{
    //cout << 
}



void Output::PrintOutro()
{
    cout << "Thanks for playing!" << endl;
}

// Private Methods

bool Output::PromptYN(string prompt)
{
    char userInput;

    // Loop to get an answer from the user
    while (true)
    {
        // Prompt user
        cout << prompt << endl;
        cin >> userInput;

        // Yes or no
        if (userInput == 'y') return true;
        else if (userInput == 'n') return false;
        else
        {
            cin.clear(); // Clear fail flag
            cin.ignore(1000, '\n'); // Ignore any other input
        }
    }
}