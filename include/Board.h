#ifndef BOARD_H
#define BOARD_H

#include <SDL2/SDL.h>


class Board
{
	public:
		Board(SDL_Renderer *);
		virtual ~Board();
		void drawBoard();

	protected:

	private:
		SDL_Renderer *m_window_renderer;
};

#endif // BOARD_H
