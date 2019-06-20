#include <iostream>
#include <SDL2/SDL.h>
#include <Board.h>
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP;


int main(int argc,char *argv[])
{
	LOG (INFO) << "Start of the game";

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		LOG(INFO) << "Failed to initialize the SDL2 library\n";
		LOG(INFO) << "SDL2 Error: " << SDL_GetError() << "\n";
		return -1;
	}

	SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

	if (!window)
	{
		LOG(INFO) << "Failed to create window\n";
		LOG(INFO) << "SDL2 Error: " << SDL_GetError() << "\n";
		return -1;
	}

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

	if (!window_surface)
	{
		LOG(INFO) << "Failed to get the surface from the window\n";
		LOG(INFO) << "SDL2 Error: " << SDL_GetError() << "\n";
		return -1;
	}

	Board *board = new Board(window);

	bool keep_window_open = true;
	while (keep_window_open)
	{
		board->drawBoard();

		SDL_Event e;
		while (SDL_PollEvent(&e) > 0)
		{
			switch (e.type)
			{
				case SDL_QUIT:
					keep_window_open = false;
					break;
			}

			SDL_UpdateWindowSurface(window);
		}
	}

	LOG(INFO) << "End of the game";
}
