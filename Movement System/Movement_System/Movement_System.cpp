/*
* Geremy Giles
* Movement System
* Uses a 2D array to represent a board, and allows the user to move freely in all 4 directions around the board.
*/

#include <iostream> // Input/Output access
#include "Board.h" // Access to Board class

using namespace std;

void InitializeBoard();
//void PrintBoard();


int main()
{
    // Constants
    const int STARTING_X_COORD = 0;
    const int STARTING_Y_COORD = 0;
    const int MAX_X = 4;
    const int MAX_Y = 4;

    // Declaring variables
    bool quit = false;
    bool validInput = false;
    string input;
    char direction;

    // Initialize Board, set player initial position
    Board board(MAX_Y, MAX_X, STARTING_Y_COORD, STARTING_X_COORD);

    board.PrintBoard();

    // Game Loop
    while (!quit)
    {
        // Loop to get a number from the user
        while (!validInput)
        {
            // Prompt the user to choose a direction to move
            cout << "Choose a movement direction (w - North, a - West, s - South, d - East)" << endl;
            cin >> input;

            // Quit if needed
            if (input == "EXIT")
            {
                cout << "Exiting..." << endl;
                quit = true;
                break;
            }

            // Clear input stream if needed
            if (!cin || cin.peek() != '\n') // Check for fail state
            {
                cin.clear(); // Clear fail flag
                cin.ignore(1000, '\n'); // Ignore any other input
                validInput = false; // Set flag to false to loop
                continue;
            }
            else validInput = true;

            // Get the first character of the input to find direction
            direction = input[0];

            // Identify desired direction or re-loop
            switch (direction)
            {
                case 'w': // North movement, up one unit
                    validInput = board.Move(-1, 0);
                    break;
                case 'a': // West movement, left one unit
                    validInput = board.Move(0, -1);
                    break;
                case 's': // South movement, down one unit
                    validInput = board.Move(1, 0);
                    break;
                case 'd': // East movement, right one unit
                    validInput = board.Move(0, 1);
                    break;
                default:
                    direction = '\0';
                    input = "";
                    validInput = false;
            }
        }

        // Print Board
        board.PrintBoard();
        validInput = false;
        

        

        
    }


    
    //cout << "___________" << endl;
}
