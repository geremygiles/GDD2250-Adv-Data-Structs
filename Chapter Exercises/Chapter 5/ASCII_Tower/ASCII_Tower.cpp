/*
* Geremy Giles
* Chapter 5, Exercise 1: ASCII Tower
* With the maximum width and amount of characters provided by the user, build an ASCII tower of a user-defined character.
*/

#include <iostream>
#include <iomanip> // Manipulate spacing

using namespace std;

int main()
{
    // Declaring variables
    bool validInput; // Checks if the user entered a valid input to break loop

    int towerWidth; // The desired width of the base of the tower
    int charCount; // The alloted characters for building the tower

    char artChar; // The character to build the tower with
    
    string finalString = ""; // The string that is built over the loops to be outputted at the end



    // ============== Get User Input ===================

    // Get the character to build the tower with
    validInput = false;
    while (!validInput) // Loop until user enters valid input
    {
        // Prompt user for number
        cout << "Enter the character for the tower to be built with." << endl;

        // Try to write to a char
        cin >> artChar;

        // Clear input stream if needed
        if (!cin || cin.peek() != '\n') // Check for fail state
        {
            cin.clear(); // Clear fail state
            cin.ignore(1000, '\n'); // Ignore any other input
            validInput = false; // Set flag to false to re-loop
        }
        else validInput = true; // Allow continue
    }


    // Get a valid width of the tower
    validInput = false;
    while (!validInput)
    {
        // Prompt user for number
        cout << "Enter an integer for the width of the tower base: " << endl;

        // Try to write to an int
        cin >> towerWidth;

        // Clear input stream if needed
        if (!cin || cin.peek() != '\n') // Check for fail state
        {
            cin.clear(); // Clear fail state
            cin.ignore(1000, '\n'); // Ignore any other input
            validInput = false; // Set flag to false to re-loop
        }
        else validInput = true; // Allow continue
    }


    // Get a valid character count
    validInput = false;
    while (!validInput)
    {
        // Prompt user for number
        cout << "Enter an integer for the amount of characters the tower uses, ensuring it is greater than the width: " << endl;

        // Try to write to an int
        cin >> charCount;

        // Clear input stream if needed
        if (!cin || cin.peek() != '\n') // Check for fail state
        {
            cin.clear(); // Clear fail state
            cin.ignore(1000, '\n'); // Ignore any other input
            validInput = false; // Set flag to false to re-loop
        }
        else validInput = true; // Allow continue
    }

    // Calculate the required amount of layers
    float charsPerSection = charCount / towerWidth;



    // ============= Build Tower =================

    cout << endl << endl;
    // Loop for each section
    for (int section = towerWidth; section > 0; section--)
    {
        // Calculate how many floors are allowed in this section
        float floors = charsPerSection / section;
        floors = round(floors);
        
        // Loop for each floor
        for (int i = 0; i < floors; i++)
        {
            // Add a char until the width matches the section width
            string floor = "";
            for (int j = 0; j < section; j++)
            {
                charCount--;
                if (charCount >= 0)
                {
                    floor = floor + artChar + " "; // Extra space for the odds to fit in the middle of the evens
                }
            }

            // Add spaces to the left of the floor to offset it to the center
            for (int k = 0; k < towerWidth - section; k++)
            {
                floor = " " + floor;
            }

            // Add to string
            finalString = " " + floor + "\n" + finalString;
        }
    }

    // Print tower
    cout << finalString;

}
