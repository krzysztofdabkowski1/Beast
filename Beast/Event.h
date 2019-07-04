#pragma once
#include <SDL.h>
#include "Board.h"
class Event
{
	SDL_Event e;
	int **tab;
	int player_x;
	int player_y;
public:
	
	Event();
	~Event();
	void waitForQuit(bool &quit);
	bool waitForPlayerMove(Board& b);
};

