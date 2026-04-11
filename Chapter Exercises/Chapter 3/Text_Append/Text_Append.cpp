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
    string tempString;

    // Check if file already exists
    if (std::filesystem::exists("\MyFile.txt"))
    {
        // Open the file
        fileInput.open("\MyFile.txt");
        cout << "File opened successfully!" << endl;

        // Print the contents
        cout << "File Contents:" << endl << endl;

        
        while (fileInput.peek() != EOF) // Read to end of file
        {
            tempString = fileInput.get(); // Get all chars, including whitespace and new lines

            textString = textString + tempString; // Write the files to a string
        }

        cout << textString << endl << endl; // Show file contents


        // Prompt user for input
        cout << "Write what would you would like to append to the file, then press enter." << endl << endl;
        getline(cin, tempString);

        tempString = '\n' + tempString; // Add a new line before input.

        textString = textString + tempString; // Add input to text string


        // Show appended contents
        cout << endl << "New Contents: " << endl << endl << textString << endl << endl;

        // Prompt for Confirm
        cout << "Do you want to save? y/n" << endl;
        tempString = cin.get();

        if (tempString == "y")
        {
            fileOutput.open("\MyFile.txt");
            fileOutput << textString;
            cout << "Saved! Closing File...";
        }
        else if (tempString == "n")
        {
            cout << "Cancelling and closing file...";
        }
        else
        {
            cout << "Invalid input. Closing file.";
        }

        fileInput.close();
    }
    else
    {
        cout << "No file found, creating new file" << endl;
        fileOutput.open("\MyFile.txt");

        // Prompt user for input
        cout << "Write what would you would like to append to the file, then press enter." << endl << endl;
        getline(cin, textString);

        // Show appended contents
        cout << endl << "New Contents: " << endl << endl << textString << endl << endl;


        // Prompt for Confirm
        cout << "Do you want to save? y/n" << endl;
        tempString = cin.get();

        if (tempString == "y")
        {
            fileOutput << textString;
            cout << "Saved! Closing File...";
        }
        else if (tempString == "n")
        {
            cout << "Cancelling and closing file...";
        }
        else
        {
            cout << "Invalid input. Closing file.";
        }

        fileOutput.close();
    }


    


    

    

    

    // Close the file
}
