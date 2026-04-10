/*
* Geremy Giles
* Chapter 3, Exercise 1
* Accepts input from the user, then alters the input and prints it back to the console.
*/

#include <iostream> // Input/Output
#include <string> // Strings
#include <cctype> // Convert to uppercase chars

using namespace std;

int main()
{
    // Variables

    string input;
    char inputChar;

    // Get User Input

    cout << "Input something fun!" << endl << endl;

    // Add spaces in-between characters
    while (cin.peek() != '\n')
    {
        cin.get(inputChar);
        input = input + inputChar + ' ';
    }

    // Print to console
    cout << input << endl << endl;

    // Clear \n from input stream
    cin.get();
    // Clear input
    input = "";

    // Convert every other character to caps (if applicable)

    cout << "Input something interesting!" << endl << endl;
    

    bool caps = false;

    // Add spaces in-between characters
    
    while (cin.peek() != '\n')
    {
        cin.get(inputChar);

        cout << inputChar << endl;

        if (inputChar > 96 && inputChar < 123) // If lowercase
        {
            if (caps) // Alternating Caps flag
            {
                inputChar -= 32;
            }
            caps = !caps;
        }
        
        input = input + inputChar;
    }

    // Print to console
    cout << input << endl << endl;
}
