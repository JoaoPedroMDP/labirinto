#include <stdio.h>
#include "maze.h"

void setCell(Maze *maze, int x, int y, int number)
{
    maze->maze[x][y] = number;
}

int getCell(Maze *maze, int x, int y)
{
    return maze->maze[x][y];
}

void setAlley(Maze *maze)
{
    setCell(
        maze,
        maze->player_coordinates[0],
        maze->player_coordinates[1],
        Alley
    );
}

void printsMaze(Maze *maze)
{
    int x = 0, y = 0;
    for(x = 0 ; x < maze->size ; x++ )
    {
        for(y = 0 ; y < maze->size ; y++ )
        {
            printCell(maze, x, y);
        }
        printf("\n");
    }
}

void printCell(Maze *maze, int x, int y)
{
    int content = getCell(maze, x, y);

    switch(content){
        case Wall:
            printf("\U0001F7E7");
            break;
        case Visited:
            printf("\U0001F4A9");
            break;
        case CurrentPosition:
            printf("\U0001F42D");
            break;
        case Exit:
            printf("\U0001F9C0");
            break;
        case Free:
            printf("  ");
            break;
        case Alley:
            printf("\U000025FE");
            break;
    }
//    printf("%d", content);
}

int upIsFree(Maze *maze)
{
    if( maze->player_coordinates[0] != 0 ){
        int upContent = getCell(
                maze,
                maze->player_coordinates[0] - 1,
                maze->player_coordinates[1]
            );

        return upContent == Free || upContent == Exit;
    }

    return 0;
}

int rightIsFree(Maze *maze)
{
    if( maze->player_coordinates[1] != (SIZE - 1) ){
        int rightContent = getCell(
                maze,
                maze->player_coordinates[0],
                maze->player_coordinates[1] + 1
        );

        return rightContent == Free || rightContent == Exit;
    }

    return 0;
}

int downIsFree(Maze *maze)
{
    if( maze->player_coordinates[0] != (SIZE - 1)){
        int downContent = getCell(
                maze,
                maze->player_coordinates[0] + 1,
                maze->player_coordinates[1]
        );

        return downContent == Free || downContent == Exit;
    }

    return 0;
}

int leftIsFree(Maze *maze)
{
    if( maze->player_coordinates[1] != 0 ){
        int leftContent = getCell(
                maze,
                maze->player_coordinates[0],
                maze->player_coordinates[1] - 1
        );

        return leftContent == Free || leftContent == Exit;
    }

    return 0;
}

