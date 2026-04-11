#include "Board.h"
#include <iostream> // Printing to the console

using namespace std;

// Public Methods

/// <summary>
/// Checks if allowed, then moves the player in the specified direction.
/// </summary>
/// <param name="yDelta">The movement down on the vertical axis.</param>
/// <param name="xDelta">The movement right on the horizontal axis.</param>
/// <returns>Returns a bool indicating whether the move was successful or not</returns>
bool Board::Move(int yDelta, int xDelta)
{
    // Check if desired move is valid
    if (playerPosY + yDelta < 0 || playerPosY + yDelta >= boardHeight ||
        playerPosX + xDelta < 0 || playerPosX + xDelta >= boardWidth) return false;

    // Clear old position marker
    ClearPlayerPosition();

    // Update position
    playerPosY += yDelta;
    playerPosX += xDelta;

    // Update player visual marker
    UpdatePlayerPosition();

    //cout << "Moved " << yDelta << " units south, and " << xDelta << " units east." << endl;
    return true; // Movement allowed and complete, return true
}

/// <summary>
/// Prints the board to the console.
/// </summary>
void Board::PrintBoard() const
{
    cout << " ===========" << endl; // Top border

    for (int i = 0; i < boardHeight; i++)
    {
        cout << " | "; // Left border
        for (int j = 0; j < boardWidth; j++)
        {
            cout << board[i][j] << ' '; // Current value at this board location, seperated by spaces
        }
        cout << "|" << endl; // Right border
    }
    cout << " ===========" << endl; // Bottom border
}

// Private Methods 

/// <summary>
/// Updates the visual representation of the player's position.
/// </summary>
void Board::UpdatePlayerPosition()
{
    board[playerPosY][playerPosX] = 'X';
}

/// <summary>
/// Clears out the visual representation of the player's position.
/// </summary>
void Board::ClearPlayerPosition()
{
    board[playerPosY][playerPosX] = ' ';
}

/// <summary>
/// Constructor that creates and initializes the board, and sets the player's starting position.
/// </summary>
/// <param name="height"> The height of the board, marks the maximum distance the player can move from the top of the board.</param>
/// <param name="width">The width of the board, marks the maximum distance the player can move from the left of the board.</param>
/// <param name="startY">Player's starting position on the vertical axis.</param>
/// <param name="startX">Player's starting position on the horizontal axis.</param>
Board::Board(int height, int width, int startY, int startX)
{
    // Set board max values
    boardHeight = height; 
    boardWidth = width;

    // Initialize Board
    for (int i = 0; i < boardHeight; i++) // Iterate through rows
    {
        for (int j = 0; j < boardWidth; j++) // Iterate through columns
        {
            board[i][j] = ' '; // Set to blank
        }
    }

    // Set player's starting position on the board
    playerPosY = startY; 
    playerPosX = startX;

    // Update player visual marker
    UpdatePlayerPosition();
}

