#include "Event.h"
#include <iostream>


Event::Event()
{
}


Event::~Event()
{
}
void Event::waitForQuit(bool &quit) {
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
	}

 }
bool Event::waitForPlayerMove(Board &b) {
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	bool update = false;
	if (currentKeyStates[SDL_SCANCODE_UP])
	{
		if ((b.player_y - 1) >= 0) {
			if (b.tab[b.player_x][b.player_y - 1] == 0 ) {
				b.player_y -= 1;
			}
			else if(b.player_y - 2>=0)  {
				if (b.tab[b.player_x][b.player_y - 1] == 1 && b.tab[b.player_x][b.player_y - 2] == 0) {
					b.tab[b.player_x][b.player_y - 1] = 0;
					b.tab[b.player_x][b.player_y - 2] = 1;
					b.player_y -= 1;
					update = true;
				}
			}
		}
		
	}
	else if (currentKeyStates[SDL_SCANCODE_DOWN])
	{
		if ((b.player_y + 1) < b.height) {
			if (b.tab[b.player_x][b.player_y + 1] == 0) {
				b.player_y += 1;
			}
			else if (b.player_y + 2 < b.height) {
				if (b.tab[b.player_x][b.player_y + 1] == 1 && b.tab[b.player_x][b.player_y + 2] == 0) {
					b.tab[b.player_x][b.player_y + 1] = 0;
					b.tab[b.player_x][b.player_y + 2] = 1;
					b.player_y += 1;
					update = true;
				}
			}
		}
	}
	else if (currentKeyStates[SDL_SCANCODE_LEFT])
	{
		if ((b.player_x - 1) >= 0) {
			if (b.tab[b.player_x - 1][b.player_y] == 0) {
				b.player_x -= 1;
			}
			else if(b.player_x - 2>= 0){
				if (b.tab[b.player_x - 1][b.player_y] == 1 && b.tab[b.player_x - 2][b.player_y] == 0) {
					b.tab[b.player_x - 1][b.player_y] = 0;
					b.tab[b.player_x - 2][b.player_y] = 1;
					b.player_x -= 1;
					update = true;
				}
			}
		}
	}
	else if (currentKeyStates[SDL_SCANCODE_RIGHT])
	{
		if ((b.player_x + 1) < b.width) {
			if (b.tab[b.player_x + 1][b.player_y] == 0) {
				b.player_x += 1;
			}
			else if((b.player_x + 2) < b.width){
				if (b.tab[b.player_x + 1][b.player_y] == 1 && b.tab[b.player_x + 2][b.player_y] == 0) {
					b.tab[b.player_x + 1][b.player_y] = 0;
					b.tab[b.player_x + 2][b.player_y] = 1;
					b.player_x += 1;
					update = true;
				}
			}
		}
	}
	else
	{
	}
	std::cout << b.player_x << "  " << b.player_y << std::endl;
	return update;
}