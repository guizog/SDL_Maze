//
// Created by guizo on 26/06/2022.
//

#include "Node.h"

Node::Node(){
    visited = false;
    xpos = ypos = 0;
    parent = nullptr;
}

Node::~Node(){
    delete parent;
}

std::vector<Node*> Node::CheckNeighbours() {
    int x = this->xpos;
    int y = this->ypos;
    extern Node mazeGrid[10][10];
    std::vector<Node*> vec;
    if(!mazeGrid[y-1][x].visited && (y-1) >= 0)
        vec.push_back(&mazeGrid[y-1][x]);

    if(!mazeGrid[y+1][x].visited && (y+1) < 10)
        vec.push_back(&mazeGrid[y+1][x]);

    if(!mazeGrid[y][x-1].visited && (x-1) >= 0)
        vec.push_back(&mazeGrid[y][x-1]);

    if(!mazeGrid[y][x+1].visited && (x+1) < 10)
        vec.push_back(&mazeGrid[y][x+1]);
    return vec;
}

std::ostream& operator<< (std::ostream& os, Node node){
    os << "Visited: " << node.visited << std::endl
       << "X: " << node.xpos << "   Y: " << node.ypos << std::endl
       << "Walls: " << node.walls[0] << node.walls[1] << node.walls[2] << node.walls[3];
    return os;
}