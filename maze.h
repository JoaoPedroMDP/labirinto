#ifndef MAZE_H
#define MAZE_H

typedef struct Maze Maze;
struct Maze{
    // 0 é X, 1 é Y
    int player_coordinates[2];
    int start_coordinates[2];
    int end_coordinates[2];

    int size;
    int maze[30][30];
};

enum cell_types {Free, Wall, Visited, Alley, CurrentPosition, Start, Exit};

Maze *mallocMaze();
void setCell(Maze *maze, int i, int j, int number);
int getCell(Maze *maze, int i, int j);
void printsMaze(Maze *maze);
void printCell(Maze *maze, int i, int j);

#endif //MAZE_H