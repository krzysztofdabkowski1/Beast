
#pragma once

class Board
{

public:
	void initBoard();
	void setBoard();
	//helpers
	void printBoard();
	
	Board(int w, int h)
	{

		Board::width = w / 20;
		Board::height = h / 20;
		initBoard();
	}
	~Board()
	{
	}
//private:
	int player_x;
	int player_y;
	int height;
	int width;
	int **tab;
};


