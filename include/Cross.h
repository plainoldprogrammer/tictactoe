#ifndef CROSS_H
#define CROSS_H

#include <SDL2/SDL.h>


class Cross
{
    public:
        Cross();
        virtual ~Cross();
        void drawCross();

    protected:

    private:
        SDL_Renderer *m_window_renderer;
};

#endif // CROSS_H
