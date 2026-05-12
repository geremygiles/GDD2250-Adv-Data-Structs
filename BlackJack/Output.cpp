#include "Output.h"
#include <iostream>

using namespace std;

// Public Methods

void Output::PrintIntro() const
{
    cout << "Welcome to BlackJack!\n";
}

void Output::PrintGameStart(string playersHand, string dealersHand) const
{
    cout << "------- GAME START!! -------" << endl;
    cout << "The dealer has dealt the cards!" << endl;
    cout << "Your cards: " << playersHand << endl;
    cout << "Dealer's card: " << dealersHand << endl << endl;
}

void Output::PrintFlip(string dealersHand) const
{
    cout << "The dealer flips over their hidden card. Their hand is " + dealersHand << endl;
}

void Output::PrintPlayerSummary(std::string hand, int value) const
{
    cout << "Your turn is over. Your final hand is: " << hand << endl;
    cout << "Your cards add up to " << value << endl;
}

void Output::PrintDealerSummary(std::string hand, int value) const
{
    cout << "The dealer's turn is over. Their final hand is: " << hand << endl;
    cout << "Their cards add up to " << value << endl;
}

void Output::PrintResults(int results) const
{
    switch (results)
    {
    case 0: // Lose
        cout << "The dealer has won! You lost TODO." << endl;
        break;
    case 1: // Tie
        cout << "You tied with the dealer! You got TODO back." << endl;
        break;
    case 2: // Win
        cout << "You won! You got TODO back." << endl;
        break;
    default:
        break;
    }
}

void Output::PrintOutro() const
{
    cout << "Thanks for playing!" << endl;
}



// Prompting methods
void Output::PromptRules() const
{
    if (PromptYN("Would you like to hear the rules? y/n"))
    {
        cout << "Blackjack Rules:\n"
                "1. Aim for a hand total closer to 21 than the dealer without going over.\n"
                "2. 2-10 = face value; J,Q,K = 10; Ace = 1.\n"
                "3. Player options: Hit (take card), Stand (keep total).\n"
                "4. Dealer must hit until reaching 17+.\n"
                "5. Exceeding 21 is an automatic loss." << endl;
    }
}

bool Output::PromptPlayAgain() const
{
    return PromptYN("Would you like to play again? y/n");
}

int Output::PromptDecision() const
{
    return PromptInt(
        "What would you like to do next?"
        "\nPlease select from one of the following:\n"
        "\n1: Hit"
        "\n2: Stand",
        //"\n3: Double Down"
        //"\n4: Surrender"
        //"\n5: Split",
        1, 2);
}

// Private Methods

bool Output::PromptYN(string prompt) const
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

int Output::PromptInt(string prompt, int minValue, int maxValue) const
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