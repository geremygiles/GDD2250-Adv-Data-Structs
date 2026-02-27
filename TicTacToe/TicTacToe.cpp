/*
* Geremy Giles
* 02/27/2026
* Practice implementation of Tic-Tac-Toe using classes
* 
*/

#include <iostream>
using namespace std;

// Class declarations
class Game
{
private:

    char board[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    bool SinglePlayerGame()
    {
        cout << "Single player game" << endl;

        bool gameOver = false;

        while (!gameOver)
        {
            // Game loop

            PlayerTurn(1);
            
            ShowBoard();

            //ComputerTurn();

            PlayerTurn(1);

            ShowBoard();

            PlayerTurn(1);

            ShowBoard();

            gameOver = true;
        }

        return true;
    }

    bool TwoPlayerGame()
    {
        bool gameOver = false;

        while (!gameOver)
        {
            // Game loop

            PlayerTurn(1);

            ShowBoard();

            gameOver = CheckWin();

            PlayerTurn(2);

            ShowBoard();

            gameOver = CheckWin();
        }

        return false;
    }

    void ShowBoard()
    {
        cout << endl << "Current Board:" << endl;
        cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << endl;
        cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << endl;
        cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << endl << endl;

    }

    void PlayerTurn(int player)
    {
        // Ensure the user inputs a valid number, then break the loop
        int choice = 0;
        while (choice == 0)
        {
            cout << "Please enter the number corresponding to the spot where you would like to put your marker." << endl;
            cout << "1|2|3\n4|5|6\n7|8|9" << endl;

            // Loop until valid number is entered
            int inputtedChoice;
            cin >> inputtedChoice;
            if (inputtedChoice > 0 && inputtedChoice <= 9) // Valid Input
            {
                int rowIndex = (inputtedChoice - 1) / 3;
                int columnIndex = (inputtedChoice - 1) % 3;

                if (board[rowIndex][columnIndex] == ' ')
                {
                    choice = inputtedChoice;
                    board[rowIndex][columnIndex] = player = 1 ? 'O' : 'X';
                }
                else
                {
                    cout << "That location is full. Pick again!" << endl;
                }
            }
            else
            {
                cout << "Invalid input, please try again." << endl;

                // Clear the console if the user has inputted an invalid character
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    bool CheckWin()
    {
        // Row 1
        if (board[0][0] == board[0][1] && board[0][0] == board[0][2]) return true;

        // Row 2 
        if (board[1][0] == board[1][1] && board[1][0] == board[1][2]) return true;

        // Row 3
        if (board[2][0] == board[2][1] && board[2][0] == board[2][2]) return true;

        // Col 1
        if (board[0][0] == board[1][0] && board[0][0] == board[2][0]) return true;

        // Col 2
        if (board[0][1] == board[1][1] && board[0][1] == board[2][1]) return true;

        // Col 3
        if (board[0][2] == board[1][2] && board[0][2] == board[2][2]) return true;

        // Diag 1
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) return true;

        // Diag 2
        if (board[2][0] == board[1][1] && board[2][0] == board[0][2]) return true;
    }

public:

    bool StartGame(int playerCount)
    {
        if (playerCount == 1)
        {
            return SinglePlayerGame();
        }
        else
        {
            return TwoPlayerGame();
        }
    }
};



// Prompts the user for how many players, then calls the corrosponding method in the Game class. This class contains a flag to mark which player has won.
int main()
{
    bool player1Win;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    // Ensure the user inputs a valid number, then break the loop
    int playerCount = 0;
    while (playerCount == 0) 
    {
        cout << "1 or 2 players?" << endl;
        
        // Loop until 1 or 2 is entered
        int inputtedPlayers;
        cin >> inputtedPlayers;
        if (inputtedPlayers == 1 || inputtedPlayers == 2) // Valid Input
        {
            playerCount = inputtedPlayers;
        }
        else
        {
            cout << "Invalid Input, please try again." << endl;

            // Clear the console if the user has inputted an invalid character
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Create game instance
    Game game;

    player1Win = game.StartGame(playerCount);

    cout << "The game is over! ";
    if (player1Win)
    {
        cout << "Player 1 has won!" << endl;
    }
    else
    {
        cout << "Player 2 has won!" << endl;
    }
    
}


