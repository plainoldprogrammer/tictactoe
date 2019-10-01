#include "Cross.h"


Cross::Cross(SDL_Renderer *window_renderer, int x, int y)
{
	m_window_renderer = window_renderer;

	this->x = x;
	this->y = y;
}

Cross::~Cross()
{
}

void Cross::drawCross()
{
	SDL_RenderDrawLine(m_window_renderer, x, y, x + 170, y + 120);
	SDL_RenderDrawLine(m_window_renderer, x + 170, y, x, y + 120);
}
