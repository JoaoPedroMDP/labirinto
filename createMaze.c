#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "maze.h"
#include "createMaze.h"

#define SIZE 30

int random_int_between(int x, int y)
{
    return (rand() % (x - y)) + y;
}

Maze *mallocMaze(int size){
    int i, j;
    Maze *newMaze = malloc(sizeof(Maze));
    newMaze->size = size;

    for ( i = 0; i < newMaze->size; i++)
        for(j = 0; j < newMaze->size; j++)
            setCell(newMaze, i, j, 0);

    newMaze->start_coordinates[0] = rand() % newMaze->size;
    newMaze->start_coordinates[1] = rand() % newMaze->size;
    newMaze->end_coordinates[0] = rand() % newMaze->size;
    newMaze->end_coordinates[1] = rand() % newMaze->size;

    newMaze->player_coordinates[0] = newMaze->start_coordinates[0];
    newMaze->player_coordinates[1] = newMaze->start_coordinates[1];

    return newMaze;
}

void configureMaze(Maze *maze);
Maze *createMaze()
{
    Maze *newMaze = mallocMaze(SIZE);
    configureMaze(newMaze);
    return newMaze;
}

int firstLine(Maze *maze, int line);
int lastLine(Maze *maze, int line);
void distributeWallsOnLine(Maze *maze, int line, int wallAmount);
void configureMaze(Maze *maze)
{
    int i = 0, wallAmount = (int) (pow(maze->size, 2) / 3);
    srand(time(NULL));

    for( i=0 ; i < maze->size ; i++)
    {
        if(firstLine(maze, i) || lastLine(maze, i))
        {
            int k;
            for(k = 0; k < maze->size; k++)
                setCell(maze, i, k, Wall);
        }else{
            distributeWallsOnLine(maze, i, wallAmount);
        }
    }

    maze->maze[maze->start_coordinates[0]][maze->start_coordinates[1]] = Start;
    maze->maze[maze->end_coordinates[0]][maze->end_coordinates[1]] = Exit;
    maze->player_coordinates[0] = maze->start_coordinates[0];
    maze->player_coordinates[1] = maze->start_coordinates[1];

    maze->maze[maze->player_coordinates[0]][maze->player_coordinates[1]] = CurrentPosition;
}

int firstLine(Maze *maze, int line)
{
    return line == 0;
}

int lastLine(Maze *maze, int line)
{
    return line == maze->size - 1;
}

void distributeWallsOnLine(Maze *maze, int line, int wallAmount)
{
    int remaining_walls_in_line = wallAmount / maze->size, j;

    maze->maze[line][0] = Wall;
    maze->maze[line][maze->size - 1] = Wall;

    while(remaining_walls_in_line > 0)
    {
        j = random_int_between(0, maze->size);
        while(getCell(maze, line, j) == Wall)
        {
            j++;
            if(j > maze->size)
            {
                j = random_int_between(0, remaining_walls_in_line);
            }
        }
        setCell(maze, line, j, Wall);
        remaining_walls_in_line--;
    }

}