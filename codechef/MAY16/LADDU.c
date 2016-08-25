#include<stdio.h>

int main()
{
	char str[100];
	int t,n,isIndian,rank,answer,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %s",&n,str);
		if(str[0]=='I')
			isIndian=1;
		else isIndian=0;
		answer=0;
		for(i=0;i<n;i++)
		{
			scanf(" %s",str);
			if(str[8]=='W')
			{
				answer+=300;
				scanf("%d",&rank);
				if(rank<20)
					answer+=(20-rank);
			}
			else if(str[8]=='R')
			{
				answer+=300;
			}
			else if(str[8]=='D')
			{
				scanf("%d",&rank);
				answer+=rank;
			}
			else if(str[8]=='H')
			{
				answer+=50;
			}
		}
		//printf("%d\n",answer);
		if(isIndian)
			printf("%d\n",answer/200);
		else printf("%d\n",answer/400);
	}
	return 0;
}
