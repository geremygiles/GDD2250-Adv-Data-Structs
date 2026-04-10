/*
* Geremy Giles
* Chapter 3, Exercise 1
* Accepts input from the user, then alters the input and prints it back to the console.
*/

#include <iostream> // Input/Output
#include <string> // Strings

using namespace std;

int main()
{
    // Variables

    string input;
    char inputChar;

    // Get User Input

    cout << "Input something fun!" << endl << endl;

    // Add spaces in-between characters
    cin.get(inputChar);
    input += " " + inputChar;

    // Print to console
    cout << input;

    // Convert every other character to caps (if applicable)
}
