#include <iostream>
#include <string>
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

void checkGameState(SDL_Renderer *);
void printBoard();
void markTheWinner(SDL_Renderer *, std::string);

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
						checkGameState(m_window_renderer);
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

	return 0;
}

void checkGameState(SDL_Renderer *m_window_renderer)
{
	Piece winnerPiece = EmptyPiece;
	bool gameWon = false;
	std::string winnerLocation = "";

	// Check if there is a winner by row
	if ( (logicalBoard[0][0] == logicalBoard[0][1]) && (logicalBoard[0][1] == logicalBoard[0][2]) && (logicalBoard[0][0] != EmptyPiece) )
	{
		gameWon = true;
		winnerLocation = "First Row";
	}
	else if ( (logicalBoard[1][0] == logicalBoard[1][1]) && (logicalBoard[1][1] == logicalBoard[1][2]) && (logicalBoard[1][0] != EmptyPiece) )
	{
		gameWon = true;
		winnerLocation = "Second Row";
	}
	else if ( (logicalBoard[2][0] == logicalBoard[2][1]) && (logicalBoard[2][1] == logicalBoard[2][2]) && (logicalBoard[2][0] != EmptyPiece) )
	{
		gameWon = true;
		winnerLocation = "Third Row";
	}

	// Check if there is a winner by column
	if ( (logicalBoard[0][0] == logicalBoard[1][0]) && (logicalBoard[1][0] == logicalBoard[2][0]) && (logicalBoard[0][0] != EmptyPiece) )
	{
		gameWon = true;
		winnerLocation = "First Column";
	}
	else if ( (logicalBoard[0][1] == logicalBoard[1][1]) && (logicalBoard[1][1] == logicalBoard[2][1]) && (logicalBoard[0][1] != EmptyPiece) )
	{
		gameWon = true;
		winnerLocation = "Second Column";
	}
	else if ( (logicalBoard[0][2] == logicalBoard[1][2]) && (logicalBoard[1][2] == logicalBoard[2][2]) && (logicalBoard[0][2] != EmptyPiece) )
	{
		gameWon = true;
		winnerLocation = "Third Column";
	}

	// Check if there is a winner by diagonal
	if ( (logicalBoard[2][0] == logicalBoard[1][1]) && (logicalBoard[1][1] == logicalBoard[0][2]) && (logicalBoard[0][2] != EmptyPiece) )
	{
		gameWon = true;
		winnerLocation = "Normal Diagonal";
	}
	else if ( (logicalBoard[0][0] == logicalBoard[1][1]) && (logicalBoard[1][1] == logicalBoard[2][2]) && (logicalBoard[0][0] != EmptyPiece) )
	{
		gameWon = true;
		winnerLocation = "Inverse Diagonal";
	}

	if (gameWon)
	{
		LOG(INFO) << std::endl << "\tWIN: " << winnerLocation << std::endl;
		markTheWinner(m_window_renderer, winnerLocation);
	}
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

void markTheWinner(SDL_Renderer *m_window_renderer, std::string location)
{
	LOG(INFO) << "Marking the winner on " << location;

	if (location.compare("First Row") == 0)
	{
		LOG(INFO) << "Marking the first row...";

		SDL_Rect lineHorizontal;
		lineHorizontal.x = 20;
		lineHorizontal.y = 70;
		lineHorizontal.w = 600;
		lineHorizontal.h = 20;

		SDL_SetRenderDrawColor(m_window_renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(m_window_renderer, &lineHorizontal);
		SDL_RenderPresent(m_window_renderer);
	}
	else if (location.compare("Second Row") == 0)
	{
		LOG(INFO) << "Marking the second row...";

		SDL_Rect lineHorizontal;
		lineHorizontal.x = 20;
		lineHorizontal.y = 230;
		lineHorizontal.w = 600;
		lineHorizontal.h = 20;

		SDL_SetRenderDrawColor(m_window_renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(m_window_renderer, &lineHorizontal);
		SDL_RenderPresent(m_window_renderer);
	}
	else if (location.compare("Third Row") == 0)
	{
		LOG(INFO) << "Marking the third row...";

		SDL_Rect lineHorizontal;
		lineHorizontal.x = 20;
		lineHorizontal.y = 390;
		lineHorizontal.w = 600;
		lineHorizontal.h = 20;

		SDL_SetRenderDrawColor(m_window_renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(m_window_renderer, &lineHorizontal);
		SDL_RenderPresent(m_window_renderer);
	}
	else if (location.compare("First Column") == 0)
	{
		LOG(INFO) << "Marking the first column...";

		SDL_Rect lineHorizontal;
		lineHorizontal.x = 100;
		lineHorizontal.y = 20;
		lineHorizontal.w = 20;
		lineHorizontal.h = 440;

		SDL_SetRenderDrawColor(m_window_renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(m_window_renderer, &lineHorizontal);
		SDL_RenderPresent(m_window_renderer);
	}
	else if (location.compare("Second Column") == 0)
	{
		LOG(INFO) << "Marking the second column...";

		SDL_Rect lineHorizontal;
		lineHorizontal.x = 310;
		lineHorizontal.y = 20;
		lineHorizontal.w = 20;
		lineHorizontal.h = 440;

		SDL_SetRenderDrawColor(m_window_renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(m_window_renderer, &lineHorizontal);
		SDL_RenderPresent(m_window_renderer);
	}
	else if (location.compare("Third Column") == 0)
	{
		LOG(INFO) << "Marking the third column...";

		SDL_Rect lineHorizontal;
		lineHorizontal.x = 520;
		lineHorizontal.y = 20;
		lineHorizontal.w = 20;
		lineHorizontal.h = 440;

		SDL_SetRenderDrawColor(m_window_renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(m_window_renderer, &lineHorizontal);
		SDL_RenderPresent(m_window_renderer);
	}
}
