#include <math.h>
#include "Circle.h"


Circle::Circle(SDL_Renderer *window_renderer, int x, int y)
{
	m_window_renderer = window_renderer;

	radius = 60;
	old_x = x;
	old_y = y;
	h = x;
	k = y;
	step = 0.002;
}

Circle::~Circle()
{
	//dtor
}

void Circle::drawCircle()
{
	for ( float theta = 0; theta < (PI * 2); theta += step )
	{
		new_x = h + (radius * cos ( theta ));
		new_y = k - (radius * sin ( theta ));
		SDL_RenderDrawLine(m_window_renderer, old_x, old_y,
						 new_x, new_y );
	}
}
