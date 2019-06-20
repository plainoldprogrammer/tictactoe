#include <iostream>
#include <SDL2/SDL.h>


int main(int argc,char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Failed to initialize the SDL2 library\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return -1;
	}

	SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

	if (!window)
	{
		std::cout << "Failed to create window\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return -1;
	}

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

	if (!window_surface)
	{
		std::cout << "Failed to get the surface from the window\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return -1;
	}

	SDL_Renderer *m_window_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	bool keep_window_open = true;
	while (keep_window_open)
	{
		// Drawing the first horizontal line of the board.
		SDL_Rect lineHorizontal1;
		lineHorizontal1.x = 20;
		lineHorizontal1.y = (480 / 3) * 1;
		lineHorizontal1.w = 640 - 40;
		lineHorizontal1.h = 10;

		SDL_SetRenderDrawColor(m_window_renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(m_window_renderer, &lineHorizontal1);
		SDL_RenderPresent(m_window_renderer);

		// Drawing the second horizontal line of the board.
		SDL_Rect lineHorizontal2;
		lineHorizontal2.x = 20;
		lineHorizontal2.y = (480 / 3) * 2;
		lineHorizontal2.w = 640 - 40;
		lineHorizontal2.h = 10;

		SDL_SetRenderDrawColor(m_window_renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(m_window_renderer, &lineHorizontal2);
		SDL_RenderPresent(m_window_renderer);

		// Drawing the first vertical line of the board.
		SDL_Rect lineVertical1;
		lineVertical1.x = (640 / 3) * 1;
		lineVertical1.y = 20;
		lineVertical1.w = 10;
		lineVertical1.h = (480 - 40);

		SDL_SetRenderDrawColor(m_window_renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(m_window_renderer, &lineVertical1);
		SDL_RenderPresent(m_window_renderer);

		// Drawing the second vertical line of the board.
		SDL_Rect lineVertical2;
		lineVertical2.x = (640 / 3) * 2;
		lineVertical2.y = 20;
		lineVertical2.w = 10;
		lineVertical2.h = (480 - 40);

		SDL_SetRenderDrawColor(m_window_renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(m_window_renderer, &lineVertical2);
		SDL_RenderPresent(m_window_renderer);

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
}
