#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <wchar.h>
#include <conio.h>
#include <math.h>
#include"moves.h"
#include "gameloop.h"
#include "UserInterface.h"


struct input_data move_1;   /**A global structure for each move input**/



/**read row and column input for each move during the game,
then determine the index of the played line in the display array**/
void move(int a[][12],int n,int m)
{
    char r,c;
    int x;
    double diff_t;
    time_t beg_t,end_t;
    colour(14);
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t ==>> GO TO MENU 'M'");
    backcolour();
    printf("\n\n\t\t\t\t\t\t\tRow: ");
    time(&beg_t);
    while (1)            /**count the time while no input is entered .. display time is updated if a minute passed**/
    {
        time(&end_t);
        diff_t=difftime(end_t, beg_t);
        if((int)diff_t-59==0)
        {
            delay(1000);
            system("cls");
            current_t=time(0)-start_t+saved_t-pause_t;
            display(a,n,n);
            printf("\n\n\t\t\t\t\t\t\tRow: ");
            time(&beg_t);
        }
        if(_kbhit())
        {
            break;
        }

    }
    r=getche();
    fflush(stdin);
    r=toupper(r);
    x=r;
    while (x<65||((x-64)>=n&&x!=77&&x!=85&&x!=82)||(x==85&&move_1.empty==n*(n/2-1))||(x==82&&played==(n*(n/2-1)-move_1.empty)) ) /**check the validity of the user input**/
    {
        system("cls");
        display(a,n,n);
        colour(14);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t ==>> GO TO MENU 'M'");
        backcolour();
        colour(12);
        if(x==85||x==82)                                  /**Invalid undo or redo**/
        {
            printf("\n\n\t\t\t\t\t\tNo more moves !");
        }
        else
            printf("\n\n\t\t\t\t\t\tInvalid row !");
        backcolour();
        printf("\n\n\t\t\t\t\t\t\tRow: ");
        time(&beg_t);
        while (1)
        {
            time(&end_t);
            diff_t=difftime(end_t, beg_t);
            if((int)diff_t-59==0)
            {
                delay(1000);
                system("cls");
                current_t=time(0)-start_t+saved_t-pause_t;
                display(a,n,n);
                colour(14);
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t ==>> GO TO MENU 'M'");
                backcolour();
                colour(12);
                if(x==85||x==82)
                {
                    printf("\n\n\t\t\t\t\t\tNo more moves !");
                }
                else
                    printf("\n\n\t\t\t\t\t\tInvalid row !");
                backcolour();
                printf("\n\n\t\t\t\t\t\t\tRow: ");
                time(&beg_t);
            }
            if(_kbhit())
            {
                break;
            }

        }
        r=getche();
        fflush(stdin);
        r=toupper(r);

        x=r;
    }
    if(x==77)
    {
        pre_t=(time(0)-start_t)+saved_t-pause_t;
        game_menu(a,n,n);
    }
    else if(x==85)
    {
        undo(a,n,n);
    }
    else if(x==82)
    {
        redo(a,n,n);
    }

    else
    {
        move_1.row=r-64;
        system("cls");
        display(a,n,n);
        colour(14);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t ==>> GO TO MENU 'M'");
        backcolour();
        printf("\n\n\t\t\t\t\t\t\tRow: %c",r);
        printf("\n\n\t\t\t\t\t\t\tColumn: ");
        time(&beg_t);
        while (1)
        {
            time(&end_t);
            diff_t=difftime(end_t, beg_t);
            if((int)diff_t-59==0)
            {
                delay(1000);
                system("cls");
                current_t=time(0)-start_t+saved_t-pause_t;
                display(a,n,n);
                colour(14);
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t ==>> GO TO MENU 'M'");
                backcolour();
                printf("\n\n\t\t\t\t\t\t\tRow: %c",r);
                printf("\n\n\t\t\t\t\t\t\tColumn: ");
                time(&beg_t);
            }
            if(_kbhit())
            {
                break;
            }

        }
        c=getche();
        fflush(stdin);

        c=toupper(c);
        x=c;

        while (x<65||((x-64)>=n&&x!=77&&x!=85&&x!=82)||(x==85&&move_1.empty==n*(n/2-1))||(x==82&&played==(n*(n/2-1)-move_1.empty))||(move_1.row%2==0&&x%2==0)||(move_1.row%2!=0&&x%2!=0) )
        {
            system("cls");
            display(a,n,n);
            colour(14);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t ==>> GO TO MENU 'M'");
            backcolour();
            colour(12);
            if(x==85||x==82)
            {
                printf("\n\n\t\t\t\t\t\tNo more moves !");
            }
            else if ((move_1.row%2==0&&x%2==0)||(move_1.row%2!=0&&x%2!=0) )
            {
                printf("\n\n\t\t\t\t\t\tInvalid input !");
            }
            else
                printf("\n\n\t\t\t\t\t\tInvalid column !");
            backcolour();
            printf("\n\n\t\t\t\t\t\t\tRow: %c",r);
            printf("\n\n\t\t\t\t\t\t\tColumn: ");
            time(&beg_t);
            while (1)
            {
                time(&end_t);
                diff_t=difftime(end_t, beg_t);
                if((int)diff_t-59==0)
                {
                    delay(1000);
                    system("cls");
                    current_t=end_t-start_t+saved_t-pause_t;
                    display(a,n,n);
                    colour(14);
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t ==>> GO TO MENU 'M'");
                    backcolour();
                    colour(12);
                    if(x==85||x==82)
                    {
                        printf("\n\n\t\t\t\t\t\tNo more moves !");
                    }
                    else if ((move_1.row%2==0&&x%2==0)||(move_1.row%2!=0&&x%2!=0) )
                    {
                        printf("\n\n\t\t\t\t\t\tInvalid input !");
                    }
                    else
                        printf("\n\n\t\t\t\t\t\tInvalid column !");
                    backcolour();
                    printf("\n\n\t\t\t\t\t\t\tRow: %c",r);
                    printf("\n\n\t\t\t\t\t\t\tColumn: ");
                    time(&beg_t);
                }
                if(_kbhit())
                {
                    break;
                }

            }
            c=getche();
            fflush(stdin);
            c=toupper(c);


            x=c;
        }
        if(x==77)
        {
            pre_t=(time(0)-start_t)+saved_t-pause_t;
            game_menu(a,n,n);
        }
        else if(x==85)
        {
            undo(a,n,n);
        }
        else if(x==82)
        {
            redo(a,n,n);
        }
        else
        {
            move_1.column=c-64;
            if(move_1.row>=1&&move_1.row<n&&move_1.column>=1&&move_1.column<n&&a[move_1.row][move_1.column]==0)
            {
                if(move_1.row%2==0&&move_1.column%2!=0)
                {
                    move_1.line=124;     /***vertical line**/
                }
                else if(move_1.row%2!=0&&move_1.column%2==0)
                {
                    move_1.line=95;      /**horizontal line**/
                }

            }
            else                    /**repeated move**/
            {
                move_1.row=0;
                move_1.line=0;
                move_1.column=0;
            }
            a[move_1.row][move_1.column]=move_1.line;
        }
    }

    return;
}


