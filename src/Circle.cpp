#include <math.h>
#include "Circle.h"


Circle::Circle(SDL_Renderer *window_renderer)
{
	m_window_renderer = window_renderer;

	circleStruct.radius = 60;
	circleStruct.old_x = 118;
	circleStruct.old_y = 90;
	circleStruct.h = 118;
	circleStruct.k = 90;
	circleStruct.step = 0.002;
}

Circle::~Circle()
{
	//dtor
}

void Circle::drawCircle()
{
	for ( float theta = 0; theta < (PI * 2); theta += circleStruct.step )
	{
		circleStruct.new_x = circleStruct.h + (circleStruct.radius * cos ( theta ));
		circleStruct.new_y = circleStruct.k - (circleStruct.radius * sin ( theta ));
		SDL_RenderDrawLine (m_window_renderer, circleStruct.old_x, circleStruct.old_y,
						 circleStruct.new_x, circleStruct.new_y );
	}
}
