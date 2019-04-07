#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <wchar.h>
#include <conio.h>
#include <math.h>
#include "gameloop.h"
#include "UserInterface.h"
#include "moves.h"
#include "save.h"
#include "ranking.h"

struct input_data save[60];
time_t start_t,current_t=0,saved_t=0,pause_t=0,pre_t;
int played=0;


/**display the game menu and read an input from the user**/
void game_menu(int a[][12],int n,int m)
{
    char y;
    int x;
    system("cls");
    colour(13);
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tMenu\n\n\n");
    colour(11);
    printf("\t\t\t\t\t\t\t1.Resume game\n\n");
    printf("\t\t\t\t\t\t\t2.Save game\n\n");
    printf("\t\t\t\t\t\t\t3.Main menu\n\n");
    y=getche();
    fflush(stdin);
    x=y;
    while(x!=49&&x!=50&&x!=51)                                           /**check the validity of the user input**/
    {
        system("cls");
        colour(13);
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tMenu\n\n\n");
        colour(11);
        printf("\t\t\t\t\t\t\t1.Resume game\n\n");
        printf("\t\t\t\t\t\t\t2.Save game\n\n");
        printf("\t\t\t\t\t\t\t3.Main menu\n\n");
        colour(12);
        printf("\n\n\t\t\t\t\t\tInavalid input !!");
        backcolour();
        y=getche();
        fflush(stdin);
        x=y;
    }
    switch(x)
    {
    case 49:
        system("cls");
        pause_t=(time(0)-start_t)-pre_t;
        pre_t=0;
        display(a,n,n);
        game_loop(a,n,n);
        break;
    case 50:
        save_game1(a,n,n);
        break;
    case 51:
        system("cls");
        menu();
        break;

    }
    return;
}



/**function to check if a player completed a box,then save the gained point(s) and the coloured box(es)**/
void points (int a[][12],int n,int m)
{
    int r,c,up=0,down=0,left=0,right=0;
    r=move_1.row;
    c=move_1.column;
    move_1.point=0;
    move_1.boxcolor_r1=0;
    move_1.boxcolor_c1=0;
    move_1.boxcolor_r2=0;
    move_1.boxcolor_c2=0;
    if(move_1.line==95)
    {
        if(a[r][c]==a[r+2][c]&&a[r+1][c-1]==124&&a[r+1][c+1]==124&&r!=(n-1))
        {
            down=1;
            move_1.boxcolor_r1=r+1;
            move_1.boxcolor_c1=c;
            a[r+1][c]=178;
        }
        if(a[r][c]==a[r-2][c]&&a[r-1][c-1]==124&&a[r-1][c+1]==124&&r!=1)
        {
            up=1;
            move_1.boxcolor_r2=r-1;
            move_1.boxcolor_c2=c;
            a[r-1][c]=178;
        }

        if(up==1&&down==1)
        {
            move_1.point=2;
        }
        else if(up==1||down==1)
        {
            move_1.point=1;
        }
    }
    else if(move_1.line==124)
    {

        if(a[r][c]==a[r][c+2]&&a[r-1][c+1]==95&&a[r+1][c+1]==95&&c!=(n-1))
        {
            right=1;
            move_1.boxcolor_r1=r;
            move_1.boxcolor_c1=c+1;
            a[r][c+1]=178;
        }
        if(a[r][c]==a[r][c-2]&&a[r-1][c-1]==95&&a[r+1][c-1]==95&&c!=1)
        {
            left=1;
            move_1.boxcolor_r2=r;
            move_1.boxcolor_c2=c-1;
            a[r][c-1]=178;
        }
        if(right==1&&left==1)
        {
            move_1.point=2;
        }
        else if(right==1||left==1)
        {
            move_1.point=1;
        }
    }
    return ;
}

/**initialize the game variables at start**/
void game_start (int a[][12],int n,int m)
{
    start_t=time(0);
    saved_t=0;
    pause_t=0;
    current_t=0;
    played=0;
    player1.score=0;
    player2.score=0;
    player1.moves=0;
    player2.moves=0;
    move_1.empty=n*(n/2-1);
    move_1.p=1;
    system("cls");
    grid(a,n,n);
    display(a,n,n);
    game_loop(a,n,n);

    return ;
}


