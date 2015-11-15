#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/menu.h"
#include "../headers/maze.h"
void init_menu(Maze *m)
{
    char c;
    system(CLEAN);
    printf("Bienvenue dans le jeu du labyrinthe ! \nVeuillez s�lectionner une action a effectuer : \n\n");
    printf("[1] - Creer un labyrinthe\n");
    printf("[2] - Charger un labyrinthe\n");
    printf("[3] - Jouer\n");
    printf("[4] - Quitter\n");
    scanf("%c",&c);
    //printf("%c",c);
    switch(c)
    {
    case '1' :
        system(CLEAN);
        printf("Creation de labyrinthe ...\n");
        menu_create_maze(m);
        break;
    case '2' :
        system(CLEAN);
        printf("Chargement de labyrinthe ...\n");
        //menu_load_maze();
        break;
    case '3' :
        system(CLEAN);
        printf("Jeu ...\n");
        //menu_play();
        break;
    case '4' :
        system(CLEAN);
        printf("Sortie ...\n");
        //menu_leave();
        break;
    default :
        printf("Aucune action valide selectionnee...\n");
        break;
    }
}

void menu_create_maze(Maze *m){
    /*Lors de la cr�ation du labyrinthe, l�utilisateur pourra choisir la taille du labyrinthe (hauteur et
    largeur impaire) ainsi que son nom. Chaque labyrinthe g�n�r� est enregistr� dans un fichier
    au format .cfg et est automatiquement charg�.*/
    int mheight;
    int mwidth;
    printf("Choisissez la hauteur du labyrinthe : \n");
    scanf("%d",&mheight);
    printf("Choisissez la largeur du labyrinthe : \n");
    scanf("%d",&mwidth);
    *m=init_maze(mheight,mwidth);
    fill_maze(m);
    system(CLEAN);
    view_maze(*m);
    free_maze(m);

}
