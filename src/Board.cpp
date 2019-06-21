#include "Board.h"

Board::Board(SDL_Renderer *window_renderer)
{
	m_window_renderer = window_renderer;
}

Board::~Board()
{
	//dtor
}

void Board::drawBoard()
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
}