/**function to undo the previous move.
computer's last move(s) and a single player's move are undone in case of one player mode**/
void undo(int a[][12],int n,int m)
{
    int r,c,i,k,l,j=n*(n/2-1)-move_1.empty,r1,c1,r2,c2;
    if(g.players==2)
    {
        i=j-1;
        r=save[i].row;
        c=save[i].column;
        a[r][c]=0;
        move_1.empty++;
        if (save[i].p==2)
        {
            player2.score-=save[i].point;
            player2.moves--;
            move_1.p=2;
        }
        else if (save[i].p==1)
        {
            player1.score-=save[i].point;
            player1.moves--;
            move_1.p=1;
        }
        r1=save[i].boxcolor_r1;
        c1=save[i].boxcolor_c1;
        r2=save[i].boxcolor_r2;
        c2=save[i].boxcolor_c2;
        a[r1][c1]=0;
        a[r2][c2]=0;

    }
    else if(g.players==1)
    {
        i=j-1;
        while(save[i].p==2)
        {
            r=save[i].row;
            c=save[i].column;
            a[r][c]=0;
            move_1.empty++;
            player2.score-=save[i].point;
            player2.moves--;
            r1=save[i].boxcolor_r1;
            c1=save[i].boxcolor_c1;
            r2=save[i].boxcolor_r2;
            c2=save[i].boxcolor_c2;
            a[r1][c1]=0;
            a[r2][c2]=0;

            i--;
        }
        r=save[i].row;
        c=save[i].column;
        a[r][c]=0;
        move_1.empty++;
        player1.score-=save[i].point;
        player1.moves--;
        r1=save[i].boxcolor_r1;
        c1=save[i].boxcolor_c1;
        r2=save[i].boxcolor_r2;
        c2=save[i].boxcolor_c2;
        a[r1][c1]=0;
        a[r2][c2]=0;

        move_1.p=1;
    }

    for(k=0; k<i; k++)
    {
        r=save[k].row;
        c=save[k].column;
        l=save[k].line;
        a[r][c]=l;
        r1=save[k].boxcolor_r1;
        c1=save[k].boxcolor_c1;
        r2=save[k].boxcolor_r2;
        c2=save[k].boxcolor_c2;
        if(r1!=0&&c1!=0)
        {
            a[r1][c1]=178;
        }
        if(r2!=0&&c2!=0)
        {
            a[r2][c2]=178;
        }

    }
    system("cls");
    current_t=(time(0)-start_t)+saved_t-pause_t;
    display(a,n,n);
    game_loop(a,n,n);

    return ;
}


