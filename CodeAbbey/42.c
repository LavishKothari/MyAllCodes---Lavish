#include<stdio.h>
int findScore(int score,char c)
{
	int currentScore;
	switch(c)
	{
		case '2':currentScore=2;break;
		case '3':currentScore=3;break;
		case '4':currentScore=4;break;
		case '5':currentScore=5;break;
		case '6':currentScore=6;break;
		case '7':currentScore=7;break;
		case '8':currentScore=8;break;
		case '9':currentScore=9;break;
		case 'T':currentScore=10;break;
		case 'J':currentScore=10;break;
		case 'Q':currentScore=10;break;
		case 'K':currentScore=10;break;
	}
	if(c=='A')
	{
		if(score+11<=21)
			score+=11;
		else score++;
	}
	else
		score+=currentScore;
	return score;
}
int main()
{
	int t,i,score;
	char str[10000];
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %[^\n]s",str);
		score=0;
		for(i=0;str[i];i++)
		{
			if(str[i]!=' ')
			{
				score=findScore(score,str[i]);
				if(score>21)
				{
					printf("Bust ");
					break;
				}
			}
		}
		if(!str[i])
			printf("%d ",score);
	}
	return 0;
}
