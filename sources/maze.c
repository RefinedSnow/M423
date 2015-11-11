#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../header/maze.h"

void init_menu()
{
    char c;
    system(CLEAN);
    printf("Bienvenue dans le jeu du labyrinthe ! \nVeuillez sélectionner une action à effectuer : \n\n");
    printf("1 - Créer un labyrinthe\n");
    printf("2 - Charger un labyrinthe\n");
    printf("3 - Jouer\n");
    printf("4 - Quitter\n");
    scanf("%c",&c);
    //printf("%c",c);
    switch(c)
    {
    case '1' :
        printf("Création de labyrinthe ...\n");
        break;
    case '2' :
        printf("Chargement de labyrinthe ...\n");
        break;
    case '3' :
        printf("Jeu ...\n");
        break;
    case '4' :
        printf("Sortie ...\n");;
        break;
    default :
        printf("Aucune action valide sélectionnée...\n");
        break;
    }
}
Maze init_maze(int height, int width)
{
    Maze m;
    Player p;
    int lin;
    m.mat_v = calloc(height,sizeof(int*));
    m.mat_h = calloc(height,sizeof(int*));
    m.mat_m = calloc(height,sizeof(int*));
    for (lin=0; lin < height; lin++)
    {
        m.mat_v[lin] = calloc(width,sizeof(int));
        m.mat_h[lin] = calloc(width,sizeof(int));
        m.mat_m[lin] = calloc(width,sizeof(int));
    }
    if(m.mat_v ==NULL  || m.mat_h == NULL || m.mat_m == NULL)
    {
        exit(1);
    }
    m.height = height;
    m.width = width;
    p.posx=0;
    p.posy=0;
    m.player = p;

    return m;
}
void create_maze(char *name, Maze *m)
{
    m->name = name;
}

void fill_maze(Maze *m)
{
    int cell_val,old_cell,lin,col,cpt;
    cpt =0;
    for(lin=0;lin<m->height;lin++){
        for(col=0;col<m->width;col++){
            m->mat_h[lin][col] = 1;
            m->mat_v[lin][col] = 1;
            m->mat_m[lin][col] = cpt;
            cpt++;
        }
    }
    do{
        //Choses which wall to open
        int cell_x_rng = rand()%(m->width);
        int cell_y_rng = rand()%(m->height);
        int wall_type_rng = rand()%2;
        cell_val = m->mat_m[cell_y_rng][cell_x_rng];
        if(wall_type_rng == WALL_VERTICAL && cell_x_rng < m->width-1){
            //the current value of the path we're about to open
            old_cell = m->mat_m[cell_y_rng][cell_x_rng+1];
            //already opened, go next
            if(m->mat_v[cell_y_rng][cell_x_rng+1] == 0) continue;
             //if the value are the same the path is already made can't open the wall
            if(old_cell==cell_val) continue;
            //opens the wall
            m->mat_v[cell_y_rng][cell_x_rng+1] = 0;
            m->mat_m[cell_y_rng][cell_x_rng+1] = cell_val;
            //we need to make the path
            for(lin =0;lin<m->height;lin++){
                for(col=0;col<m->width;col++){
                    if(m->mat_m[lin][col] == old_cell)
                    {
                        m->mat_m[lin][col] = cell_val;
                    }
                }
            }

        }
        else if(wall_type_rng == WALL_HORIZONTAL && cell_y_rng < m->height-1){
            //the current value of the path we're about to open
            old_cell = m->mat_m[cell_y_rng+1][cell_x_rng];
            //already opened, go next
            if(m->mat_h[cell_y_rng+1][cell_x_rng] == 0) continue;
             //if the value are the same the path is already made can't open the wall
            if(old_cell==cell_val) continue;
            //opens the wall
            m->mat_h[cell_y_rng+1][cell_x_rng] = 0;
            m->mat_m[cell_y_rng+1][cell_x_rng] = cell_val;
            //we need to make the path
            for(lin =0;lin<m->height;lin++){
                for(col=0;col<m->width;col++){
                    if(m->mat_m[lin][col] == old_cell)
                    {
                        m->mat_m[lin][col] = cell_val;
                    }
                }
            }
        }

    }while(!check_array(m->mat_m,m->width,m->height));
}

void view_maze(Maze m)
{
    view_tab(m.mat_v,m.height,m.width);
    printf("\n");
    view_tab(m.mat_h,m.height,m.width);
    printf("\n");
    view_tab(m.mat_m,m.height,m.width);

}

void view_tab(int **tab, int height, int width){
    int lin,col;
    for (lin=0; lin < height; lin++)
    {
        for (col=0; col < width; col++)
        {
            printf("%4d",tab[lin][col]);
        }
        printf("\n");
    }
}
void free_maze(Maze *m)
{
    free(m->mat_v);
    free(m->mat_h);
    free(m->mat_m);
}

bool check_array(int ** tab, int width, int height)
{
    int lin, col;
    //printf("%d",tab[0][0]);
    for (lin=0; lin < height; lin++)
    {
        for (col=0; col < width; col++)
        {
            //printf("%d",tab[lin][col]);
            if(tab[lin][col] != tab[0][0])
            {
                return false;
            }

        }
    }
    return true;

}
