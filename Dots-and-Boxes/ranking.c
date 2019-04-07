#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <wchar.h>
#include <conio.h>
#include <math.h>
#include "ranking.h"
#include "UserInterface.h"
#include "gameloop.h"



/**function to sort an array of structure according to one of its integers**/
void sorting (struct top a[],int n)
{
    int i,j,temp_score;
    char temp_name [15];
    for (i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            if(a[j].score>a[i].score)
            {
                temp_score=a[i].score;
                a[i].score=a[j].score;
                a[j].score=temp_score;
                strcpy(temp_name,a[i].name);
                strcpy(a[i].name,a[j].name);
                strcpy(a[j].name,temp_name);
            }
        }
    }
    return;
}



/**function to read the file of top 10 experts**/
int top10_1read (struct top top_10[],int n)
{
    FILE *top10;
    int i=0;
    top10=fopen("top10_1.txt","r");
    if (top10!=NULL)
    {
        while (fscanf(top10, "%s\n%d\n", top_10[i].name,&top_10[i].score)!=EOF)
        {
            i++;
        }
        fclose(top10);
    }

    else i=-1;

    return i;
}


/**function to update the file of top 10 experts**/
void top10_1write (struct top top_10 [],int n)
{
    FILE *top10;
    int i;
    top10=fopen("top10_1.txt","w");
    if(top10!=NULL)
    {
        for(i=0; i<n; i++)
        {
            fprintf(top10,"%s\n%d\n",top_10[i].name,top_10[i].score);
        }
        fclose(top10);
    }
    else
    {
        system("cls");
        printf("\n\t\t\t Error saving high score !");
        delay(2000);
        menu();
    }
    return;
}


/**function to read the file of top 10 beginners**/
int top10_2read (struct top top_10[],int n)
{
    FILE *top10;
    int i=0;
    top10=fopen("top10_2.txt","r");
    if (top10!=NULL)
    {
        while (fscanf(top10, "%s\n%d\n", top_10[i].name,&top_10[i].score)!=EOF)
        {
            i++;
        }
        fclose(top10);
    }

    else i=-1;

    return i;
}

/**function to update the file of top 10 experts**/
void top10_2write (struct top top_10 [],int n)
{
    FILE *top10;
    int i;
    top10=fopen("top10_2.txt","w");
    if(top10!=NULL)
    {
        for(i=0; i<n; i++)
        {
            fprintf(top10,"%s\n%d\n",top_10[i].name,top_10[i].score);
        }
        fclose(top10);
    }
    else
    {
        system("cls");
        printf("\n\t\t\t Error saving high score !");
        delay(2000);
        menu();
    }
    return;
}


/**function to compare the player's name with all the names of top players,
 update the score if higher or add the player if not found,then sort the players according to score**/
int update_highscores(struct top top10[],int n,char name[],int m,int score)
{
    int i,j=0,flag=0,t,size;
    for(i=0; i<n-1;)
    {
        while(top10[i].name[j]!='\0')
        {
            top10[i].name[j]=tolower(top10[i].name[j]);
            j++;
        }
        t=strcmp(name,top10[i].name);
        if(t==0)
        {
            if(score>top10[i].score)
            {
                top10[i].score=score;
            }
            flag=1;
            break;
        }
        else
        {
            i++;
            flag=0;
        }
    }
    if (flag==0)
    {
        if (n<=10)
        {
            top10[n-1].score=score;
            strcpy(top10[n-1].name,name);
            size=n;
        }
        else
        {
            if(score>top10[9].score)
            {
                top10[9].score=score;
                strcpy(top10[9].name,name);
            }
            size=10;
        }

    }
    else if (flag==1)
    {
        size= (n-1);
    }
    sorting(top10,size);
    for(i=0; i<size; i++)
    {
        if(top10[i].name[0]>='a'&&top10[i].name[0]<='z')
        {
            top10[i].name[0]=toupper(top10[i].name[0]);
        }
        for(j=0; j<m; j++)
        {
            if(top10[i].name[j]==' '&&top10[i].name[j+1]!=' ')
            {
                top10[i].name[j+1]=toupper(top10[i].name[j+1]);
            }
        }
    }


    return size;

}


