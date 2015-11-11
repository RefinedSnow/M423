#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "header/maze.h"

int main ()
{
    srand(time(NULL));

    //init_menu();
    Maze m;
    m = init_maze(9,9);
    //create_maze("coucou",&m);
    fill_maze(&m);
    view_maze(m);
    free_maze(&m);

    return 0;
}
