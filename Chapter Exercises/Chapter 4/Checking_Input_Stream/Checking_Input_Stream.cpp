/*
* Geremy Giles
* Chapter 4, Exercise 2: Checking Input Stream
* Allows the user to enter invalid input, and cleans the input stream to allow for more input.
*/

#include <iostream>

using namespace std;

int main()
{
    // Declaring Variables
    long long int activeNumber = -1;
    bool quit = false;
    bool validInput = false;

    // Inform the user of the rules
    cout << "Welcome to the unbreakable input system!\n - I will ask you for a number, and I won't stop asking until you enter a valid integer." << endl
        << " - If the input contains any characters that aren't valid integers, or if the integer is out of the range of a long long int, I won't crash." << endl
        << "Let's try it out! Enter 'q' at anytime to quit." << endl << endl;

    // Loop until user quits
    while (!quit)
    {
        // Loop to get a number from the user
        while (!validInput)
        {
            // Prompt user for number
            cout << "Enter any integer: " << endl;

            // Quit if needed
            if (cin.peek() == 'q')
            {
                cout << "Qutting..." << endl;
                quit = true;
                //validInput = true;
                break;
            }

            // Try to write to an int
            cin >> activeNumber;

            // Clear input stream if needed
            if (!cin || cin.peek() != '\n') // Check for fail state
            {
                cin.clear(); // Clear fail flag
                cin.ignore(1000, '\n'); // Ignore any other input
                validInput = false; // Set flag to false to loop
            }
            else validInput = true;
        }

        if (validInput)
        {
            cout << "\n\nWe did it! Your valid number is " << activeNumber << ". You can't break me! \n\nLet's go again!! ";

            validInput = false;
        }
    }
}
