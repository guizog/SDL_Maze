//
// Created by guizo on 30/06/2022.
//

#ifndef SDL_MAZE_TEXTURE_H
#define SDL_MAZE_TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include "Maze.h"

class Texture {
public:
    static SDL_Texture* LoadTexture(const char *path);
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst);
    static void DrawNode(Node node);
private:
};


#endif //SDL_MAZE_TEXTURE_H
