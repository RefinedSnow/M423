#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../headers/maze.h"
void view_maze_state(Maze m)
{
    int lin,col;
    for (lin=0; lin < m.height; lin++)
    {
        //Horizontal walls
        for (col=0; col < m.width; col++)
        {
            printf("#");
            if(m.mat_h[lin][col]) printf(" # ");
            else printf("   ");
        }
        printf("#\n");
        //Vertical walls
        for (col=0; col < m.width; col++)
        {
            if((lin==0 && col==0)) printf(" ");
            else if(m.mat_v[lin][col]) printf("#");
            else printf(" ");
            if(m.player.posx == col && m.player.posy == lin) printf(" 0 ");
            else printf("   ");
        }
        if(lin == m.height - 1) printf(" \n");
        else printf("#\n");
    }
    for (col=0; col < m.width*2+1; col++) printf("# ");
    printf("\n x = %d y = %d\n",m.player.posx,m.player.posy);
}
void move_right(Maze *m){
    int lin,col,x,y;
    x = m->player.posx;
    y = m->player.posy;
    //m->player.posx += 1;
    //if(x < m->width-1){
        //if(m->mat_v[y][x+1] != 1)
        m->player.posx += 1;
    //}
}
void move_left(Maze *m){
    int lin,col,x,y;
    x = m->player.posx;
    y = m->player.posy;
    /*if(x > 0){
        if(m->mat_v[y][x-1] != 1) m->player.posx -= 1;
    }*/m->player.posx -= 1;
}
void move_down(Maze *m){
    int lin,col,x,y;
    x = m->player.posx;
    y = m->player.posy;
    //if(y < m->height){
        //if(m->mat_h[y+1][x] != 1) m->player.posy += 1;
   // }
   m->player.posy += 1;
}
void move_up(Maze *m){
    int lin,col,x,y;
    x = m->player.posx;
    y = m->player.posy;
   // if(y > 1){
        //if(m->mat_h[y-1][x] != 1) m->player.posy -= 1;
    //}
   // if(y == 1){
        m->player.posy -= 1;
   // }
}
bool win(Maze m){
    if(m.player.posx == m.width-1 && m.player.posy == m.height-1) return true;
    return false;
}

