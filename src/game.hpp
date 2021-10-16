#ifndef _GAME_H
#define _GAME_H

#include <SDL2/SDL.h>
#include <iostream>

class Game {
    public:
        Game();
        ~Game();

        void init(const char *title, int xpos, int ypos, int w, int h, bool flag);
        void update();
        void render();
        void clean();
        void handleEvent();
        bool running() { return isRunning; }
    private:
        bool isRunning;
        SDL_Window *win;
        SDL_Renderer *ren;
};

#endif
