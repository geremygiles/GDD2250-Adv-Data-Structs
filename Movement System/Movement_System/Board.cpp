#include "Board.h"
#include <iostream> // Printing to the console

using namespace std;

// Public Methods

bool Board::Move(int yDelta, int xDelta)
{
    cout << "Moved " << yDelta << " units south, and " << xDelta << " units east." << endl;
    return true;
}

void Board::PrintBoard() const
{
    cout << "===========" << endl;

    for (int i = 0; i < boardHeight; i++)
    {
        cout << "| ";
        for (int j = 0; j < boardWidth; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << "|" << endl;
    }
    cout << "===========" << endl;
}

// Private Methods 
void Board::SetPosition(int yCoord, int xCoord)
{
    board[yCoord][xCoord] = 'X';
}

Board::Board(int height, int width, int startY, int startX)
{
    boardHeight = height;
    boardWidth = width;

    // Initialize Board
    for (int i = 0; i < boardHeight; i++)
    {
        for (int j = 0; j < boardWidth; j++)
        {
            board[i][j] = 'O';
        }
    }

    SetPosition(startY, startX);
}

