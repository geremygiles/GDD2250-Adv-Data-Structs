#include "Output.h"
#include <iostream>

using namespace std;

// Print methods

void Output::PrintHeapIntro()
{
    cout << "Min-Heap Example" << endl << endl;
    cout << "Enter in an array of any size, "
        "then the program will show the unsorted array, "
        "followed by the sorted heap." << endl;
}

void Output::PrintQueueIntro()
{
    cout << "Priority Queue Example" << endl << endl;
    cout << "Enter in an array of any size, "
        "then the program will show the unsorted array, "
        "followed by the sorted heap." << endl;
}

void Output::PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
        if (i < size - 1) cout << ", ";
        else cout << endl;
    }
}


// Prompt methods

int Output::PromptInt(string prompt) const
{
    int userInput;

    // Loop to get an answer from the user
    while (true)
    {
        // Prompt user
        cout << prompt << endl;
        // Try to write to an int
        cin >> userInput;

        // Clear input stream if needed
        if (!cin || cin.peek() != '\n') // Check for fail state
        {
            cin.clear(); // Clear fail flag
            cin.ignore(1000, '\n'); // Ignore any other input
            continue; // Try again
        }

        return userInput;
    }
}