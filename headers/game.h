#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

void view_maze_state(Maze m);
void move_right(Maze *m);
void move_left(Maze *m);
void move_up(Maze *m);
void move_down(Maze *m);
bool win(Maze m);

#endif // GAME_H_INCLUDED
