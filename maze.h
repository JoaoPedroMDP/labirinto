#ifndef MAZE_H
#define MAZE_H

typedef struct Maze Maze
struct Maze{
    int player_row;
    int player_col;
    int maze_size;
    int *maze;
};

Maze *mallocMaze();
#endif //MAZE_H
