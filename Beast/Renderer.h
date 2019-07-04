#pragma once
#include <SDL.h> 
#include "Window.h"
#include "Board.h"
class Renderer
{	
public:
	int blocksCounter;
	SDL_Rect r[1280];
	SDL_Rect player;
	SDL_Renderer* renderer;
	Renderer(Window &window);
	~Renderer();
	void renderBoard();
	void renderPlayer(int x,int y);
	void display();
	void setBlocks(Board board);
	void updateBlocks(Board board,bool update);
};