/**function to redo an undone move.
 A single player's move and the subsequent computer's move(s) in case of one player mode**/
void redo(int a[][12],int n,int m)
{
    int r,c,i,l,j=n*(n/2-1)-move_1.empty,r1,r2,c1,c2;
    if(g.players==2)
    {
        r=save[j].row;
        c=save[j].column;
        l=save[j].line;
        a[r][c]=l;
        move_1.empty--;
        if (save[j].p==2)
        {
            player2.score+=save[j].point;
            player2.moves++;
            if (save[j].point==0)
            {
                move_1.p=1;
            }
            else
            {
                move_1.p=2;
            }

        }
        else if (save[j].p==1)
        {
            player1.score+=save[j].point;
            player1.moves++;
            if (save[j].point==0)
            {
                move_1.p=2;
            }
            else
            {
                move_1.p=1;
            }
        }
        r1=save[j].boxcolor_r1;
        c1=save[j].boxcolor_c1;
        r2=save[j].boxcolor_r2;
        c2=save[j].boxcolor_c2;
        if(r1!=0&&c1!=0)
        {
            a[r1][c1]=178;
        }
        if(r2!=0&&c2!=0)
        {
            a[r2][c2]=178;
        }



    }
    else if(g.players==1)
    {
        r=save[j].row;
        c=save[j].column;
        l=save[j].line;
        a[r][c]=l;
        player1.score+=save[j].point;
        player1.moves++;
        move_1.empty--;
        r1=save[j].boxcolor_r1;
        c1=save[j].boxcolor_c1;
        r2=save[j].boxcolor_r2;
        c2=save[j].boxcolor_c2;
        if(r1!=0&&c1!=0)
        {
            a[r1][c1]=178;
        }
        if(r2!=0&&c2!=0)
        {
            a[r2][c2]=178;
        }
        j++;
        while (save[j].p==2&&played!=(n*(n/2-1)-move_1.empty))
        {
            r=save[j].row;
            c=save[j].column;
            l=save[j].line;
            a[r][c]=l;
            move_1.empty--;
            player2.score+=save[j].point;
            player2.moves++;
            r1=save[j].boxcolor_r1;
            c1=save[j].boxcolor_c1;
            r2=save[j].boxcolor_r2;
            c2=save[j].boxcolor_c2;
            if(r1!=0&&c1!=0)
            {
                a[r1][c1]=178;
            }
            if(r2!=0&&c2!=0)
            {
                a[r2][c2]=178;
            }
            j++;
        }
    }

    for(i=0; i<j; i++)
    {
        r=save[i].row;
        c=save[i].column;
        l=save[i].line;
        a[r][c]=l;
        r1=save[i].boxcolor_r1;
        c1=save[i].boxcolor_c1;
        r2=save[i].boxcolor_r2;
        c2=save[i].boxcolor_c2;
        if(r1!=0&&c1!=0)
        {
            a[r1][c1]=178;
        }
        if(r2!=0&&c2!=0)
        {
            a[r2][c2]=178;
        }
    }
    system("cls");
    current_t=(time(0)-start_t)+saved_t-pause_t;
    display(a,n,n);
    game_loop(a,n,n);

    return ;
}

/**function to return number of lines played in one box**/
int onebox (int a[][12],int n,int m,int i,int j)
{
    int h=0,v=0,sum;
    if(a[i][j-1]==124&&a[i][j+1]==124)
    {
        v=2;
    }
    else if(a[i][j-1]==124||a[i][j+1]==124)
    {
        v=1;
    }
    if(a[i-1][j]==95&&a[i+1][j]==95)
    {
        h=2;
    }
    else if (a[i-1][j]==95||a[i+1][j]==95)
    {
        h=1;
    }
    sum=v+h;
    return sum;
}



