
#include "Board.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

/*
tab[][]=0 ->empty field
tab[][]=1 ->field of block
tab[][]=2 ->player

*/



void Board::initBoard()
{
	tab = new int*[width ];
	for (int i = 0; i < width; ++i) {
		tab[i] = new int[height];
	}
}
void Board::setBoard()
{
	for (int i = 0; i < Board::width; ++i) {
		for (int j = 0; j < Board::height; ++j) {
			Board::tab[i][j]=0 ;
		}
	}
	int tmp_w, tmp_h;
	srand(time(NULL));
	for (int i = 0; i < width*10; ++i) {
		
		tmp_w = rand() % width;
		tmp_h = rand() % height;
		tab[tmp_w][tmp_h]=1;
	}
}

void Board::printBoard() //helper function for console
{
	for (int i = 0; i < Board::width; ++i) {
		for (int j = 0; j < Board::height; ++j) {
			std::cout<<Board::tab[i][j]<<" " ;
		}
		std::cout<<std::endl;
	}
}


