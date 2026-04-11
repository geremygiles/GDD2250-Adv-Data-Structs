#pragma once
/// <summary>
/// The game board, with all the data about the player's position and the bounds of their movement.
/// </summary>
class Board
{
	public:
		// Moves the player in the specified direction.
		bool Move(int yDelta, int xDelta); 

		// Prints the board to the console.
		void PrintBoard() const;

		// Constructor that creates and initializes the board, and sets the player's starting position.
		Board(int height, int width, int startY, int startX);

	private:
		// Updates the visual representation of the board to show where the player is.
		void UpdatePlayerPosition();

		// Clears out the old marker of where the player was.
		void ClearPlayerPosition();

		// The height of the board, marks the maximum distance the player can move from the top of the board.
		int boardHeight;

		// The width of the board, marks the maximum distance the player can move from the left of the board.
		int boardWidth;
		
		// Player's current position on the vertical axis.
		int playerPosY;

		// Player's current position on the horizontal axis.
		int playerPosX;

		// The board, as represented as an array of characters.
		char board[4][4];
};