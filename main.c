#include <stdio.h>
#include "maze.h"
#include "createMaze.h"
#include "mouse.h"

#define EXIT 0
#define SHOW_MAZE 1
#define START 2

void printsMenu()
{
    printf("---------MENU---------\n");
    printf("    %d) Sair\n", EXIT);
    printf("    %d) Ver labirinto\n",  SHOW_MAZE);
    printf("    %d) Iniciar\n",  START);

}

int reachedExit(Maze *maze)
{
    return  (maze->player_coordinates[0] == maze->end_coordinates[0]) &&
            (maze->player_coordinates[1] == maze->end_coordinates[1]);
}

int main(){
    int option = 0;
    Maze *maze = createMaze(mallocStack());

    printsMenu();
    scanf("%d", &option);
    do{
        switch(option)
        {
            case EXIT:
                printf("Falows\n");
                break;

            case SHOW_MAZE:
                printsMaze(maze);
                break;

            case START:
                printf("Vamo torcer pra nao dar segfault \U0001F64C\n\n");
                start(maze);
                if(reachedExit(maze))
                {
                    printf("Agora o rato esta gordinho de queijo :D\n");
                }
        }

        printsMenu();
        scanf("%d", &option);
    }while(option != EXIT);

    return 0;
}