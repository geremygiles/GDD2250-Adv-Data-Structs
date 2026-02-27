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

    bool SinglePlayerGame()
    {
        bool gameOver = false;

        while (!gameOver)
        {
            // Game loop
            cout << "Single player game" << endl;
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
            cout << "Two player game" << endl;
            gameOver = true;
        }

        return false;
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
        
        int inputtedPlayers;
        cin >> inputtedPlayers;
        if (inputtedPlayers == 1 || inputtedPlayers == 2) // Valid Input
        {
            playerCount = inputtedPlayers;
        }
        else
        {
            cout << "Invalid Input, please try again." << endl;
            inputtedPlayers = 0;
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


