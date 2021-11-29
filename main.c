#include <stdio.h>
#include "maze.h"

#define MAZE_SIZE 30
#define EXIT 0
#define SHOW_MAZE 1

void prints_menu(){
    printf("---------MENU---------\n");
    printf("    %d) Sair", EXIT);
    printf("    %d) Ver labirinto",  SHOW_MAZE);

}

void main(){
    int option = 0, maze_size = MAZE_SIZE;

    create_maze(maze_size);

    prints_menu();
    scanf("%d", &option);

    while(opcao != 0)
}