#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include "save.h"
#include "UserInterface.h"
#include "gameloop.h"
#include "moves.h"

int saved;  /**number of saved game**/



void readsaved()
{
    FILE *save;
    save=fopen("saved.txt","r");
    fprintf(save,"%d",saved);
    fclose(save);
}

/**save a game in first file**/
void save_game1 (int a[][12],int n,int m)
{
    int i,size;
    FILE *game1;
    game1=fopen("game1.txt","r");
    if(game1!=NULL)
    {
        fseek (game1, 0, SEEK_END);
        size=ftell(game1);
        if (size==0||saved%3==0)
        {
            fclose(game1);
            game1=fopen("game1.txt","w");
            fprintf(game1,"%d,%d,%ld\n",g.size,g.players,current_t);
            fprintf(game1,"%s,%d,%d\n",player1.name,player1.score,player1.moves);
            fprintf(game1,"%s,%d,%d\n",player2.name,player2.score,player2.moves);
            for(i=0; i<played; i++)
            {

                fprintf(game1,"%d,%d,%d,%d,%d,%d,%d,%d,%d\n",save[i].row,save[i].column,save[i].line,save[i].point,save[i].p,save[i].boxcolor_r1,save[i].boxcolor_c1,save[i].boxcolor_r2,save[i].boxcolor_c2);
            }
            fclose(game1);
            saved++;
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame saved");
            delay(2000);
            system("cls");
            display(a,n,n);
            game_loop(a,n,n);
        }
        else
        {
            fclose(game1);
            save_game2(a,n,n);
        }
    }
    else
    {
        system("cls");
        printf("\n\t\t\t\tError saving game !");
        delay(2000);
        system("cls");
        display(a,n,n);
        game_loop(a,n,n);
    }

    return;
}


/**save a game in second file**/
void save_game2(int a[][12],int n,int m)
{
    FILE *game2;
    int i,size;
    game2=fopen("game2.txt","r");
    if(game2!=NULL)
    {
        fseek (game2, 0, SEEK_END);
        size=ftell(game2);
        if (size==0||saved%3==1)
        {
            fclose(game2);
            game2=fopen("game2.txt","w");

            fprintf(game2,"%d,%d,%ld\n",g.size,g.players,current_t);
            fprintf(game2,"%s,%d,%d\n",player1.name,player1.score,player1.moves);
            fprintf(game2,"%s,%d,%d\n",player2.name,player2.score,player2.moves);
            for(i=0; i<played; i++)
            {

                fprintf(game2,"%d,%d,%d,%d,%d,%d,%d,%d,%d\n",save[i].row,save[i].column,save[i].line,save[i].point,save[i].p,save[i].boxcolor_r1,save[i].boxcolor_c1,save[i].boxcolor_r2,save[i].boxcolor_c2);
            }
            fclose(game2);
            saved++;
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame saved");
            delay(2000);
            system("cls");
            display(a,n,n);
            game_loop(a,n,n);
        }
        else
        {
            fclose(game2);
            save_game3(a,n,n);

        }
    }
    else
    {
        system("cls");
        printf("\n\t\t\t\tError saving game !");
        delay(2000);
        system("cls");
        display(a,n,n);
        game_loop(a,n,n);
    }
    return;
}


/**save a game in third file**/
void save_game3(int a[][12],int n,int m)
{
    FILE *game3;
    int i,size;
    game3=fopen("game3.txt","r");
    if(game3!=NULL)
    {
        fseek (game3, 0, SEEK_END);

        size=ftell(game3);
        if (size==0||saved%3==2)
        {
            fclose(game3);
            game3=fopen("game3.txt","w");
            fprintf(game3,"%d,%d,%ld\n",g.size,g.players,current_t);
            fprintf(game3,"%s,%d,%d\n",player1.name,player1.score,player1.moves);
            fprintf(game3,"%s,%d,%d\n",player2.name,player2.score,player2.moves);

            for(i=0; i<played; i++)
            {

                fprintf(game3,"%d,%d,%d,%d,%d,%d,%d,%d,%d\n",save[i].row,save[i].column,save[i].line,save[i].point,save[i].p,save[i].boxcolor_r1,save[i].boxcolor_c1,save[i].boxcolor_r2,save[i].boxcolor_c2);
            }
            fclose(game3);
            saved++;
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame saved");
            delay(2000);
            system("cls");
            display(a,n,n);
            game_loop(a,n,n);

        }
        else
        {
            fclose(game3);

        }


    }
    else
    {
        system("cls");
        printf("\n\t\t\t\tError saving game !");
        delay(2000);
        system("cls");
        display(a,n,n);
        game_loop(a,n,n);
    }

    return;
}


void writesaved()
{
    FILE *save;
    save=fopen("saved.txt","w");
    fscanf(save,"%d",&saved);
    fclose(save);
}

