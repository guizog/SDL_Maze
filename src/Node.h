//
// Created by guizo on 26/06/2022.
//

#ifndef SDL_MAZE_NODE_H
#define SDL_MAZE_NODE_H

#include <iostream>
#include <vector>

class Node {
public:
    Node();
    ~Node();

    bool visited;
    int xpos, ypos;
    int walls[4] = {1,1,1,1};// clockwise starting from north
    Node* parent;

    std::vector<Node*> CheckNeighbours();

private:
};

std::ostream& operator<<(std::ostream& os, const Node node);

#endif //SDL_MAZE_NODE_H
