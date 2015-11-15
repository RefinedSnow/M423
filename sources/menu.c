#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../headers/menu.h"
#include "../headers/maze.h"
void init_menu(Maze *m)
{
    char c;
    system(CLEAN);
    printf("Bienvenue dans le jeu du labyrinthe ! \nVeuillez sélectionner une action a effectuer : \n\n");
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
        menu_load_maze(m);
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
    /*Lors de la création du labyrinthe, l’utilisateur pourra choisir la taille du labyrinthe (hauteur et
    largeur impaire) ainsi que son nom. Chaque labyrinthe généré est enregistré dans un fichier
    au format .cfg et est automatiquement chargé.*/
    int mheight, mwidth,i,j;
    char name[MAX_NAME_LENGTH];
    int cpt = 0;

    printf("Choisissez la hauteur du labyrinthe : \n");
    scanf("%d",&mheight);
    printf("Choisissez la largeur du labyrinthe : \n");
    scanf("%d",&mwidth);
    printf("Donnez un nom a votre labyrinthe : (max %d caracteres) \n",MAX_NAME_LENGTH);
    scanf("%s",name);

    *m=init_maze(mheight,mwidth);
    fill_maze(m);
    create_maze(name, m);
    system(CLEAN);
    view_maze(*m);
    free_maze(m);

}

void menu_load_maze(Maze *m){
    char name[MAX_NAME_LENGTH];
    printf("Charger le labyrinthe : (max %d caracteres) \n",MAX_NAME_LENGTH);
    scanf("%s",name);
    load_maze(name,m);
    view_maze(*m);
    free_maze(m);
}
