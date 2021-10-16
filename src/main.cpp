#include <iostream>
#include "game.hpp"
#include <SDL2/SDL.h>

int main(int argc, char **argv) {
    Game *game = new Game();
    game->init("New Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);
    while(game->running()) {
        game->handleEvent();
        game->update();
        game->render();
    }

    game->clean();
    return 0;
}
