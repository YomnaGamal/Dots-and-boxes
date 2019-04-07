#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <wchar.h>
#include <conio.h>
#include <math.h>
#include "UserInterface.h"
#include "ranking.h"
#include "save.h"
#include "gameloop.h"
#include "moves.h"


/**a structure for the game mode concerning number of players and level of the game**/
struct game_mode g;
/**structure for each player including : player's name,score,number of moves and colour**/
struct player player1= {.score=0,.moves=0,.color=13};
struct player player2= {.score=0,.moves=0,.color=11};
int seconds,minutes;

void colour (int n)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, n);
}


void backcolour ()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
}


/**function to split time passed into minutes and seconds  **/
void time_passed ()
{

        minutes=current_t/60;
        seconds=current_t%60;


}

/**display the main menu to the user and get an input**/
void menu()
{


    char y;
    int x;
    colour(14);
    printf("\n\n\n\n\t\t\t\t\t\t\t");
    printf("   ................\n\t\t\t\t\t\t\t<<  ");
    colour(11);
    printf("DOTS AND BOXES");
    colour(14);
    printf("  >>");
    printf("\n\t\t\t\t\t\t\t   ................");
    colour(13);
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t  MAIN MENU");
    colour(11);
    printf("\n\n\n\t\t\t\t\t\t\t1.Start game\n");
    printf("\n\t\t\t\t\t\t\t2.Load game\n");
    printf("\n\t\t\t\t\t\t\t3.Top 10 players\n");
    printf("\n\t\t\t\t\t\t\t4.Exit\n");
    backcolour();
    y=getche();
    fflush(stdin);
    x=y;
    while ((int)x!=49&&(int)x!=50&&(int)x!=51&&(int)x!=52)  /**check the validity of the user input**/
    {
        system("cls");
        colour(14);
        printf("\n\n\n\n\t\t\t\t\t\t\t");
        printf("   ................\n\t\t\t\t\t\t\t<<  ");
        colour(11);
        printf("DOTS AND BOXES");
        colour(14);
        printf("  >>");
        printf("\n\t\t\t\t\t\t\t   ................");
        colour(13);
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t  MAIN MENU\n\n\n");
        colour(11);
        printf("\t\t\t\t\t\t\t1.Start game\n");
        printf("\n\t\t\t\t\t\t\t2.Load game\n");
        printf("\n\t\t\t\t\t\t\t3.Top 10 players\n");
        printf("\n\t\t\t\t\t\t\t4.Exit\n");
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
        start();
        break;
    case 50:
        load_game();
        break;
    case 51:
        system("cls");
        leaderboard();
        break;
    case 52:
        system("cls");
        exit(0);
        break;

    }

    return;
}


/**get input from the user for the game level and mode,get the player(s) name,then start the game**/
void start ()
{
    char y;
    int x;

    colour(14);
    printf("\n\n\n\n\t\t\t\t\t\t\t");
    printf("   ................\n\t\t\t\t\t\t\t<<  ");
    colour(11);
    printf("DOTS AND BOXES");
    colour(14);
    printf("  >>");
    printf("\n\t\t\t\t\t\t\t   ................");
    colour(13);
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t START GAME\n\n\n");
    colour(11);
    printf("\t\t\t\t\t\t%c Choose level\n\n",254);
    printf("\t\t\t\t\t\t\t 1.Beginner\n");
    printf("\n\t\t\t\t\t\t\t 2.Expert\n");
    colour(14);
    printf("\n\n\n\n\t\t\t\t<<== BACK TO MENU 'M'");
    backcolour();
    y=getche();
    fflush(stdin);
    x=y;
    while (x!=49&&x!=50&&x!=77&&x!=109)     /**check the validity of the user input**/
    {
        system("cls");
        colour(14);
        printf("\n\n\n\n\t\t\t\t\t\t\t");
        printf("   ................\n\t\t\t\t\t\t\t<<  ");
        colour(11);
        printf("DOTS AND BOXES");
        colour(14);
        printf("  >>");
        printf("\n\t\t\t\t\t\t\t   ................");
        colour(13);
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t START GAME\n\n\n");
        colour(11);
        printf("\t\t\t\t\t\t%c Choose level\n\n",254);
        printf("\t\t\t\t\t\t\t 1.Beginner\n");
        printf("\n\t\t\t\t\t\t\t 2.Expert\n");
        colour(14);
        printf("\n\n\n\n\t\t\t\t<<== BACK TO MENU 'M'");
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
        g.size=6;
        break;
    case 50:
        g.size=12;
        break;
    case 77:
        system("cls");
        menu();
        break;
    case 109:
        system("cls");
        menu();
        break;
    }
    system("cls");
    colour(14);
    printf("\n\n\n\n\t\t\t\t\t\t\t");
    printf("   ................\n\t\t\t\t\t\t\t<<  ");
    colour(11);
    printf("DOTS AND BOXES");
    colour(14);
    printf("  >>");
    printf("\n\t\t\t\t\t\t\t   ................");
    colour(13);
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t START GAME\n\n\n");
    colour(11);
    printf("\t\t\t\t\t\t%c Choose mode\n\n",254);

    printf("\t\t\t\t\t\t\t 1.One player\n");
    printf("\n\t\t\t\t\t\t\t 2.Two players\n");
    colour(14);
    printf("\n\n\n\n\t\t\t\t<<== BACK TO MENU 'M'");
    backcolour();
    y=getche();
    fflush(stdin);
    x=y;
    while(x!=49&&x!=50&&x!=77&&x!=109)      /**check the validity of the user input**/
    {
        system("cls");
        colour(14);
        printf("\n\n\n\n\t\t\t\t\t\t\t");
        printf("   ................\n\t\t\t\t\t\t\t<<  ");
        colour(11);
        printf("DOTS AND BOXES");
        colour(14);
        printf("  >>");
        printf("\n\t\t\t\t\t\t\t   ................");
        colour(13);
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t START GAME\n\n\n");
        colour(11);
        printf("\t\t\t\t\t\t%c Choose mode\n\n",254);

        printf("\t\t\t\t\t\t\t 1.One player\n");
        printf("\n\t\t\t\t\t\t\t 2.Two players\n");
        colour(14);
        printf("\n\n\n\n\t\t\t\t<<== BACK TO MENU 'M'");
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
        g.players=1;
        system("cls");
        colour(13);
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPlayer's name:\n\n\t\t\t\t\t\t\t\t");
        colour(11);
        fgets(player1.name,10,stdin);      /**only 10 characters from input are considered as the player's name**/
        backcolour();
        int i;
        for (i=0; i<strlen(player1.name); i++)
        {
            if (player1.name[i]=='\n')
            {
                player1.name[i]='\0';
            }
        }
        fflush(stdin);
        strcpy(player2.name,"Computer");
        break;
    case 50:
        g.players=2;
        system("cls");

        colour(13);
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPlayer one:\n\n\t\t\t\t\t\t\t\t");
        colour(11);
        fgets(player1.name,10,stdin);
        backcolour();
        for (i=0; i<strlen(player1.name); i++)
        {
            if (player1.name[i]=='\n')
            {
                player1.name[i]='\0';
            }
        }
        fflush(stdin);
        colour(13);
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tPlayer two:\n\n\t\t\t\t\t\t\t\t");
        colour(11);
        fgets(player2.name,10,stdin);
        backcolour();
        for (i=0; i<strlen(player2.name); i++)
        {
            if (player2.name[i]=='\n')
            {
                player2.name[i]='\0';
            }
        }
        fflush(stdin);
        break;
    case 77:
        system("cls");
        menu();
        break;
    case 109:
        system("cls");
        menu();
        break;
    }
    int a[g.size][g.size];
    game_start(a,g.size,g.size);

    return ;
}


