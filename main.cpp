#include <iostream>
#include <SDL2/SDL.h>
#include "easylogging++.h"
#include "Board.h"
#include "Circle.h"
#include "Cross.h"


enum Piece { EmptyPiece, CirclePiece, CrossPiece };

INITIALIZE_EASYLOGGINGPP;

Piece logicalBoard[3][3] = {
						{ EmptyPiece, EmptyPiece, EmptyPiece },
						{ EmptyPiece, EmptyPiece, EmptyPiece },
						{ EmptyPiece, EmptyPiece, EmptyPiece }
					};

void checkGameState();
void printBoard();

int main(int argc,char *argv[])
{
	LOG (INFO) << "Start of the game";

	boolean circleTurn = false;

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
				case SDL_MOUSEBUTTONDOWN:
					if (e.button.button == SDL_BUTTON_LEFT)
					{
						LOG(INFO) << "Left button click of the mouse at (" << e.button.x << ", " << e.button.y << ").";

						if (e.button.x >= 20 && e.button.x <= 210 &&
							e.button.y >= 20 && e.button.y <= 160)
						{
							if (circleTurn)
							{
								Circle *circle = new Circle(m_window_renderer, 118, 80);
								circle->drawCircle();
								delete circle;

								logicalBoard[0][0] = CirclePiece;
							}
							else
							{
								Cross *cross = new Cross(m_window_renderer, 20, 20);
								cross->drawCross();
								delete cross;

								logicalBoard[0][0] = CrossPiece;
							}

							circleTurn = !circleTurn;
						}
						else if (e.button.x >= 223 && e.button.x <= 425 &&
								 e.button.y >= 20 && e.button.y <= 160)
						{
							if (circleTurn)
							{
								Circle *circle = new Circle(m_window_renderer, 324, 80);
								circle->drawCircle();
								delete circle;

								logicalBoard[0][1] = CirclePiece;
							}
							else
							{
								Cross *cross = new Cross(m_window_renderer, 233, 20);
								cross->drawCross();
								delete cross;

								logicalBoard[0][1] = CrossPiece;
							}

							circleTurn = !circleTurn;
						}
						else if (e.button.x >= 435 && e.button.x <= 620 &&
								 e.button.y >= 20 && e.button.y <= 160)
						{
							if (circleTurn)
							{
								Circle *circle = new Circle(m_window_renderer,  529, 80);
								circle->drawCircle();
								delete circle;

								logicalBoard[0][2] = CirclePiece;
							}
							else
							{
								Cross *cross = new Cross(m_window_renderer, 445, 20);
								cross->drawCross();
								delete cross;

								logicalBoard[0][2] = CrossPiece;
							}

							circleTurn = !circleTurn;
						}
						else if (e.button.x >= 20 && e.button.x <= 210 &&
								 e.button.y >= 170 && e.button.y <= 320)
						{
							if (circleTurn)
							{
								Circle *circle = new Circle(m_window_renderer, 118, 245);
								circle->drawCircle();
								delete circle;

								logicalBoard[1][0] = CirclePiece;
							}
							else
							{
								Cross *cross = new Cross(m_window_renderer, 20, 180);
								cross->drawCross();
								delete cross;

								logicalBoard[1][0] = CrossPiece;
							}

							circleTurn = !circleTurn;
						}
						else if (e.button.x >= 233 && e.button.x <= 425 &&
								 e.button.y >= 170 && e.button.y <= 320)
						{
							if (circleTurn)
							{
								Circle *circle = new Circle(m_window_renderer, 324, 245);
								circle->drawCircle();
								delete circle;

								logicalBoard[1][1] = CirclePiece;
							}
							else
							{
								Cross *cross = new Cross(m_window_renderer, 233, 180);
								cross->drawCross();
								delete cross;

								logicalBoard[1][1] = CrossPiece;
							}

							circleTurn = !circleTurn;
						}
						else if (e.button.x >= 435 && e.button.x <= 620 &&
								 e.button.y >= 170 && e.button.y <= 320)
						{
							if (circleTurn)
							{
								Circle *circle = new Circle(m_window_renderer, 529, 245);
								circle->drawCircle();
								delete circle;

								logicalBoard[1][2] = CirclePiece;
							}
							else
							{
								Cross *cross = new Cross(m_window_renderer, 445, 180);
								cross->drawCross();
								delete cross;

								logicalBoard[1][2] = CrossPiece;
							}

							circleTurn = !circleTurn;
						}
						else if (e.button.x >= 20 && e.button.x <= 210 &&
								 e.button.y >= 330 && e.button.y <= 460)
						{
							if (circleTurn)
							{
								Circle *circle = new Circle(m_window_renderer, 118, 410);
								circle->drawCircle();
								delete circle;

								logicalBoard[2][0] = CirclePiece;
							}
							else
							{
								Cross *cross = new Cross(m_window_renderer, 20, 340);
								cross->drawCross();
								delete cross;

								logicalBoard[2][0] = CrossPiece;
							}

							circleTurn = !circleTurn;
						}
						else if (e.button.x >= 233 && e.button.x <= 425 &&
								 e.button.y >= 330 && e.button.y <= 460)
						{
							if (circleTurn)
							{
								Circle *circle = new Circle(m_window_renderer, 324, 410);
								circle->drawCircle();
								delete circle;

								logicalBoard[2][1] = CirclePiece;
							}
							else
							{
								Cross *cross = new Cross(m_window_renderer, 233, 340);
								cross->drawCross();
								delete cross;

								logicalBoard[2][1] = CrossPiece;
							}

							circleTurn = !circleTurn;
						}
						else if (e.button.x >= 435 && e.button.x <= 620 &&
								 e.button.y >= 330 && e.button.y <= 460)
						{
							if (circleTurn)
							{
								Circle *circle = new Circle(m_window_renderer, 529, 410);
								circle->drawCircle();
								delete circle;

								logicalBoard[2][2] = CirclePiece;
							}
							else
							{
								Cross *cross = new Cross(m_window_renderer, 445, 340);
								cross->drawCross();
								delete cross;

								logicalBoard[2][2] = CrossPiece;
							}

							circleTurn = !circleTurn;
						}

						printBoard();
					}
					break;
			}

			SDL_UpdateWindowSurface(window);
		}
	}

	delete board;
	delete m_window_renderer;
	delete window;

	LOG(INFO) << "End of the game";
}

void checkGameState()
{
}

void printBoard()
{
	LOG(INFO) << std::endl << "Board";

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (logicalBoard[i][j] == EmptyPiece)
			{
				std::cout << "-" << "\t";
			}
			else if (logicalBoard[i][j] == CirclePiece)
			{
				std::cout << "O" << "\t";
			}
			else if (logicalBoard[i][j] == CrossPiece)
			{
				std::cout << "X" << "\t";
			}
		}

		std::cout << std::endl;
	}
}
