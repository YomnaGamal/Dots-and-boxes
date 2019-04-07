#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED


struct top
{
    char name[15];
    int score;
};

void sorting (struct top a[],int n);
int name_compare(char str1[], char str2[]);
int top10_1read (struct top top_10[],int n);
void top10_1write (struct top top_10 [],int n);
int top10_2read (struct top top_10[],int n);
void top10_2write (struct top top_10 [],int n);
int update_highscores(struct top top10[],int n,char name[],int m,int score);
void high_scores(int x);
void leaderboard();


#endif // RANKING_H_INCLUDED
