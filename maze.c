#include "maze.h"
#include <math.h>

Maze *mallocMaze(int maze_size){
    Maze *newMaze = malloc(sizeof(Maze));
    newMaze->maze_size = maze_size;
    newMaze->maze = malloc(pow(maze_size, 2) * sizeof(int));
    newMaze->player_col = 0;
    newMaze->player_row = 0;

    return newMaze;
}
enum cell_types {Free, Wall, Visited, Alley, CurrentPosition};

Maze *createMaze()
{
    Maze *newMaze = mallocMaze();
}