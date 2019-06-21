#ifndef CIRCLE_H
#define CIRCLE_H

#include <SDL2/SDL.h>

#define PI 3.1416


class Circle
{
	public:
		Circle(SDL_Renderer *, int, int);
		virtual ~Circle();
		void drawCircle();

	protected:

	private:
		int radius;
		int h;
		int k;
		int new_x;
		int new_y;
		int old_x;
		int old_y;
		float step;
		SDL_Renderer *m_window_renderer;
};

#endif // CIRCLE_H
