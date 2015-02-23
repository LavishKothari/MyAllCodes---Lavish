#include<stdio.h>

int findWinner(char a,char b)
{
	if(a==b)
		return 0;
	else if(a=='R' && b=='S')
		return 1;
	else if(a=='S' && b=='P')
		return 1;
	else if(a=='P' && b=='R')
		return 1;
	else return -1;
}
int main()
{
	int t,count,i;
	char str[10000];
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf(" %[^\n]s",str);
		for(i=0;str[i];i+=2)
		{
			if(i!=0) i++;
			count+=findWinner(str[i],str[i+1]);
		}
		if(count>0)
			printf("1 ");
		else printf("2 ");
	}

	return 0;
}
