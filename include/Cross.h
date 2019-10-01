#ifndef CROSS_H
#define CROSS_H

#include <SDL2/SDL.h>


class Cross
{
    public:
        Cross(SDL_Renderer *, int, int);
        virtual ~Cross();
        void drawCross();

    protected:

    private:
		int x;
		int y;
        SDL_Renderer *m_window_renderer;
};

#endif // CROSS_H