/**save the name and the score of the winner, then read the file of top players and update it**/
void high_scores(int x)
{
    struct top top10[10];
    int i=0,score,t,size,len,z,temp_color;
    char y;
    char name[15],temp_name[15];
    int a[12][12];
    if(x==1)
    {
        strcpy(name,player1.name);
        score=player1.score;
    }
    else if(x==2)
    {
        strcpy(name,player2.name);
        score=player2.score;
    }
    while(name[i]!='\0')
    {
        name[i]=tolower(name[i]);
        i++;
    }
    switch (g.size)
    {
    case 12:
        t=top10_1read(top10,10);
        break;
    case 6:
        t=top10_2read(top10,10);
        break;
    }
    if (t==0)
    {
        strcpy(top10[0].name,name);
        top10[0].score=score;
        size=1;
    }
    else if (t==-1)
    {
        system("cls");
        printf("\n\t\t\t Error saving high score !");
        delay(2000);
        system("cls");
        backcolour();
        printf("\n\n\t\t\t\t\t\t\t 1.Play again\n\n\t\t\t\t\t\t\t 2.Main menu\n\n\t\t\t\t\t\t\t 3.Exit");
        y=getche();
        fflush(stdin);
        z=y;
        while (z!=49&&z!=50&&z!=51)
        {
            system("cls");
            backcolour();
            printf("\n\n\t\t\t\t\t\t\t 1.Play again\n\n\t\t\t\t\t\t\t 2.Main menu\n\n\t\t\t\t\t\t\t 3.Exit");
            colour(12);
            printf("\n\n\t\t\t\t\t\t\tInvalid input!\n\n");
            backcolour();
            y=getche();
            fflush(stdin);
            z=y;
        }
        switch(z)
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
        }

    }
    else
    {
        len=strlen(name);
        size=update_highscores(top10,t+1,name,len+1,score);
    }
    switch (g.size)
    {
    case 12:
        top10_1write(top10,size);
        break;
    case 6:
        top10_2write(top10,size);
        break;
    }



    return;
}






/**read an input from the user and display the top 10 experts or beginners**/
void leaderboard()
{
    struct top top10[10];
    int a[10][10];
    char x;
    int i=0,size,y,j;
    colour(14);
    printf("\n\n\n\n\t\t\t\t\t\t\t");
    printf("   ................\n\t\t\t\t\t\t\t<<  ");
    colour(11);
    printf("DOTS AND BOXES");
    colour(14);
    printf("  >>");
    printf("\n\t\t\t\t\t\t\t   ................");
    colour(13);
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTOP 10 PLAYERS\n\n\n");
    colour(11);
    printf("\t\t\t\t\t\t\t 1.Beginners\n\n\t\t\t\t\t\t\t 2.Experts");
    colour(14);
    printf("\n\n\n\n\t\t\t\t<<== BACK TO MENU 'M'");
    backcolour();
    x=getche();
    fflush(stdin);
    y=x;
    while(y!=49&&y!=50&&y!=77&&y!=109)                 /**check the validity of the user input**/
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
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTOP 10 PLAYERS\n\n\n");
        colour(11);
        printf("\t\t\t\t\t\t\t 1.Beginners\n\n\t\t\t\t\t\t\t 2.Experts");
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
        size=top10_2read(top10,10);
        break;
    case 50:
        size=top10_1read(top10,10);
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
    if (size==-1)
    {
        system("cls");
        colour(11);
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tError loading file !");
        backcolour();
        delay(2000);
        system("cls");
        leaderboard();
    }
    else if (size==0)
    {
        system("cls");
        colour(11);
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tNo players");
        backcolour();
        delay(2000);
        system("cls");
        leaderboard();
    }
    else
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
        printf("\n\n\n\n\t\t\t\t\t\t\tTOP 10 PLAYERS\n\n");
        colour(11);
        printf("\n\n\t\t\t\t\tRANK\t\t    NAME\t\t    SCORE\n\n\n");
        backcolour();
        for(i=0; i<size; i++)
        {
            for(j=0; j<10; j++)
            {
                if(j<strlen(top10[i].name))
                {
                    a[i][j]=top10[i].name[j];
                }
                else

                    a[i][j]=0;
            }
        }
        for(i=0; i<size; i++)
        {
            printf("\t\t\t\t\t %d\t\t    ",i+1);
            for(j=0; j<10; j++)
            {

                printf("%c",a[i][j]);

            }
            printf("\t\t\t%d\n\n",top10[i].score);

        }
        colour(14);
        printf("\n\n\n\n\t\t<<== BACK TO MENU 'M'");
        backcolour();
        x=getche();
        fflush(stdin);
        x=toupper(x);
        while (x!='M')
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
            printf("\n\n\n\n\t\t\t\t\t\t\tTOP 10 PLAYERS\n\n");
            colour(11);
            printf("\n\n\t\t\t\t\tRANK\t\t    NAME\t\t    SCORE\n\n\n");
            backcolour();
            for(i=0; i<size; i++)
            {
                printf("\t\t\t\t\t %d\t\t    ",i+1);
                for(j=0; j<10; j++)
                {

                    printf("%c",a[i][j]);

                }
                printf("\t\t\t%d\n\n",top10[i].score);

            }
            colour(14);
            printf("\n\n\n\n\t\t<<== BACK TO MENU 'M'");
            colour(12);
            printf("\n\n\n\t\t\t\t\tInavalid input !!");
            backcolour();
            x=getche();
            fflush(stdin);
            x=toupper(x);
        }
        if(x=='M')
        {
            system("cls");
            menu();
        }
    }
    return;
}




