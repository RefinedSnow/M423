#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "maze.h"
void init_menu(Maze *m);
void menu_create_maze(Maze *m);
void menu_load_maze(Maze *m);
void menu_play(Maze *m);
void menu_leave();

#endif // MENU_H_INCLUDED
