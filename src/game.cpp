#include "game.hpp"

Game::Game() {
}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int w, int h, bool fullscreen) {
    int flag = 0;

    //Check for fullscreen
    if(fullscreen) flag = SDL_WINDOW_FULLSCREEN;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL initializer!" << std::endl;
        win = SDL_CreateWindow(title, xpos, ypos, w, h, flag);
        if(win) {
            std::cout << "SDL window created!" << std::endl;
            ren = SDL_CreateRenderer(win, -1, 0);
            if(ren) {
                std::cout << "SDL renderer created!" << std::endl;
                SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
                isRunning = true;
            } else {
                isRunning = false;
            }
        }
    }
}

void Game::update() {
}

void Game::render() {
    SDL_RenderClear(ren);

    /* Rendering stuff */
    SDL_RenderPresent(ren);
}

void Game::clean() {
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    SDL_Quit();
    std::cout << "SDL cleaned!" << std::endl;
}

void Game::handleEvent() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;

    }
}
