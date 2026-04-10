/*
* Geremy Giles
* Chapter 3, Exercise 2: Text Append
* Reads a text file and appends the user's input to the file.
*/

#include <iostream>
#include <fstream> // Read/Write to file
#include <filesystem> // Check for file existence
#include <string> // Use strings

using namespace std;

int main()
{
    // Create variables
    ifstream fileInput;
    ofstream fileOutput;

    string textString;

    // Check if file already exists
    if (std::filesystem::exists("\MyFile.txt"))
    {
        // Open the file
        fileInput.open("\MyFile.txt");

        cout << "File opened" << endl;

        fileInput >> textString;

        cout << textString;

        fileInput.close();
    }
    else
    {
        cout << "No file found, creating new file" << endl;
        fileOutput.open("\MyFile.txt");

        fileOutput << "Created new file";

        fileOutput.close();
    }


    


    // Print the contents

    // Prompt user for input

    // Show appended contents

    // Confirm

    // Close the file
}
