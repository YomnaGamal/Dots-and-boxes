#ifndef USERINTERFACE_H_INCLUDED
#define USERINTERFACE_H_INCLUDED

struct game_mode
{
    int size;
    int players;

};

struct player
{
    char name[15];
    int score;
    int moves;
    int color;
};


extern struct game_mode g;
extern struct player player1;
extern struct player player2;


void colour (int n);
void backcolour ();
void time_passed ();
void menu();
void start();
void grid (int a[][12],int n,int m);
void display (int a[][12],int n,int m);
void delay();

#endif // USERINTERFACE_H_INCLUDED