void game_loop (int a[][12],int n,int m)
{
    int i,t=1;
    for(i=played; move_1.empty!=0;)
    {
        if ((g.players==1&&move_1.p==2))
        {
            comp(a,n,n);
        }
        else
        {
            move(a,n,n);

        }
        if(move_1.line==124||move_1.line==95)
        {
            i=n*(n/2-1)-move_1.empty;
            points(a,n,n);
            save[i]=move_1;
            if(move_1.p==1)
            {
                player1.score+=move_1.point;
                player1.moves++;
                if(move_1.point==0)
                {
                    t=2;
                }
                else
                {
                    t=1;
                }
            }
            else if(move_1.p==2)
            {
                player2.score+=move_1.point;
                player2.moves++;
                if(move_1.point==0)
                {
                    t=1;
                }
                else
                {
                    t=2;
                }
            }
            if(t==1)
            {
                move_1.p=1;
            }
            else if(t==2)
            {
                move_1.p=2;
            }
            move_1.empty--;
            system("cls");
            current_t=(time(0)-start_t)+saved_t-pause_t;
            display(a,n,n);
            played++;

        }
        else
        {
            system("cls");
            display(a,n,n);
            colour(12);
            printf("\n\n\t\t\t\t\t\tAlready played !");
            backcolour();
        }


    }
    end_game();

}


void end_game()
{
    char y;
    char temp_name[15];
    int temp_color;
    int a[12][12];
    int i,r,c,l,r1,c1,r2,c2,x;
    colour(14);
    printf("\n\n\t\t\t\t\t\t\t\t**End Game**\n\n");
    backcolour();
    if(player1.score>player2.score)
    {
        switch(g.players)
        {
        case 1:
            colour(player1.color);
            printf("\n\n\t\t\t\t\t\t\t\tYOU WON !");
            backcolour();
            high_scores(1);
            break;
        case 2:
            colour(player1.color);
            printf("\n\n\t\t\t\t\t\t\t\t%s WON",player1.name);
            backcolour();
            high_scores(1);
            break;
        }

    }
    else if(player2.score>player1.score)
    {
        switch(g.players)
        {
        case 1:
            colour(player1.color);
            printf("\n\n\t\t\t\t\t\t\t\tYOU LOST");
            break;
        case 2:
            colour(player2.color);
            printf("\n\n\t\t\t\t\t\t\t\t%s WON",player2.name);
            backcolour();
            high_scores(2);
            break;
        }
    }
    else if(player1.score==player2.score)
    {
        switch(g.players)
        {
        case 1:
            printf("\n\n\t\t\t\t\t\t\t\tYOU HAVE DRAWN");
            break;
        case 2:
            printf("\n\n\t\t\t\t\t\t\t\t%s and %s HAVE DRAWN",player1.name,player2.name);
            break;
        }

    }
    backcolour();
    printf("\n\n\t\t\t\t\t\t\t 1.Play again\n\n\t\t\t\t\t\t\t 2.Main menu\n\n\t\t\t\t\t\t\t 3.Exit");
    y=getche();
    fflush(stdin);
    x=y;
    while (x!=49&&x!=50&&x!=51)
    {
        grid(a,g.size,g.size);
        for (i=0; i<played; i++)
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
        display(a,g.size,g.size);
        colour(14);
        printf("\n\n\t\t\t\t\t\t\t**End Game**\n\n");
        backcolour();
        if(player1.score>player2.score)
        {
            switch(g.players)
            {
            case 1:
                colour(player1.color);
                printf("\n\n\t\t\t\t\t\t\t\tYOU WON !");
                backcolour();
                break;
            case 2:
                colour(player1.color);
                printf("\n\n\t\t\t\t\t\t\t\t%s WON",player1.name);
                backcolour();
                break;
            }

        }
        else if(player2.score>player1.score)
        {
            switch(g.players)
            {
            case 1:
                colour(player1.color);
                printf("\n\n\t\t\t\t\t\t\t\tYOU LOST");
                break;
            case 2:
                colour(player2.color);
                printf("\n\n\t\t\t\t\t\t\t\t%s WON",player2.name);
                backcolour();
                break;
            }
        }
        else if(player1.score==player2.score)
        {
            switch(g.players)
            {
            case 1:
                printf("\n\n\t\t\t\t\t\t\t\tYOU HAVE DRAWN");
                break;
            case 2:
                printf("\n\n\t\t\t\t\t\t\t\t%s and %s HAVE DRAWN",player1.name,player2.name);
                break;
            }

        }
        backcolour();
        printf("\n\n\t\t\t\t\t\t\t 1.Play again\n\n\t\t\t\t\t\t\t 2.Main menu\n\n\t\t\t\t\t\t\t 3.Exit");
        colour(12);
        printf("\n\n\t\t\t\t\t\t\tInvalid input!\n\n");
        backcolour();
        y=getche();
        fflush(stdin);
        x=y;
    }
    switch(x)
    {
    case 49:
        system("cls");
        if(g.players==2)
        {
            if(player2.score>player1.score)
            {
                strcpy(temp_name,player1.name);
                strcpy(player1.name,player2.name);
                strcpy(player2.name,temp_name);
                temp_color=player1.color;
                player1.color=player2.color;
                player2.color=temp_color;
            }
        }
        game_start(a,g.size,g.size);
        break;
    case 50:
        system("cls");
        menu();
        break;
    case 51:
        exit(0);
        break;
    }



}
