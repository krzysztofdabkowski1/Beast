#include "Renderer.h"



Renderer::Renderer(Window &window)
{
	Renderer::renderer = NULL;
	renderer = SDL_CreateRenderer(window.getWindow(), -1, SDL_RENDERER_ACCELERATED);
	//player.x = 20 * 10;
	//player.y = 20 * 10;
	player.w = 20;
	player.h = 20;
}
void Renderer::setBlocks(Board board) {
	blocksCounter = 0;
	int y = 0;
	for (int i = 0; i < board.width; ++i) {
		for (int j = 0; j < board.height; ++j) {
			if (board.tab[i][j] == 1) {
				r[blocksCounter].x = i * 20;
				r[blocksCounter].y = j * 20;
				r[blocksCounter].w =20;
				r[blocksCounter].h =20;
				// Set render color to blue ( rect will be rendered in this color )


				// Render rect
				//SDL_RenderFillRect(renderer, &r[inc]);

				// Render the rect to the screen

				blocksCounter++;
			}
		}

	}

}


void Renderer::updateBlocks(Board board,bool update) {
	if (update) setBlocks(board);
}
void Renderer::renderBoard() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 100, 255);

	// Clear winow
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	for (int i = 0; i < blocksCounter; i++) SDL_RenderFillRect(renderer, &r[i]);
	
	

}
void Renderer::renderPlayer(int x, int y) {
	player.x = x*20;
	player.y = y*20;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &player);
}
	void Renderer::display() {
		SDL_RenderPresent(renderer);
}
Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
	Renderer::renderer = NULL;
}
