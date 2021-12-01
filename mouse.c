#include <unistd.h>
#include "mouse.h"
#include <stdio.h>
#include <stdlib.h>

int iteration(Maze *maze);
void start(Maze *maze)
{
    int end_program = 0;
    while(end_program == 0)
    {
        system("clear");
        end_program = iteration(maze);
        usleep(10000);
    }
}

void moveUp(Maze *maze);
void moveRight(Maze *maze);
void moveDown(Maze *maze);
void moveLeft(Maze *maze);
void backtrack(Maze *maze);
void setVisited(Maze *maze);
int haveToEnd(Maze *maze);
void saveCurrentPositionOnStack(Maze *maze);
int iteration(Maze *maze)
{
    if(upIsFree(maze))
    {
        setVisited(maze);
        saveCurrentPositionOnStack(maze);
        moveUp(maze);
    }else if(rightIsFree(maze))
    {
        setVisited(maze);
        saveCurrentPositionOnStack(maze);
        moveRight(maze);
    }else if(downIsFree(maze))
    {
        setVisited(maze);
        saveCurrentPositionOnStack(maze);
        moveDown(maze);
    }else if(leftIsFree(maze))
    {
        setVisited(maze);
        saveCurrentPositionOnStack(maze);
        moveLeft(maze);
    }else{
        setAlley(maze);
        backtrack(maze);
    }

    printsMaze(maze);
    return haveToEnd(maze);
}

void saveCurrentPositionOnStack(Maze *maze)
{
    stackNewNode(
            maze->movements,
            createNode(
                    maze->player_coordinates[0],
                    maze->player_coordinates[1]
            )
    );
}

void setVisited(Maze *maze)
{
    setCell(
            maze,
            maze->player_coordinates[0],
            maze->player_coordinates[1],
            Visited
    );
}

void moveTo(Maze *maze, int x, int y)
{
    maze->player_coordinates[0] = x;
    maze->player_coordinates[1] = y;

    setCell(
            maze,
            maze->player_coordinates[0],
            maze->player_coordinates[1],
            CurrentPosition
    );

}

void moveUp(Maze *maze)
{
    moveTo(
        maze,
        maze->player_coordinates[0] - 1,
        maze->player_coordinates[1]
    );
}

void moveRight(Maze *maze)
{
    moveTo(
        maze,
        maze->player_coordinates[0],
        maze->player_coordinates[1] + 1
    );
}

void moveDown(Maze *maze)
{
    moveTo(
        maze,
        maze->player_coordinates[0] + 1,
        maze->player_coordinates[1]
    );
}

void moveLeft(Maze *maze)
{
    moveTo(
        maze,
        maze->player_coordinates[0],
        maze->player_coordinates[1] - 1
    );
}

void backtrack(Maze *maze)
{
    if(maze->movements->top != NULL)
    {
        Node *lastMovement = maze->movements->top;
        int x = extractXFromInteger(lastMovement->position);
        int y = extractYFromInteger(lastMovement->position);

        moveTo(maze, x, y);
        removeNode(maze->movements);
    }
}

int haveToEnd(Maze *maze)
{
    if((maze->player_coordinates[0] == maze->end_coordinates[0] &&
        maze->player_coordinates[1] == maze->end_coordinates[1]) ||
        maze->movements->size == 0)
    {
        return 1;
    }

    return 0;
}
