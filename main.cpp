#include <iostream>
#include <SDL2/SDL.h>
#include "easylogging++.h"
#include "Board.h"
#include "Circle.h"

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

	SDL_Renderer *m_window_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	Board *board = new Board(m_window_renderer);
	Circle *circle = new Circle(m_window_renderer);

	bool keep_window_open = true;
	while (keep_window_open)
	{
		board->drawBoard();
		circle->drawCircle();

		SDL_Event e;
		while (SDL_PollEvent(&e) > 0)
		{
			switch (e.type)
			{
				case SDL_QUIT:
					keep_window_open = false;
					break;
				case SDL_MOUSEBUTTONDOWN:
					if (e.button.button == SDL_BUTTON_LEFT)
					{
						LOG(INFO) << "Left button click of the mouse at (" << e.button.x << ", " << e.button.y << ").";
					}
					break;
			}

			SDL_UpdateWindowSurface(window);
		}
	}

	delete circle;
	delete board;
	delete m_window_renderer;
	delete window;

	LOG(INFO) << "End of the game";
}
