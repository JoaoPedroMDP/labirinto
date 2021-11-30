#include <stdio.h>
#include "maze.h"
#include "createMaze.h"

#define EXIT 0
#define SHOW_MAZE 1

void prints_menu(){
    printf("---------MENU---------\n");
    printf("    %d) Sair\n", EXIT);
    printf("    %d) Ver labirinto\n",  SHOW_MAZE);

}

void main(){
    int option = 0;
    Maze *maze = createMaze();

    prints_menu();
    printsMaze(maze);
//    scanf("%d", &option);
//
//    while(opcao != 0)
}