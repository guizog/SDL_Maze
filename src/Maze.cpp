//
// Created by guizo on 30/06/2022.
//

#include "Maze.h"
#include <stack>
#include <random>

extern SDL_Renderer* renderer;
Node mazeGrid[10][10];

void RemoveWalls(Node* curr, Node* next){
    int cx = curr->xpos;
    int nx = next->xpos;
    int cy = curr->ypos;
    int ny = next->ypos;
    //cx == nx && ny == cy - 1
    if(cx == nx && ny == cy - 1){
        curr->walls[0] = 0;
        next->walls[2] = 0;
    }
    //cx == nx && ny = cy + 1
    else if(cx == nx && ny == cy + 1){
        curr->walls[2] = 0;
        next->walls[0] = 0;
    }
    //nx == cx - 1 && ny == cy
    else if(nx == cx - 1 && ny == cy){
        curr->walls[3] = 0;
        next->walls[1] = 0;
    }
    //nx == cx + 1 && ny == cy
    else if(nx == cx + 1 && ny == cy){
        curr->walls[1] = 0;
        next->walls[3] = 0;
    }
}

Node* ChooseRandom(std::vector<Node*> node){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, (node.size()-1));
    return node[dist(rng)];
}

Maze::Maze() {
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            mazeGrid[y][x].xpos = x;
            mazeGrid[y][x].ypos = y;
        }
    }
}

Maze::~Maze() = default;

void Maze::DrawMaze() {
    SDL_RenderClear(renderer);
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            Texture::DrawNode(mazeGrid[y][x]);
        }
    }
    SDL_RenderPresent(renderer);
}

void Maze::GenerateMaze() {
    std::stack<Node*> stack;
    Node *initialCell = &mazeGrid[0][0];
    initialCell->visited = true;
    stack.push(initialCell);
    while(!stack.empty()){
        Node *curr = stack.top();
        stack.pop();
        if(!curr->CheckNeighbours().empty()){
            stack.push(curr);
            Node *next = new Node();

            //Choose one of the unvisited neighbours
            next = ChooseRandom(curr->CheckNeighbours());

            //Remove the wall between the current cell and the chosen cell
            RemoveWalls(curr, next);

            //Mark the chosen cell as visited and push it to the stack
            next->visited = true;
            stack.push(next);
        }
    }
}
