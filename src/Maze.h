//
// Created by guizo on 30/06/2022.
//

#ifndef SDL_MAZE_MAZE_H
#define SDL_MAZE_MAZE_H

#include "Node.h"
#include "Texture.h"
#include <SDL.h>

class Maze {
public:
    Maze();
    ~Maze();
    void GenerateMaze();
    void DrawMaze();

    bool running;

    SDL_Rect srcR, dstR;
private:

};


#endif //SDL_MAZE_MAZE_H
