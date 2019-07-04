

#include <stdio.h>
#include "Board.h"
#include "Window.h"
#include "Renderer.h"
#include "Event.h"
#include <iostream>
//Screen dimension constants
const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window

//fsfsfsfsdfsfsfa



int main(int argc, char* args[])
{
	Window window(SCREEN_WIDTH, SCREEN_HEIGHT);
	Board board(SCREEN_WIDTH, SCREEN_HEIGHT);
	board.setBoard();
	board.printBoard();
	Renderer renderer(window);
	Event e;
	//Start up SDL and create window

	renderer.setBlocks(board);
	bool quit = false;
	bool update = false;
	int player_x = 0;
	int player_y = 0;
	board.player_x = player_x;
	board.player_y = player_y;
	renderer.renderPlayer(player_x, player_y);
	while (!quit) {

		e.waitForQuit(quit);
		update=e.waitForPlayerMove(board);

		renderer.updateBlocks(board, update);
		renderer.renderBoard();
		
		renderer.renderPlayer(board.player_x, board.player_y);
		renderer.display();
		SDL_Delay(80);
		// Wait for 5 sec
		//SDL_Delay(5000);
		//Update the surface
		//SDL_UpdateWindowSurface(gWindow);

		//Wait two seconds
		//
	}

	//Free resources and close SDL
	

	return 0;
}