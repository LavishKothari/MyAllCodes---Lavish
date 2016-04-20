#include<stdio.h>
#include<stdlib.h>

struct ladder
{
	int start,end;
};
struct snake
{
	int start,end;
};
int isSnakeThere(int x,struct snake*s,int m)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(s[i].start==x)
			return 1;
	}
	return 0;
}
int findAnswer(struct ladder*l,int n,struct snake*s,int m)
{
	int x=1,answer=0,maxhike,ladderno,i;
	while(x!=100)
	{
		maxhike=ladderno=0;
		for(i=0;i<n;i++)
		{
			if(l[i].start>=x+1 && l[i].start<=x+6 && l[i].end>x+6)
			{
				if(maxhike<l[i].end)
				{
					maxhike=l[i].end;
					ladderno=i;
				}
			}
		}
		if(maxhike!=0)
		{
			x=l[ladderno].end;
			answer++;
		}
		else
		{
			for(i=6;i>=1;i--)
			{
				if(!isSnakeThere(x+i,s,m) && x+i<=100)
				{
					answer++;
					x=x+i;
					break;
				}
			}
			if(i==0)
				return -1;
		}
	}
	return answer;
}
int main()
{
	int t,n,m,i;
	struct ladder*l;
	struct snake*s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		l=(struct ladder*)malloc(sizeof(struct ladder)*n);
		for(i=0;i<n;i++)
			scanf("%d%d",&l[i].start,&l[i].end);
		scanf("%d",&m);
		s=(struct snake*)malloc(sizeof(struct snake)*m);
		for(i=0;i<m;i++)
			scanf("%d%d",&s[i].start,&s[i].end);
		printf("%d\n",findAnswer(l,n,s,m));
		free(l);
		free(s);			
	}
	return 0;
}

