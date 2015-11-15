#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/maze.h"

int main ()
{
    srand(time(NULL));
    Maze m;
    int height,width;
    init_menu(&m);
    //printf("h : %d, w: %d lol",height,width);
    //m = init_maze(9,9);
    //create_maze("coucou",&m);
    /*fill_maze(&m);
    view_maze(m);
    free_maze(&m);*/

    return 0;
}
