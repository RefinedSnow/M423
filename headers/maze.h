#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED

/*#################################################
  #               CONSTANTES                      #
  #################################################
*/
#ifdef _WIN32
#define CLEAN "cls"
#else
#define CLEAN "clear"
#endif

#define MAX_NAME_LENGTH 20
#define WALL_VERTICAL 0
#define WALL_HORIZONTAL 1
/*#################################################
  #               STRUCTURES                      #
  #################################################
*/
/*typedef struct{
	int cup;
	int cdown;
	int cright;
	int cleft;

}Cell;
*/
typedef struct
{
    int posx;
    int posy;
} Player;

typedef struct
{
    char *name;
    int height;
    int width;
    int **mat_v;
    int **mat_h;
    int **mat_m;
    Player player;
} Maze;

/*#################################################
  #               FONCTIONS                       #
  #################################################
*/
void init_menu();
Maze init_maze(int height, int width);
void create_maze(char *name, Maze *m);
void view_maze(Maze m);
void free_maze(Maze *m);
bool check_array(int ** tab, int width, int height);
void view_tab(int **tab, int heigt, int width);
void load_maze(char *name,Maze *m);

#endif // MAZE_H_INCLUDED
