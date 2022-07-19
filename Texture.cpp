//
// Created by guizo on 30/06/2022.
//

#include "Texture.h"
#include <iostream>
#include <string>

extern SDL_Renderer* renderer;

SDL_Texture* Texture::LoadTexture(const char *path) {
    SDL_Surface* temp = IMG_Load(path);
    if(temp == NULL)
        std::cout << "Failed to load surface. Error: " << SDL_GetError() << std::endl;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp);
    if(texture == NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    SDL_FreeSurface(temp);
    return texture;
}

void Texture::Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dst) {
    SDL_RenderCopy(renderer, texture, &src, &dst);
}

void Texture::DrawNode(Node node) {
    SDL_Rect src, dst;
    src.w = src.h = dst.w = dst.h = 32;
    src.x = src.y = 0;
    dst.x = node.xpos * 32;
    dst.y = node.ypos * 32;
    for(int i = 0; i < 4; i++){
        if(node.walls[i]) {
            std::string path = "../assets/wall" + std::to_string(i) + ".png";
            SDL_Surface *temp = IMG_Load(path.c_str());
            SDL_Texture *texture;
            texture = SDL_CreateTextureFromSurface(renderer, temp);
            SDL_FreeSurface(temp);
            SDL_RenderCopy(renderer, texture, &src, &dst);
        }
    }
}
