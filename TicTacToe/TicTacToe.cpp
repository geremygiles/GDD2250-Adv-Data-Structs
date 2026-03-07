/*
* Geremy Giles
* 02/27/2026
* Practice implementation of Tic-Tac-Toe using classes, 2D arrays, and libraries.
*/

#include <iostream>
#include <cstdlib> // Allows the computer to randomly select moves
#include <ctime> // Allows seeding the current time for random
using namespace std;

// Class declarations
class Game
{
public:

    /// <summary>
    /// The method to start the correct game loop, depending on the amount of players.
    /// </summary>
    /// <param name="playerCount">The amount of players in this game.</param>
    /// <returns>Whether player 1 won or not.</returns>
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

    bool GameTie = false;

private:

    // The board that is referenced throughout the game
    char board[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    // Whether player one has won the game or not
    bool player1Win = false;

    /// <summary>
    /// The game logic for a single player game against a computer. Turns will alternate between the player and the computer.
    /// </summary>
    /// <returns>Whether player 1 won or not. If so, returns true.</returns>
    bool SinglePlayerGame()
    {
        cout << "Single player game" << endl;

        bool gameOver = false;
        while (!gameOver)
        {
            // Game loop

            PlayerTurn(1);

            ShowBoard();

            // If player 1 has won, break the loop here.
            gameOver = CheckWin();
            if (gameOver) return player1Win;

            ComputerTurn();

            ShowBoard();

            gameOver = CheckWin();

        }

        // Once the game is over, return whether player 1 has won or not.
        return player1Win;
    }

    /// <summary>
    /// The game logic for a two player game. Turns will alternate between the two players.
    /// </summary>
    /// <returns>Whether player 1 won or not. If so, returns true.</returns>
    bool TwoPlayerGame()
    {
        bool gameOver = false;

        while (!gameOver)
        {
            // Game loop

            PlayerTurn(1);

            ShowBoard();

            // If player 1 has won, break the loop here.
            gameOver = CheckWin();
            if (gameOver) return player1Win;

            PlayerTurn(2);

            ShowBoard();

            gameOver = CheckWin();
        }

        // Once the game is over, return whether player 1 has won or not.
        return player1Win;
    }

    /// <summary>
    /// Outputs the current board to the console, formatted to look like an actual Tic-Tac-Toe board.
    /// </summary>
    void ShowBoard()
    {
        cout << endl << "Current Board:" << endl;
        cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << endl;
        cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << endl;
        cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << endl << endl;

    }

    /// <summary>
    /// Continously prompts the player to choose a location for their move. 
    /// Once a valid location has been chosen, the corresponding symbol is placed there.
    /// </summary>
    /// <param name="player">Which player's turn it is. Either 1 or 2</param>
    void PlayerTurn(int player)
    {
        // Ensure the user inputs a valid number, then break the loop
        int choice = 0;
        while (choice == 0)
        {
            // Prompt the player to make a choice.
            cout << "Player " << player << ": ";
            cout << "Please enter the number corresponding to the spot where you would like to put your marker." << endl;

            // Show them a representation of which spot each number lines up with.
            cout << "1|2|3\n4|5|6\n7|8|9" << endl;

            // Loop until valid number is entered
            int inputtedChoice;
            cin >> inputtedChoice;
            if (inputtedChoice > 0 && inputtedChoice <= 9) // Valid Input
            {
                // Based on the player's input, calculate the corresponding row and column in the 2D matrix.
                int rowIndex = (inputtedChoice - 1) / 3;
                int columnIndex = (inputtedChoice - 1) % 3;

                // Check to make sure the chosen spot is empty.
                if (board[rowIndex][columnIndex] == ' ')
                {
                    choice = inputtedChoice;

                    // Place the correct symbol, with player 1 being 'O', and player 2 being 'X'.
                    board[rowIndex][columnIndex] = player == 1 ? 'O' : 'X';
                }
                else // Chosen spot is already full
                {
                    // Reprompt the user
                    cout << "That location is full. Pick again!" << endl;
                }
            }
            else
            {
                cout << "Invalid input, please try again." << endl;

                // Clear the console just in case the user has inputted an invalid character
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    /// <summary>
    /// Randomly picks spots on the board until an empty one is found. Then, puts the computer's 'X' marker on it.
    /// </summary>
    void ComputerTurn()
    {
        cout << "Computer's Turn:" << endl;

        // Ensure the computer chooses a valid spot, then break the loop
        int choice = -1;
        while (choice == -1)
        {
            // Loop until valid number is entered
            int randomChoice = rand() % 9; // Get random int, from 0 to 8

            // Calculate the corresponding row and column in the 2D matrix.
            int rowIndex = randomChoice / 3;
            int columnIndex = randomChoice % 3;

            // Check to make sure the chosen spot is empty.
            if (board[rowIndex][columnIndex] == ' ')
            {
                choice = randomChoice;
                board[rowIndex][columnIndex] = 'X'; // Computer will always be X
                cout << "The computer has chosen spot " << randomChoice + 1 << endl;
            }
        }
    }

    /// <summary>
    /// Check if either player has won the game by iterating through the possible 8 win conditions.
    /// If player 1 has won, update the field to reflect this.
    /// </summary>
    /// <returns>Whether either player has won or not.</returns>
    bool CheckWin()
    {
        // Row 1
        if (board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][0] == board[0][2])
        {
            player1Win = board[0][0] == 'O' ? true : false;
            return true;
        }

        // Row 2 
        else if (board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][0] == board[1][2])
        {
            player1Win = board[1][0] == 'O' ? true : false;
            return true;
        }
            

        // Row 3
        else if (board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][0] == board[2][2])
        {
            player1Win = board[2][0] == 'O' ? true : false;
            return true;
        }

        // Col 1
        else if (board[0][0] != ' ' && board[0][0] == board[1][0] && board[0][0] == board[2][0])
        {
            player1Win = board[0][0] == 'O' ? true : false;
            return true;
        }

        // Col 2
        else if (board[0][1] != ' ' && board[0][1] == board[1][1] && board[0][1] == board[2][1])
        {
            player1Win = board[0][1] == 'O' ? true : false;
            return true;
        }

        // Col 3
        else if (board[0][2] != ' ' && board[0][2] == board[1][2] && board[0][2] == board[2][2])
        {
            player1Win = board[0][2] == 'O' ? true : false;
            return true;
        }

        // Diag 1
        else if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            player1Win = board[0][0] == 'O' ? true : false;
            return true;
        }

        // Diag 2
        else if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[2][0] == board[0][2])
        {
            player1Win = board[2][0] == 'O' ? true : false;
            return true;
        }


