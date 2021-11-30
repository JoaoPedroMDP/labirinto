#include <stdio.h>
#include "maze.h"

void setCell(Maze *maze, int i, int j, int number)
{
    maze->maze[i][j] = number;
}

int getCell(Maze *maze, int i, int j)
{
    return maze->maze[i][j];
}

void printsMaze(Maze *maze)
{
    int i = 0, j = 0;
    for( i = 0 ; i < maze->size ; i++ )
    {
        for( j = 0 ; j < maze->size ; j++ )
        {
            printCell(maze, i, j);
        }
        printf("\n");
    }
}

void printCell(Maze *maze, int i, int j)
{
    int content = getCell(maze, i, j);
    if(content == Wall)
    {
        printf("\U0001F7E7");
    }else if(content == Visited)
    {
        printf(".");
    }else if( content == CurrentPosition)
    {
        printf("\U0001F42D");
    }else if(content == Exit)
    {
        printf("\U0001F9C0");
    }else{
        printf("  ");
    }
}