/**function for computer's move in one player mode, a box is completed with a fourth line if it has three,
empty lines in boxes with couple of lines and lines of completed boxes are excluded, then one other empty place is chosen randomly**/
void comp(int a[][12],int n,int m)
{
    int i,j,k,x=0,flag=0,y,ran_n,lines;
    struct random r[60];
    for (i=2; i<n;)
    {
        for (j=2; j<n;)
        {
            lines=onebox(a,n,n,i,j);
            if(lines==3)
            {
                flag=1;
                break;
            }
            else
            {
                j=j+2;
            }
        }
        if(flag==1)              /**check which place is empty in a box with three lines**/
        {
            if(a[i][j-1]==0)
            {
                move_1.row=i;
                move_1.column=j-1;
            }
            else if (a[i][j+1]==0)
            {
                move_1.row=i;
                move_1.column=j+1;
            }
            else if (a[i-1][j]==0)
            {
                move_1.row=i-1;
                move_1.column=j;
            }
            else if(a[i+1][j]==0)
            {
                move_1.row=i+1;
                move_1.column=j;
            }
            break;
        }
        else i=i+2;
    }
    if(flag==0)
    {
        for(i=2; i<n; i=i+2)
        {
            for(j=2; j<n; j=j+2)
            {
                lines=onebox(a,n,n,i,j);
                if(lines!=2&&lines!=4)
                {
                    if(a[i][j-1]==0)
                    {
                        if(j-1!=1)
                        {
                            k=j-2;
                            y=onebox(a,n,n,i,k);    /**check the number of lines in the adjacent box**/
                            if(y!=2)
                            {
                                r[x].row=i;
                                r[x].column=j-1;
                                x++;
                            }
                        }
                        else
                        {
                            r[x].row=i;
                            r[x].column=j-1;
                            x++;
                        }
                    }
                    if(a[i][j+1]==0)
                    {
                        if((j+1)!=n-1)
                        {
                            k=j+2;
                            y=onebox(a,n,n,i,k);
                            if(y!=2)
                            {
                                r[x].row=i;
                                r[x].column=j+1;
                                x++;
                            }
                        }
                        else
                        {
                            r[x].row=i;
                            r[x].column=j+1;
                            x++;
                        }
                    }
                    if(a[i-1][j]==0)
                    {
                        if(i-1!=1)
                        {
                            k=i-2;
                            y=onebox(a,n,n,k,j);
                            if(y!=2)
                            {
                                r[x].row=i-1;
                                r[x].column=j;
                                x++;
                            }
                        }
                        else
                        {
                            r[x].row=i-1;
                            r[x].column=j;
                            x++;
                        }
                    }
                    if(a[i+1][j]==0)
                    {
                        if((i+1)!=n-1)
                        {
                            k=i+2;
                            y=onebox(a,n,n,k,j);
                            if(y!=2)
                            {
                                r[x].row=i+1;
                                r[x].column=j;
                                x++;
                            }
                        }
                        else
                        {
                            r[x].row=i+1;
                            r[x].column=j;
                            x++;

                        }
                    }
                }
            }
        }
        if(x==1)
        {
            move_1.row=r[0].row;
            move_1.column=r[0].column;
        }
        else if(x>1)
        {
            srand(time(NULL));
            ran_n=rand()%x;
            move_1.row=r[ran_n].row;
            move_1.column=r[ran_n].column;
        }
        else if (x==0)
        {
            random_move(a,n,n);
        }
    }
    if(move_1.row%2==0&&move_1.column%2!=0)
    {
        move_1.line=124;
    }
    else if(move_1.row%2!=0&&move_1.column%2==0)
    {
        move_1.line=95;
    }
    a[move_1.row][move_1.column]=move_1.line;
}

/**if all the remaining boxes have couple of lines, any empty place is chosen randomly**/
void random_move (int a[][12],int n,int m)
{
    int i,j,x=0,ran_n;
    struct random r[60];
    for(i=0; i<60; i++)
    {
        r[i].row=0;
        r[i].column=0;
    }
    for (i=1; i<n; i++)
    {
        for (j=1; j<n; j++)
        {
            if((i%2!=0&&j%2==0)||(i%2==0&&j%2!=0))
            {
                if(a[i][j]==0)
                {
                    r[x].row=i;
                    r[x].column=j;
                    x++;
                }
            }
        }
    }
    srand(time(0));
    ran_n=rand()%x;
    move_1.row=r[ran_n].row;
    move_1.column=r[ran_n].column;
}

