#include <SDL.h>
#include <iostream>
#include "Maze.h"

void Init(const char*, int, int, int, int);

SDL_Renderer* renderer;
SDL_Window* window;

int main(int argc, char* args[] ) {
    Init("Maze generator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 320);
    Maze *maze = new Maze();

    maze->GenerateMaze();
    while(maze->running){
        HandleEvents();
        maze->DrawMaze();
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return EXIT_SUCCESS;
}

void Init(const char *title, int xpos, int ypos, int width, int height) {
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "SDL subsystems initialised successfully" << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
        if(window)
            std::cout << "Window initialised successfully" << std::endl;
        else
            std::cout << "Window failed to initialise successfully. Error code: " << SDL_GetError() << std::endl;

        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        if(renderer)
            std::cout << "Renderer initialised successfully" << std::endl;
        else
            std::cout << "Renderer failed to initialise successfully. Error code: " << SDL_GetError() << std::endl;
    }
    else{
        std::cout << "SDL subsystems failed to initialise properly. Error code: " << SDL_GetError() << std::endl;
    }
}