/**read an input from the user to load a specific game,
thn read  the saved game from its saving file**/
void load_game()
{
    char x;
    int y,i=0;
    FILE *game1,*game2,*game3;

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
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\tCHOOSE GAME\n\n\n");
    colour(11);
    printf("\t\t\t\t\t\t\t1.Game 1\n");
    printf("\n\t\t\t\t\t\t\t2.Game 2\n");
    printf("\n\t\t\t\t\t\t\t3.Game 3\n");
    colour(14);
    printf("\n\n\n\n\t\t\t\t<<== BACK TO MENU 'M'");
    backcolour();
    x=getche();
    fflush(stdin);
    y=x;
    while(y!=49&&y!=50&&y!=51&&y!=77&&y!=109)                      /**check the validity of the user input**/
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
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\tCHOOSE GAME\n\n\n");
        colour(11);
        printf("\t\t\t\t\t\t\t1.Game 1\n");
        printf("\n\t\t\t\t\t\t\t2.Game 2\n");
        printf("\n\t\t\t\t\t\t\t3.Game 3\n");
        colour(14);
        printf("\n\n\n\n\t\t\t\t<<== BACK TO MENU 'M'");
        colour(12);
        printf("\n\n\t\t\t\t\t\tInavalid input !!");
        backcolour();
        x=getche();
        fflush(stdin);
        y=x;
    }
    switch(y)
    {
    case 49:
        game1=fopen("game1.txt","r");
        if (game1!=NULL)
        {

            fseek (game1, 0, SEEK_END);

            if (ftell(game1)!=0)
            {
                fclose(game1);
                game1=fopen("game1.txt","r");
                fscanf(game1,"%d,%d,%ld\n",&g.size,&g.players,&saved_t);
                fscanf(game1,"%[^,],%d,%d\n",player1.name,&player1.score,&player1.moves);
                fscanf(game1,"%[^,],%d,%d\n",player2.name,&player2.score,&player2.moves);
                i=0;
                while(!feof(game1))
                {
                    fscanf(game1,"%d,%d,%d,%d,%d,%d,%d,%d,%d\n",&save[i].row,&save[i].column,&save[i].line,&save[i].point,&save[i].p,&save[i].boxcolor_r1,&save[i].boxcolor_c1,&save[i].boxcolor_r2,&save[i].boxcolor_c2);
                    i++;
                }
                fclose(game1);
                start_loadedgame();

            }
            else
            {
                fclose(game1);
                system("cls");
                colour(11);
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tNo saved game");
                backcolour();
                delay(2000);
                system("cls");
                load_game();
            }
        }
        else
        {
            system("cls");
            colour(11);
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tError loading game !");
            backcolour();
            delay(2000);
            system("cls");
            load_game();
        }

        break;

    case 50:
        game2=fopen("game2.txt","r");
        if (game2!=NULL)
        {
            fseek (game2, 0, SEEK_END);

            if (ftell(game2)!=0)
            {
                fclose(game2);
                game2=fopen("game2.txt","r");
                fscanf(game2,"%d,%d,%ld\n",&g.size,&g.players,&saved_t);
                fscanf(game2,"%[^,],%d,%d\n",player1.name,&player1.score,&player1.moves);
                fscanf(game2,"%[^,],%d,%d\n",player2.name,&player2.score,&player2.moves);
                i=0;
                while(!feof(game2))
                {
                    fscanf(game2,"%d,%d,%d,%d,%d,%d,%d,%d,%d\n",&save[i].row,&save[i].column,&save[i].line,&save[i].point,&save[i].p,&save[i].boxcolor_r1,&save[i].boxcolor_c1,&save[i].boxcolor_r2,&save[i].boxcolor_c2);
                    i++;
                }
                fclose(game2);
                start_loadedgame();

            }
            else
            {
                fclose(game2);
                system("cls");
                colour(11);
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tNo saved game");
                backcolour();
                delay(2000);
                system("cls");
                load_game();
            }
        }
        else
        {
            system("cls");
            colour(11);
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tError loading game !");
            backcolour();
            delay(2000);
            system("cls");
            load_game();
        }

        break;

    case 51:
        game3=fopen("game3.txt","r");
        if (game3!=NULL)
        {
            fseek (game3, 0, SEEK_END);

            if (ftell(game3)!=0)
            {
                fclose(game3);
                game3=fopen("game3.txt","r");
                fscanf(game3,"%d,%d,%ld\n",&g.size,&g.players,&saved_t);
                fscanf(game3,"%[^,],%d,%d\n",player1.name,&player1.score,&player1.moves);
                fscanf(game3,"%[^,],%d,%d\n",player2.name,&player2.score,&player2.moves);
                i=0;
                while(!feof(game3))
                {
                    fscanf(game3,"%d,%d,%d,%d,%d,%d,%d,%d,%d\n",&save[i].row,&save[i].column,&save[i].line,&save[i].point,&save[i].p,&save[i].boxcolor_r1,&save[i].boxcolor_c1,&save[i].boxcolor_r2,&save[i].boxcolor_c2);
                    i++;
                }
                fclose(game3);
                start_loadedgame();

            }
            else
            {
                fclose(game3);
                system("cls");
                colour(11);
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tNo saved game");
                backcolour();
                delay(2000);
                system("cls");
                load_game();
            }
        }
        else
        {
            system("cls");
            colour(11);
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tError loading game !");
            backcolour();
            delay(2000);
            system("cls");
            load_game();
        }

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
    return ;
}


/**function to initialize the variables of a game with information of the loaded game, display the game and start it**/
void start_loadedgame ()
{
    int a[12][12];
    int n=g.size,i,r,l,c,r1,c1,r2,c2;
    played=player1.moves+player2.moves;
    if(save[played-1].p==1)
    {
        if (save[played-1].point==0)
        {
            move_1.p=2;
        }
        else
        {
            move_1.p=1;
        }
    }
    else if(save[played-1].p==2)
    {
        if (save[played-1].point==0)
        {
            move_1.p=1;
        }
        else
        {
            move_1.p=2;
        }
    }
    move_1.empty=n*(n/2-1)-played;
    grid(a,n,n);
    for(i=0; i<played; i++)
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
    start_t=time(0);
    system("cls");
    display(a,n,n);
    game_loop(a,n,n);
}
