#pragma once
class Board
{
	public:
		bool Move(int yDelta, int xDelta);
		void PrintBoard() const;
		Board(int height, int width, int startY, int startX);

	private:
		void SetPosition(int yCoord, int xCoord);
		int boardHeight;
		int boardWidth;
		char board[4][4];
};