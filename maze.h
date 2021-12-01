#ifndef MAZE_H
#define MAZE_H
#include "node.h"
#include "stack.h"
#define SIZE 60

typedef struct Maze Maze;
struct Maze{
    // 0 é X, 1 é Y
    int player_coordinates[2];
    int start_coordinates[2];
    int end_coordinates[2];

    int size;
    int maze[SIZE][SIZE];

    Stack *movements;
};

enum cell_types {Free, Wall, Visited, Alley, CurrentPosition, Start, Exit};

Maze *mallocMaze();

void setCell(Maze *maze, int x, int y, int number);
int getCell(Maze *maze, int x, int y);
void setAlley(Maze *maze);

void printsMaze(Maze *maze);
void printCell(Maze *maze, int x, int y);

int upIsFree(Maze *maze);
int rightIsFree(Maze *maze);
int downIsFree(Maze *maze);
int leftIsFree(Maze *maze);
#endif //MAZE_H