#include "Output.h"
#include <iostream>

using namespace std;

// Public Methods

void Output::PrintIntro()
{
    cout << "Welcome to BlackJack!\n";
}

void Output::PrintGameStart(string playersHand, string dealersHand)
{
    cout << "------- GAME START!! -------" << endl;
    cout << "The dealer has dealt the cards!" << endl;
    cout << "Your cards: " << playersHand << endl;
    cout << "Dealer's card: " << dealersHand << endl << endl;
}

void Output::PrintOutro()
{
    cout << "Thanks for playing!" << endl;
}

void Output::PrintFlip(string dealersHand)
{
    cout << "The dealer flips over their hidden card. Their hand is " + dealersHand << endl;
}


// Prompting methods
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

int Output::PromptDecision()
{
    return PromptInt(
        "What would you like to do next?"
        "\nPlease select from one of the following:\n"
        "\n1: Hit"
        "\n2: Stand"
        "\n3: Double Down"
        "\n4: Surrender"
        "\n5: Split",
        1, 5);
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

int Output::PromptInt(string prompt, int minValue, int maxValue)
{
    int userInput;

    // Loop to get an answer from the user
    while (true)
    {
        // Prompt user
        cout << prompt << endl;
        cout << "Value must be no less than " << minValue << " and no greater than " << maxValue << endl;
        // Try to write to an int
        cin >> userInput;

        // Clear input stream if needed
        if (!cin || cin.peek() != '\n') // Check for fail state
        {
            cin.clear(); // Clear fail flag
            cin.ignore(1000, '\n'); // Ignore any other input
            continue; // Try again
        }

        if (userInput < minValue || userInput > maxValue) continue; // Out of range, try again

        return userInput;
    }
}