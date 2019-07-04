#include "Window.h"
#include <iostream>


Window::Window(const int w,const int h)
{
	width = w;
	height = h;
	Window::init();
}
SDL_Window* Window::getWindow() {
	return gWindow;
}

Window::~Window()
{
	//Destroy window
	SDL_DestroyWindow(Window::gWindow);
	Window::gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

bool Window::init()
{
	//The window we'll be rendering to
	gWindow = NULL;

	//The surface contained by the window
	gScreenSurface = NULL;
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout<<"SDL could not initialize! SDL_Error: %s\n", SDL_GetError();
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Beast", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Window::width, Window::height, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			std::cout << "Window could not be created! SDL_Error: %s\n", SDL_GetError();
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

