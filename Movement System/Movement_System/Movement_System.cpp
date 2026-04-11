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
    // The location the player starts the game at
    const int STARTING_X_COORD = 0; 
    const int STARTING_Y_COORD = 0;

    // The max size of the board
    const int MAX_X = 4;
    const int MAX_Y = 4;

    // Declaring variables
    bool quit = false; // Tracks if the player wants to quit
    bool validInput = false; // Tracks if the player has entered a valid input
    string input; // Input stream reads into this var
    char direction; // The first character the user inputs, used to find their intended movement direction

    // Inform the user of the rules
    cout << "Welcome to 2D Movement: The Game!\n - Input your desired direction with wasd, and press enter to confirm." << endl
        << " - If you cannot complete your selected move, or if your input is invalid, you will be reprompted." << endl
        << " - Enter EXIT at any time to end the program." << endl << endl;

    // Initialize Board, set player initial position
    Board board(MAX_Y, MAX_X, STARTING_Y_COORD, STARTING_X_COORD);

    // Game Loop
    while (!quit)
    {
        // Loop to get a valid direction from the user
        while (!validInput)
        {
            // Show current board
            board.PrintBoard();

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

            // Get the first character of the input to find direction
            direction = input[0];

            // Identify desired direction or re-loop if invalid
            switch (direction)
            {
                case 'w': // North movement, up one unit
                    validInput = board.Move(-1, 0);
                    if (!validInput) cout << "You cannot move north right now. Try again!" << endl;
                    break;
                case 'a': // West movement, left one unit
                    validInput = board.Move(0, -1);
                    if (!validInput) cout << "You cannot move west right now. Try again!" << endl;
                    break;
                case 's': // South movement, down one unit
                    validInput = board.Move(1, 0);
                    if (!validInput) cout << "You cannot move south right now. Try again!" << endl;
                    break;
                case 'd': // East movement, right one unit
                    validInput = board.Move(0, 1);
                    if (!validInput) cout << "You cannot move east right now. Try again!" << endl;
                    break;
                default:
                    cout << "Invalid input. Try again!" << endl;
                    validInput = false;
            }
        }

        // Reloop for next input
        validInput = false;

        
    }

    return 0; // End program
}
