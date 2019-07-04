#pragma once
#include <SDL.h>
class Window
{
	//The window we'll be rendering to
	SDL_Window* gWindow ;

	//The surface contained by the window
	SDL_Surface* gScreenSurface;
	int height;
	int width;
	bool init();
	
public:
	Window(const int w, const int h);
	SDL_Window* getWindow();
	~Window();
};

