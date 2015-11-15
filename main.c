#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/maze.h"

int main ()
{
    srand(time(NULL));
    //On cree un labyrinthe vide pour commencer
    Maze m;
    m.name = '\0';
    m.height = NULL;
    m.width = NULL;
    //on charge le menu avec le labyrinthe
    init_menu(&m);
    //printf("h : %d, w: %d lol",height,width);
    //m = init_maze(9,9);
    //create_maze("coucou",&m);
    /*fill_maze(&m);
    view_maze(m);
    free_maze(&m);*/
    free_maze(&m);
    return 0;
}