/**initializing the game grid for first display**/
void grid (int a[][12],int n,int m)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==0&&j!=0)
            {
                a[i][j]=j+64;
            }
            else if(j==0&&i!=0)
            {
                a[i][j]=i+64;
            }
            else if(i%2!=0&&j%2!=0)
            {
                a[i][j]=46;
            }
            else a[i][j]=0;
        }
    }
    return;
}


/** display screen during game loop with current game information concerning players' information, next turn,
 moves left,time passed from start game and the grid updated with the last move and **/
void display (int a[][12],int n,int m)
{
    int i,j,k;
    time_passed();
    colour(14);
    printf("\n\t\t\t\t\tUndo 'U'\t\t\t\t\tRedo 'R'\n\n\n");
    colour(player1.color);
    printf("\t\t\t\t\t%s",player1.name);
    colour(player2.color);
    printf("\t\t\t\t\t\t%s",player2.name);
    backcolour();
    printf("\n\t\t\t\t\t\t\t\t%02d:%02d\n",minutes,seconds);
    colour(player1.color);
    printf("\t\t\t\t\t%d",player1.score);
    colour(player2.color);
    printf("  \t\t\t\t\t\t%d \n\t\t\t\t\t\t\t\t ",player2.score);
    if(move_1.p==1)
    {
        colour(player1.color);
        printf("%s",player1.name);
    }
    else if(move_1.p==2)
    {
        colour(player2.color);
        printf("%s",player2.name);
    }
    colour(player1.color);
    printf("\n\t\t\t\t\t%d",player1.moves);

    colour(player2.color);
    printf("\t\t\t\t\t\t%d\n",player2.moves);
    backcolour();
    printf("\t\t\t\t\t\t\t\t%d\n\n\n\n",move_1.empty);

    for(i=0; i<n; i++)
    {
        printf("\t\t\t\t\t\t\t");
        for(j=0; j<n; j++)
        {
            if(a[i][j]==95)
            {
                for(k=0; k<(n*(n/2-1)-move_1.empty);)
                {
                    if(save[k].row==i&&save[k].column==j)
                    {
                        if (save[k].p==1)
                        {
                            colour(player1.color);
                            printf("__");
                        }

                        else if(save[k].p==2)
                        {
                            colour(player2.color);
                            printf("__");
                        }

                        break;
                    }
                    else k++;
                }

            }
            else if (a[i][j]==124)
            {
                for(k=0; k<(n*(n/2-1)-move_1.empty);)
                {
                    if(save[k].row==i&&save[k].column==j)
                    {
                        if (save[k].p==1)
                        {
                            colour(player1.color);
                            printf("|%c",32);
                        }

                        else if(save[k].p==2)
                        {
                            colour(player2.color);
                            printf("|%c",32);
                        }
                        break;
                    }
                    else k++;
                }
            }
            else if (a[i][j]==178)
            {
                for(k=0; k<(n*(n/2-1)-move_1.empty);)
                {
                    if((save[k].boxcolor_r1==i&&save[k].boxcolor_c1==j)||(save[k].boxcolor_r2==i&&save[k].boxcolor_c2==j))
                    {
                        if (save[k].p==1)
                        {
                            colour(player1.color);
                            printf("%c%c",178,178);
                        }

                        else if(save[k].p==2)
                        {
                            colour(player2.color);
                            printf("%c%c",178,178);
                        }
                        break;
                    }
                    else k++;
                }
            }
            else
            {
                backcolour();
                printf("%c%c",a[i][j],32);
            }
        }
        printf("\n");
    }
}