        // No win conditions found
        else
        {
            // Check for tie
            bool spotRemaining = false; // Tracks if there is an empty spot remaining
            for (int i = 0; i < 3; i++) // Interate the rows
            {
                for (int j = 0; j < 3; j++) // Iterate the columns
                {
                    if (board[i][j] == ' ') spotRemaining = true; // There is a possible move left
                }
            }
            if (!spotRemaining) // No possible spots left, but also no win
            {
                GameTie = true;
                return true;
            }
            else return false; // No win or tie detected, continue normal play
        }
    }


};



// Prompts the user for how many players, then calls the StartGame method in the Game class. This class also contains a flag to mark which player has won.
int main()
{
    bool player1Win;

    // Seed the random with current time
    srand(time(0));

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
        else // Invalid input
        {
            cout << "Invalid Input, please try again." << endl;

            // Clear the console if the user has inputted an invalid character
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Create game instance
    Game game;

    // Call the start game method with the correct player count.
    player1Win = game.StartGame(playerCount);

    // Once the loop above has finished, output the results to the console.
    cout << "The game is over! ";

    // Check for a tie
    if (game.GameTie)
    {
        cout << "Neither player has won... it was a Tie!!" << endl;
    }
    else // No tie, report who won.
    {
        if (player1Win)
        {
            cout << "Player 1 has won!" << endl;
        }
        else
        {
            // If single player game, refer to player 2 as "computer".
            if (playerCount == 1) cout << "The computer has won!" << endl;
            else cout << "Player 2 has won!" << endl;
        }
    }

    
    
}


