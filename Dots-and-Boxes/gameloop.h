#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED


struct input_data
{
    int row;
    int column;
    int line;
    int point;
    int empty;
    int p;
    int boxcolor_r1;
    int boxcolor_c1;
    int boxcolor_r2;
    int boxcolor_c2;

};



extern struct input_data save[60];
extern time_t start_t,current_t,saved_t,pause_t,pre_t;
extern int played;

void game_menu(int a[][12],int n,int m);
void points (int a[][12],int n,int m);
void game_start (int a[][12],int n,int m);
void game_loop (int a[][12],int n,int m);
void end_game();


#endif // GAMELOOP_H_INCLUDED
