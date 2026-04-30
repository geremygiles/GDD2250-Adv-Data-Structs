/*
* Geremy Giles
* 04/17/2026
* A basic version of a binary search tree. Nodes can be added, removed, printed, and searched for.
*/

#include <iostream>
#include "BinarySearchTree.h"
#include "Node.h"

using namespace std;

int LoopForInput(string promptString, string successString);

int main()
{
	BinarySearchTree bst;

	// Create root
	cout << bst.AddNode(8) << endl;

	// Level 1
	cout << bst.AddNode(4) << endl;
	cout << bst.AddNode(12) << endl;

	// Level 2
	cout << bst.AddNode(2) << endl;
	cout << bst.AddNode(6) << endl;
	cout << bst.AddNode(10) << endl;
	cout << bst.AddNode(14) << endl;

	// Level 3
	cout << bst.AddNode(1) << endl;
	cout << bst.AddNode(3) << endl;
	cout << bst.AddNode(5) << endl;
	cout << bst.AddNode(7) << endl;
	cout << bst.AddNode(9) << endl;
	cout << bst.AddNode(11) << endl;
	cout << bst.AddNode(13) << endl;
	cout << bst.AddNode(15) << endl;

	// Print the tree
	cout << bst.PrintTree() << endl;

	// Prompt the user for a value to remove
    int removeValue = LoopForInput("Enter a value to remove: ", "Attempting to remove the node with the value: ");
    cout << bst.RemoveNode(removeValue) << endl;

	// Re-print the tree
    cout << bst.PrintTree() << endl;

	// Prompt the user to enter a value to search for
    int searchValue = LoopForInput("Enter a value to search for: ", "Searching for node with value: ");
    cout << bst.SearchTree(searchValue) << endl;
}


/// <summary>
/// Loops until the user enters a valid input, then returns that number.
/// </summary>
/// <param name="promptString">The string to prompt the user with.</param>
/// <param name="successString">The string to show when the valid input is entered.</param>
/// <returns>The final entereed value.</returns>
int  LoopForInput(string promptString, string successString)
{
    bool quit = false;
    bool validInput = false;
    int userInput;

    // Loop until user quits
    while (!quit)
    {
        // Loop to get a number from the user
        while (!validInput)
        {
            // Prompt user for number
            cout << promptString;

            // Try to write to an int
            cin >> userInput;

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
            cout << successString << userInput << endl;

            return userInput;
        }
    }
}