#ifndef MOVES_H_INCLUDED
#define MOVES_H_INCLUDED


struct random
{
    int row;
    int column;
};

extern struct input_data move_1;

void move( int a[][12],int n,int m);
void undo(int a[][12],int n,int m);
void redo(int a[][12],int n,int m);
int onebox (int a[][12],int n,int m,int i,int j);
void comp(int a[][12],int n,int m);
void random_move (int a[][12],int n,int m);

#endif // MOVES_H_INCLUDED
