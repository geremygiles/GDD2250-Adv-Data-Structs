/*
* Geremy Giles
* 02/27/2026
* Practice implementation of Tic-Tac-Toe using classes
* 
*/

#include <iostream>
using namespace std;

// Prompts the user for how many players, then calls the corrosponding method in the Game class. This class contains a flag to mark which player has won.
int main()
{
    bool player1Win;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    int playerCount = 0;

    while (playerCount == 0) 
    {
        cout << "1 or 2 players?" << endl;
        
        int inputtedPlayers;
        cin >> inputtedPlayers;
        if (inputtedPlayers == 1 || inputtedPlayers == 2) 
        {
            playerCount = inputtedPlayers;
        }
    }

    if (playerCount == 1) 
    {

    }

    cout << "Hello World!\n";
}


class Game
{
    private bool SinglePlayerGame()
    {

    }

    private bool TwoPlayerGame()
    {

    }
};