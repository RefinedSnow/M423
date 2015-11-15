#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../headers/menu.h"
#include "../headers/maze.h"
void init_menu(Maze *m)
{
    char c;
    //on vide le buffer avant tout
    fflush(stdin);
    if(m->name == NULL) printf("Bienvenue dans le jeu du labyrinthe ! \nVeuillez sélectionner une action a effectuer : \n\n");
    else printf("\nLabyrinthe charge : %s\n\n", m->name);
    printf("[1] - Creer un labyrinthe\n");
    printf("[2] - Charger un labyrinthe\n");
    printf("[3] - Jouer\n");
    printf("[x] - Quitter\n");
    scanf("%c",&c);
    printf(" [%c] ",c);
        switch(c)
        {
        case '1' :
            //system(CLEAN);
            printf("Creation de labyrinthe ...\n");
            menu_create_maze(m);
            break;
        case '2' :
            //system(CLEAN);
            printf("Chargement de labyrinthe ...\n");
            free_maze(m);
            menu_load_maze(m);
            break;
        case '3' :
            //system(CLEAN);
            printf("Jeu ...\n");
            if(m->name == NULL) printf("Aucun labyrinthe charge\n");
            else menu_play(m);
            break;
        case 'x' :
            free_maze(m);
            printf("Sortie ...\n");
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
    printf("Labyrinthe %s cree et charge que voulez vous faire ? \n\n",name);
    init_menu(m);

}

void menu_load_maze(Maze *m){
    char name[MAX_NAME_LENGTH];
    printf("Charger le labyrinthe : (max %d caracteres) \n",MAX_NAME_LENGTH);
    fflush(stdin);
    scanf("%s",name);
    load_maze(name,m);
    //view_maze(*m);
    //printf("%s",m->name);
    init_menu(m);
    //todo : play
    //free_maze(m);
}
void menu_play(Maze *m){
    char c;
    bool end = false;
    printf("laby : %s",m->name);
    /*do{
        scanf("%c",&c);
        switch(c){
        case 'z' ://up
            break;
        case 'q'://left
            break;
        case 's'://down
            break;
        case 'd'://right
            break;
        default: printf("saisie invalide\n");
            break;
        }
    }while(!end);*/
}
